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


    $servername = "sql3.freesqldatabase.com";
    $username = "sql3121775";
    $password = "zn9aeuSusI";
    $dbname = "sql3121775";

    $sql_names = "SELECT tempo, nome FROM SensorLumi UNION SELECT tempo, nome FROM SensorPreTep UNION SELECT tempo, nome FROM SensorAcel UNION SELECT tempo, nome FROM SensorQuAr";

    $sql_lumi = "SELECT  nome, informacao FROM SensorLumi ORDER BY tempo DESC LIMIT 1";
    $sql_preTep = "SELECT  nome, informacao FROM SensorPreTep ORDER BY tempo DESC LIMIT 1";
    $sql_aceleracao = "SELECT  nome, informacao FROM SensorAcel ORDER BY tempo DESC LIMIT 1";
    $sql_qualidadear = "SELECT  nome, informacao FROM SensorQuAr ORDER BY tempo DESC LIMIT 1";
    $sql_umidadesolo = "SELECT  nome, informacao FROM SensorUmidadeSolo ORDER BY tempo DESC LIMIT 1";

    ?>

    <meta http-equiv="refresh" content="<?php echo $sec ?>;URL='<?php echo $page ?>'">

</head>
<body>

<table id="t01">

    <?php

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $resultado = $conn->query($sql_names);

    $resultados = array(

        $conn->query($sql_lumi),
        $conn->query($sql_preTep),
        $conn->query($sql_aceleracao),
        $conn->query($sql_qualidadear),
        $conn->query($sql_umidadesolo)
    );


    if ($resultado->num_rows > 0) {

        echo "<tr>";

        echo "<th> Tempo </th>";

        $row = $resultado->fetch_assoc();

        $tempo = $row["tempo"];

        do {
            echo "<th>" . $row["nome"] . "</th>";
        }while($row = $resultado->fetch_assoc());

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