<!DOCTYPE html>
<html>
<head>

    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>

    <link rel="stylesheet" type="text/css" href="css/estilo.css">

    <?php

    $page = $_SERVER['PHP_SELF'];
    $sec = "2";

    $db_host = getenv('OPENSHIFT_MYSQL_DB_HOST'); //sample host 
    $db_user = getenv('OPENSHIFT_MYSQL_DB_USERNAME');
    $db_pass = getenv('OPENSHIFT_MYSQL_DB_PASSWORD');
    $db_name = 'php'; //this is the database I created in PhpMyAdmin

    $sql_names = "SHOW TABLES LIKE 'S%'";
    $sql_tempo = "SELECT tempo FROM SensorUpdate ORDER BY tempo DESC LIMIT 1";

    ?>

    <meta http-equiv="refresh" content="<?php echo $sec ?>;URL='<?php echo $page ?>'">

</head>
<body>

<table>

    <caption><H2>Analisando informações dos sensores</H2></caption>

    <br>

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

    $row = $tempo_resultado->fetch_array();

    echo "<thread>";
    echo "<tr>";

    echo "<th colspan=\"2\">Last Update</th>";

    $tempo = $row["tempo"];

    echo "<th colspan=\"1\">" . $tempo . "</th>";

    echo "</tr>";
    echo "</thread>";

    echo "<tbody>";

    while ($table = $tabelaName_resultado->fetch_array()) {

        echo "<tr>";

        $sql = "SELECT  nome, informacao FROM " . $table[0] . " ORDER BY tempo DESC LIMIT 1";

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

    $conn->close();

    ?>

</table>
