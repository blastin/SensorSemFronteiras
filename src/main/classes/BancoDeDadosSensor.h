/*
 * BancoDeDadosSensor.h
    Copyright (C) <2016>  <Jeff>

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

 */

#ifndef BANCODEDADOS_CLASS_SENSORES_H
#define BANCODEDADOS_CLASS_SENSORES_H

#include <MySQL_Encrypt_Sha1.h>
#include <MySQL_Packet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

extern const char * TABELA_SENSOR_LUMINOSIDADE;
extern const char * TABELA_SENSOR_QUALIDADE_AR;
extern const char * TABELA_SENSOR_VIBRACOES;
extern const char * TABELA_SENSOR_PRESSAO_TEMPERATURA;

#endif