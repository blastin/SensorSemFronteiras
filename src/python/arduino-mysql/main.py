#!/usr/bin/env python
# -*- coding: utf-8 -*-

import mysql.connector
import time
from optparse import OptionParser
import os.path
import tailer

SLEEP_INTERVAL = 5.0

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

    try:

        p = OptionParser("usage: tail.py file")
        (options, args) = p.parse_args()
        if len(args) < 1:
            p.error("must specify a file to watch")

        print("Verificando se o arquivo já foi aberto ...")

        while not os.path.isfile(args[0]):
            time.sleep(SLEEP_INTERVAL)

        with open(args[0], 'r') as fin:

            print(fin)

            for line in tailer.follow(open(args[0])):

                string = line.strip()

                if len(string) > 0:

                    nometabela = string.split(':', 1)[0]

                    print(string)

                    tupla_informacao = tuple(string.split(':', 1)[1].split(','))

                    adicionar_info = "INSERT INTO " + nometabela + " (nome,informacao) VALUES (%s,%s)"

                    cursor.execute(adicionar_info, tupla_informacao)

                    # Make sure data is committed to the database
                    cnx.commit()

    except Exception as e:
        cursor.close()
        cnx.close()
        print(e)
