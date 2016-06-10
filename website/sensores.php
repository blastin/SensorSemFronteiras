<!DOCTYPE html>
<html>
<head>

    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>

    <style>
        table {
            width: 100%;
        }

        table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
        }

        th, td {
            padding: 3px;
            text-align: left;
        }

        table#t01 tr:nth-child(even) {
            background-color: #eee;
        }

        table#t01 tr:nth-child(odd) {
            background-color: #ffe;
        }

        table#t01 th {
            background-color: darkslateblue;
            color: white;
        }
    </style>

    <?php

    $page = $_SERVER['PHP_SELF'];
    $sec = "3";

    $db_host = getenv('OPENSHIFT_MYSQL_DB_HOST'); //sample host 
    $db_user = getenv('OPENSHIFT_MYSQL_DB_USERNAME');
    $db_pass = getenv('OPENSHIFT_MYSQL_DB_PASSWORD');
    $db_name = 'php'; //this is the database I created in PhpMyAdmin

    $sql_names = "SHOW TABLES";
    $sql_tempo = "SELECT tempo FROM php.SensorLumi ORDER BY tempo DESC LIMIT 1";

    $sql_lumi = "SELECT  nome, informacao FROM php.SensorLumi ORDER BY tempo DESC LIMIT 1";
    $sql_preTep = "SELECT  nome, informacao FROM php.SensorPreTep ORDER BY tempo DESC LIMIT 1";
    $sql_aceleracao = "SELECT  nome, informacao FROM php.SensorAcel ORDER BY tempo DESC LIMIT 1";
    $sql_qualidadear = "SELECT  nome, informacao FROM php.SensorQuAr ORDER BY tempo DESC LIMIT 1";
    $sql_umidadesolo = "SELECT  nome, informacao FROM php.SensorUmidadeSolo ORDER BY tempo DESC LIMIT 1";

    ?>

    <meta http-equiv="refresh" content="<?php echo $sec ?>;URL='<?php echo $page ?>'">

</head>
<body>

<table id="t01">

    <?php

    // Create connection
    $conn = new mysqli($db_host, $db_user, $db_pass, $db_name);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $tabelaName_resultado = $conn->query($sql_names);

    $resultados = array(

        $conn->query($sql_aceleracao),
        $conn->query($sql_lumi),
        $conn->query($sql_preTep),
        $conn->query($sql_qualidadear),
        $conn->query($sql_umidadesolo)

    );

    $tempo_resultado = $conn->query($sql_tempo);

    if ($tempo_resultado->num_rows > 0) {

        echo "<tr>";

        echo "<th> Last Update </th>";

        $row = $tempo_resultado->fetch_assoc();

        $tempo = $row["tempo"];

        while($table = $tabelaName_resultado->fetch_array()) {
            echo "<th>" . $table[0] . "</th>";
        }

        echo "</tr>";

        echo "<td>" . $tempo ." </td>";

        foreach ($resultados as $result) {

            if ($result->num_rows > 0) {

                $row = $result->fetch_assoc();

                echo "<td>" . $row["informacao"] . "</td>";

            }
        }

    }

    $conn->close();

    ?>

</table>
