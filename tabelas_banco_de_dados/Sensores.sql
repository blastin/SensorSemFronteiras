-- phpMyAdmin SQL Dump
-- version 4.0.10.12
-- http://www.phpmyadmin.net
--
-- Servidor: 127.2.97.130:3306
-- Tempo de Geração: 15/06/2016 às 01:03
-- Versão do servidor: 5.5.45
-- Versão do PHP: 5.3.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET GLOBAL time_zone = "-03:00";
SET GLOBAL event_scheduler = "ON";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Banco de dados: `php`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorAcel`
--

CREATE TABLE IF NOT EXISTS `SensorAcel` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorLumi`
--

CREATE TABLE IF NOT EXISTS `SensorLumi` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorPressao`
--

CREATE TABLE IF NOT EXISTS `SensorPressao` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorQuAr`
--

CREATE TABLE IF NOT EXISTS `SensorQuAr` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorTemp`
--

CREATE TABLE IF NOT EXISTS `SensorTemp` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorUmidadeAr`
--

CREATE TABLE IF NOT EXISTS `SensorUmidadeAr` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `SensorUmidadeSolo`
--

CREATE TABLE IF NOT EXISTS `SensorUmidadeSolo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `nome` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `medida` float DEFAULT NULL,
  `unidade_medida` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `informacao` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estrutura para tabela `TimeUpdate`
--

CREATE TABLE IF NOT EXISTS `TimeUpdate` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `void` smallint(2) NOT NULL,
  `tempo` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

DELIMITER $$
--
-- Eventos
--
CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `luminosidade_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-10 00:00:00' ON COMPLETION PRESERVE ENABLE DO truncate php.`SensorLumi`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `aceleracao_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-10 00:00:00' ON COMPLETION PRESERVE ENABLE DO truncate php.`SensorAcel`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `pressao_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-10 00:00:00' ON COMPLETION PRESERVE ENABLE DO truncate php.`SensorPressao`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `qualidade_ar_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-10 00:00:00' ON COMPLETION PRESERVE ENABLE DO truncate php.`SensorQuAr`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `umidade_solo_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-10 00:00:00' ON COMPLETION PRESERVE ENABLE DO truncate php.`SensorUmidadeSolo`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `temperatura_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-13 00:00:00' ON COMPLETION PRESERVE ENABLE COMMENT 'Limpa a tabela do sensor de temperatura a cada 10 minutos' DO truncate php.`SensorTemp`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `umidade_do_ar_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-13 00:00:00' ON COMPLETION PRESERVE ENABLE COMMENT 'Limpa a tabela do sensor de umidade do ar a cada 10 minutos' DO truncate php.`SensorUmidadeAr`$$

CREATE DEFINER=`adminSFmAMTp`@`127.2.97.130` EVENT `time_stamp_limpeza` ON SCHEDULE EVERY 10 MINUTE STARTS '2016-06-14 22:02:36' ON COMPLETION PRESERVE ENABLE COMMENT 'Limpa a tabela do sensor de time_stamp a cada 10 minutos' DO truncate php.`TimeUpdate`$$

DELIMITER ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
