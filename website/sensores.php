<!DOCTYPE html>
<html>
<head>

    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>

    <link rel="stylesheet" type="text/css" href="css/estilo.css">
    
    <?php

    $page = $_SERVER['PHP_SELF'];
    $sec = "3";

    $db_host = getenv('OPENSHIFT_MYSQL_DB_HOST'); //sample host 
    $db_user = getenv('OPENSHIFT_MYSQL_DB_USERNAME');
    $db_pass = getenv('OPENSHIFT_MYSQL_DB_PASSWORD');
    $db_name = 'php'; //this is the database I created in PhpMyAdmin

    $sql_names = "SHOW TABLES";
    $sql_tempo = "SELECT tempo FROM php.SensorLumi ORDER BY tempo DESC LIMIT 1";

    ?>

    <meta http-equiv="refresh" content="<?php echo $sec ?>;URL='<?php echo $page ?>'">

</head>
<body>

<table>

    <caption>Analisando informações dos sensores</caption>

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

        echo "<thread>";
        echo "<tr>";

        echo "<th colspan=\"2\">Last Update</th>";

        $row = $tempo_resultado->fetch_assoc();

        $tempo = $row["tempo"];

        echo "<th colspan=\"1\">" . $tempo . "</th>";

        echo "</tr>";
        echo "</thread>";

        echo "<tbody>";

        while ($table = $tabelaName_resultado->fetch_array()) {

            echo "<tr>";

            $sql = "SELECT  nome, informacao FROM php." . $table[0] . " ORDER BY tempo DESC LIMIT 1";

            $result = $conn->query($sql);

            if ($result->num_rows > 0) {

                $row = $result->fetch_assoc();

                echo "<th colspan=\"2\">" . $row["nome"] . "</th>";
                echo "<td colspan=\"1\">" . $row["informacao"] . "</td>";

            } else {
                echo "<th colspan=\"2\">" . $table[0] . "</th>";
                echo "<td colspan=\"1\"> </td>";
            }

            echo "</tr>";
        }

        echo "</tbody>";

    } else {
        echo '<th>Sem informações dos sensores.</th>';
    }

    $conn->close();

    ?>

</table>
