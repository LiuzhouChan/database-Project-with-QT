-- MySQL dump 10.13  Distrib 5.7.15, for osx10.11 (x86_64)
--
-- Host: localhost    Database: project
-- ------------------------------------------------------
-- Server version	5.7.15

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Book`
--

DROP TABLE IF EXISTS `Book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Book` (
  `ISBN` varchar(8) NOT NULL,
  `Bname` varchar(50) NOT NULL,
  `Sno` varchar(8) NOT NULL COMMENT 'FK of Shelf\n\ntype of books',
  `Bpublisher` varchar(50) NOT NULL,
  `Bauthor` varchar(50) NOT NULL,
  `Bdate` date NOT NULL,
  `Bprice` double NOT NULL,
  PRIMARY KEY (`ISBN`),
  UNIQUE KEY `ISBN_UNIQUE` (`ISBN`),
  KEY `S_idx` (`Sno`),
  CONSTRAINT `Sno` FOREIGN KEY (`Sno`) REFERENCES `Shelf` (`Sno`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Book`
--

LOCK TABLES `Book` WRITE;
/*!40000 ALTER TABLE `Book` DISABLE KEYS */;
INSERT INTO `Book` VALUES ('00000000','DATABASE','00000001','BALA','BALA','2000-01-01',50),('00000001','ARTIFICIAL','00000007','BALA','BALA','2000-01-02',50),('00000002','NETWORKING','00000007','BALA','BALA','2000-01-02',60),('00000003','ALGORITHM','00000007','BALA','BALA','2000-01-02',60);
/*!40000 ALTER TABLE `Book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BookForRent`
--

DROP TABLE IF EXISTS `BookForRent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BookForRent` (
  `Bno` varchar(8) NOT NULL,
  `ISBN` varchar(8) NOT NULL COMMENT 'FB of Book',
  `Bposi` varchar(8) DEFAULT NULL COMMENT 'Reader’s Rno or NULL',
  PRIMARY KEY (`Bno`),
  UNIQUE KEY `Bno_UNIQUE` (`Bno`),
  KEY `ISBN_idx` (`ISBN`),
  KEY `Bposi_idx` (`Bposi`),
  CONSTRAINT `Bposi` FOREIGN KEY (`Bposi`) REFERENCES `Reader` (`Rno`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `ISBN` FOREIGN KEY (`ISBN`) REFERENCES `Book` (`ISBN`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BookForRent`
--

LOCK TABLES `BookForRent` WRITE;
/*!40000 ALTER TABLE `BookForRent` DISABLE KEYS */;
INSERT INTO `BookForRent` VALUES ('00000000','00000000',NULL),('00000001','00000000',NULL),('00000002','00000001',NULL),('00000003','00000001',NULL),('00000004','00000002',NULL),('00000005','00000002',NULL),('00000006','00000003',NULL),('00000007','00000003',NULL);
/*!40000 ALTER TABLE `BookForRent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BorrowRecord`
--

DROP TABLE IF EXISTS `BorrowRecord`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BorrowRecord` (
  `BRno` int(20) NOT NULL,
  `operNo` varchar(8) NOT NULL COMMENT 'FK of Reader&Manager',
  `Rno` varchar(8) NOT NULL COMMENT 'FK of Reader',
  `Bno` varchar(8) NOT NULL COMMENT 'FK of Book',
  `startTime` datetime NOT NULL,
  PRIMARY KEY (`BRno`),
  UNIQUE KEY `BRno_UNIQUE` (`BRno`),
  KEY `Rno_idx` (`Rno`),
  KEY `Bno_idx` (`Bno`),
  CONSTRAINT `Bno` FOREIGN KEY (`Bno`) REFERENCES `BookForRent` (`Bno`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Rno` FOREIGN KEY (`Rno`) REFERENCES `Reader` (`Rno`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BorrowRecord`
--

LOCK TABLES `BorrowRecord` WRITE;
/*!40000 ALTER TABLE `BorrowRecord` DISABLE KEYS */;
/*!40000 ALTER TABLE `BorrowRecord` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Fine`
--

DROP TABLE IF EXISTS `Fine`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Fine` (
  `maxday` int(4) NOT NULL,
  `rate` double(2,1) NOT NULL,
  PRIMARY KEY (`maxday`),
  UNIQUE KEY `day_UNIQUE` (`maxday`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Fine`
--

LOCK TABLES `Fine` WRITE;
/*!40000 ALTER TABLE `Fine` DISABLE KEYS */;
INSERT INTO `Fine` VALUES (30,0.2);
/*!40000 ALTER TABLE `Fine` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Manager`
--

DROP TABLE IF EXISTS `Manager`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Manager` (
  `Mon` varchar(8) NOT NULL,
  `password` varchar(50) NOT NULL,
  PRIMARY KEY (`Mon`),
  UNIQUE KEY `Mon_UNIQUE` (`Mon`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Manager`
--

LOCK TABLES `Manager` WRITE;
/*!40000 ALTER TABLE `Manager` DISABLE KEYS */;
INSERT INTO `Manager` VALUES ('00000000','root'),('00000001','root');
/*!40000 ALTER TABLE `Manager` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Reader`
--

DROP TABLE IF EXISTS `Reader`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Reader` (
  `Rno` varchar(8) NOT NULL,
  `password` varchar(50) NOT NULL,
  `Rname` varchar(50) NOT NULL,
  `Rbirth` date NOT NULL,
  `Rsex` tinyint(1) NOT NULL COMMENT '0: male\n1: female',
  `Rdept` varchar(50) NOT NULL,
  `BmaxNum` int(11) NOT NULL DEFAULT '5',
  `Rdebt` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`Rno`),
  UNIQUE KEY `Rno_UNIQUE` (`Rno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Reader`
--

LOCK TABLES `Reader` WRITE;
/*!40000 ALTER TABLE `Reader` DISABLE KEYS */;
INSERT INTO `Reader` VALUES ('20160000','1234','lwd','1996-05-17',0,'computer science',5,0),('20160001','1234','cy','1996-05-16',0,'computer science',5,0),('20160002','1234','clz','1996-05-15',1,'computer science',5,0),('20160003','1234','deiw','1996-05-14',1,'computer science',5,1);
/*!40000 ALTER TABLE `Reader` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ReturnRecord`
--

DROP TABLE IF EXISTS `ReturnRecord`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ReturnRecord` (
  `RRno` int(20) NOT NULL,
  `operNo` varchar(8) NOT NULL,
  `BRno` int(20) NOT NULL COMMENT 'FK of BorrowRecord',
  `returnTime` datetime NOT NULL,
  PRIMARY KEY (`RRno`),
  UNIQUE KEY `RRno_UNIQUE` (`RRno`),
  KEY `BRno_idx` (`BRno`),
  CONSTRAINT `FKBR2` FOREIGN KEY (`BRno`) REFERENCES `BorrowRecord` (`BRno`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ReturnRecord`
--

LOCK TABLES `ReturnRecord` WRITE;
/*!40000 ALTER TABLE `ReturnRecord` DISABLE KEYS */;
/*!40000 ALTER TABLE `ReturnRecord` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Shelf`
--

DROP TABLE IF EXISTS `Shelf`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Shelf` (
  `Sno` varchar(8) NOT NULL,
  `Stype` varchar(50) NOT NULL,
  PRIMARY KEY (`Sno`),
  UNIQUE KEY `Sno_UNIQUE` (`Sno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Shelf`
--

LOCK TABLES `Shelf` WRITE;
/*!40000 ALTER TABLE `Shelf` DISABLE KEYS */;
INSERT INTO `Shelf` VALUES ('00000000','politics'),('00000001','economy'),('00000002','PE'),('00000003','environment'),('00000004','literature'),('00000005','electric'),('00000006','math'),('00000007','computer'),('00000008','chemistry'),('00000009','biology');
/*!40000 ALTER TABLE `Shelf` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `renewrecord`
--

DROP TABLE IF EXISTS `renewrecord`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `renewrecord` (
  `NRno` int(20) NOT NULL,
  `operNo` varchar(8) NOT NULL,
  `BRno` int(20) NOT NULL,
  `restartTime` datetime NOT NULL,
  PRIMARY KEY (`NRno`),
  UNIQUE KEY `NRno_UNIQUE` (`NRno`),
  KEY `FKbr_idx` (`BRno`),
  CONSTRAINT `FKbr` FOREIGN KEY (`BRno`) REFERENCES `BorrowRecord` (`BRno`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `renewrecord`
--

LOCK TABLES `renewrecord` WRITE;
/*!40000 ALTER TABLE `renewrecord` DISABLE KEYS */;
/*!40000 ALTER TABLE `renewrecord` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-12-20  0:03:10
