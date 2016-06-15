#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""

    Objetivo : Abrir sessão com banco de dados e com o arquivo `device` da placa arduino, para enviar informações
    de cada sensor ao servidor.

    Copyright (C) <2016>  <Jefferson Lisboa>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

"""

import mysql.connector
import re
import serial
from optparse import OptionParser
from time import sleep


class KoalaInterpretador:
    def __init__(self, configuration):

        self.modular = 0

        self.conexao = None
        self.cursor = None
        self.nomeTabela = None
        self.dev = None
        self.serial_arduino = None

        self.dicionario = {}
        self.config = configuration

        self.expression = re.compile('^[a-zA-Z0-9:_ (),.-]+$')

        print("Tentando conectar ao banco de dados com as seguintes configurações ... ")

        print(self.config)

        self.connection()

    def open_session_serial_arduino(self, argument):
        # type: (string) -> object

        while True:

            try:

                print("Tentando abrir device do arduino ... ")

                self.dev = open(argument, 'r')

                print("device aberto com sucesso.!")

                while True:

                    try:

                        print("Tentando abrir sessão com o serial do arduino ... ")
                        self.serial_arduino = serial.Serial(self.dev.name, 9600)

                        print(self.serial_arduino)
                        print("Sessão foi aberta com sucesso.!")

                        break

                    except serial.serialutil.SerialException as msgerror:

                        print(msgerror)
                        print("Tentarei novamente abrir a sessão com arduino daqui a 5 segundos ... ")

                        sleep(5)
                break

            except IOError as msgerror:

                print(msgerror)
                print("Tentarei novamente abrir device do arduino daqui a 5 segundos ... ")

                sleep(5)

    def serial_data(self):

        while True:
            yield self.serial_arduino.readline()

    def update_time(self):

        tabelaupdatequery = "INSERT INTO TimeUpdate (void) values(%d)" % (self.modular % 2)

        self.cursor.execute(tabelaupdatequery)
        self.conexao.commit()

        self.modular += 1

        sleep(0.250)

    def send_query(self):

        print("Iniciando envio de informações de cada sensor para o banco de dados")

        for string in self.serial_data():

            if string:
                """

                    verifica se o existe algum caractere na string

                """

                string = string.replace('\n', '').replace('\r', '').replace('\x00', '')
                """

                        Filtra  alguns caracteres especiais da porta Serial

                """

                if self.ismatch(string) is not None and string.__contains__(':') and string.__contains__(','):
                    """

                        verifica se a string contém apenas numerais,letras,virgulas,ponto e underline
                        verifica se a string contém ':'
                        verifica se a string contém ','

                        Caso satisfaça todas essas  condições, o programa continuará

                    """

                    self.nomeTabela = string.split(':', 1)[0]

                    tupla = tuple(string.split(':', 1)[1].split(','))

                    if self.nomeTabela not in self.dicionario:
                        print(
                            "Tabela %s foi adicionado ao sistema de pesquisa para diminuir o de fluxo "
                            "de informações de envio" %
                            self.nomeTabela
                        )

                        self.dicionario[self.nomeTabela] = None
                        """

                            dicionario é uma estrutura de dados que mantém o nome de cada tabela salva para evitar
                            envio de informações duplicadas. Isso diminui o custo de processamento e  gasto de
                            dados de internet para o banco de dados.

                            (excelente medida para internet movéis roteadas)

                        """

                    if self.dicionario[self.nomeTabela] != tupla[1]:
                        """

                        verifica se na chave do dicionário especifico, já foi enviado a mesma informação para o sensor.
                        isso evita duplicação de informação e sobrecarga do servidor de banco de dados.

                        """

                        query = 'INSERT INTO ' + self.nomeTabela + ' (nome,informacao) VALUES (%s,%s)'
                        """

                            cria uma query com informações do sensor lido pela porta serial do arduino e atualiza
                            a tabela de atualização global dos sensores.

                        """

                        print(
                            "MySQL =: tabela: %s\tNome Sensor: %s\tInformação: %s" % (
                                self.nomeTabela, tupla[0], tupla[1]))

                        self.cursor.execute(query, tupla)

                        # Make sure data is committed to the database
                        self.conexao.commit()

                        self.dicionario[self.nomeTabela] = str(tupla[1])

                        self.update_time()
                        """

                            Enviar informação para o banco de dados que houve atualização de algum sensor

                        """

    def disconnect(self):

        print("Desconectando do servidor ... ")

        self.cursor.close()
        self.conexao.close()
        self.serial_arduino.close()

    def connection(self):

        while True:

            try:

                self.conexao = mysql.connector.connect(**self.config)
                self.cursor = self.conexao.cursor()

                print("Conexão com o servidor foi realizada com sucesso.!")
                break

            except mysql.connector.errors.InterfaceError as msgerror:

                print(msgerror)
                print("Tentarei conectar ao servidor em 5 segundos ... ")

                sleep(5)
                print("Tentando reconectar")

    def ismatch(self, string):

        return self.expression.match(string)


if __name__ == "__main__":

    print("Iniciando koala python Serial read ...")

    config = {
        'user': 'arduino',
        'password': 'zn9aeuSusI',
        'host': 'localhost',
        'database': 'php',
        'raise_on_warnings': True,

    }

    p = OptionParser("usage: tail.py file")
    (options, args) = p.parse_args()

    koala = KoalaInterpretador(config)

    koala.open_session_serial_arduino(args[0])

    while True:

        try:
            koala.send_query()

        except mysql.connector.errors.InterfaceError as e:
            print(e)
            koala.connection()

        except mysql.connector.errors.ProgrammingError as e:
            print(e)

            sleep(2)

            print(
                "Tabela %s foi removida do sistema para diminuir o custo de processamento de lixos"
                % koala.nomeTabela
            )

            del koala.dicionario[koala.nomeTabela]

        except serial.serialutil.SerialException as e:
            print(e)
            koala.open_session_serial_arduino(args[0])

        except KeyboardInterrupt:
            koala.disconnect()
            break

    print("Fim do processo")
