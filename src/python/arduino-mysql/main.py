#!/usr/bin/env python
# -*- coding: utf-8 -*-

import mysql.connector
import serial
from optparse import OptionParser


def serial_data(ser):

    try:
        while True:
            yield ser.readline()
    except KeyboardInterrupt:
        raise

if __name__ == "__main__":
    config = {

        'user': 'arduino',
        'password': 'zn9aeuSusI',
        'host': 'localhost',
        'database': 'php',
        'raise_on_warnings': True,

    }

    cnx = mysql.connector.connect(**config)

    print("Conexão com o banco de dados realizado com sucesso.!")

    cursor = cnx.cursor()

    p = OptionParser("usage: tail.py file")
    (options, args) = p.parse_args()

    if len(args) < 1:
        p.error("must specify o arquivo serial para leitura")
    else:

        dev = open(args[0], 'r')

        serial_ = serial.Serial(dev.name, 9600)

        print(serial_)

        try:

            for line in serial_data(serial_):

                string = str(serial_.readline())

                if string and len(string) > 0 and string.__contains__(':') and string.__contains__(','):

                    string = string.replace('\n', '').replace('\r', '')

                    nometabela = string.split(':', 1)[0]

                    tupla = tuple(string.split(':', 1)[1].split(','))

                    query = "INSERT INTO " + nometabela + " (nome,informacao) VALUES (%s,%s)"

                    cursor.execute(query, tupla)

                    # Make sure data is committed to the database
                    cnx.commit()

                    print("MySQL =: tabela: %s\tNome Sensor: %s\tInformação: %s" % (nometabela, tupla[0], tupla[1]))

        except KeyboardInterrupt as e:
            cursor.close()
            cnx.close()
            serial_.close()
            print("Fim do processo ...")
