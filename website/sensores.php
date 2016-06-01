<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html;charset=utf-8" /> <!--Introduza esta linha no teu html-->
    <style>
        table {
            width: 100%;
        }

        table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
        }

        th, td {
            padding: 5px;
            text-align: left;
        }

        table#t01 tr:nth-child(even) {
            background-color: #eee;
        }

        table#t01 tr:nth-child(odd) {
            background-color: #ffe;
        }

        table#t01 th {
            background-color: black;
            color: white;
        }
    </style>

    <?php

    $page = $_SERVER['PHP_SELF'];
    $sec = "10";

    ?>
    
    <meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">

</head>
<body>

<table id="t01">

    <?php

    $servername = "sql3.freesqldatabase.com";
    $username = "sql3121775";
    $password = "";
    $dbname = "sql3121775";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT tempo, nome, informacao FROM SensorLumi ORDER BY tempo DESC LIMIT 2";
    $sql_preTep = "SELECT tempo, nome, informacao FROM SensorPreTep ORDER BY tempo DESC LIMIT 2";

    $resultados = array($conn->query($sql), $conn->query($sql_preTep));

    if ($resultados[0]->num_rows > 0 || $resultados[1]->num_rows > 0) {

        echo "<tr>";
        echo "<th>Data</th>";
        echo "<th>Sensor</th>";
        echo "<th>Informacao</th>";
        echo "</tr>";

        foreach ($resultados as $result) {

            if ($result->num_rows > 0) {

                while ($row = $result->fetch_assoc()) {

                    echo "<tr>";

                    echo "<td>" . $row["tempo"] . "</td>";
                    echo "<td>" . $row["nome"] . "</td>";
                    echo "<td>" . $row["informacao"] . "</td>";

                    echo "</tr>";

                }

            }

        }


    } else {
        echo "0 results";
    }

    $conn->close();
    ?>

</table>
