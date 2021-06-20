-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jun 19, 2021 at 01:43 PM
-- Server version: 10.1.19-EzraDB
-- PHP Version: 7.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `managementSystem_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `management_system_tb`
--

CREATE TABLE `management_system_tb` (
  `t_id` int(11) NOT NULL,
  `t_event` varchar(50) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `management_system_tb`
--

INSERT INTO `management_system_tb` (`t_id`, `t_event`) VALUES
(1, 'Corrupted Storage'),
(2, 'LCD Blue Screen'),
(3, 'RAM Not Found');

-- --------------------------------------------------------

--
-- Table structure for table `management_system_tb`
--

CREATE TABLE `management_system_tb` (
  `t_id` int(10) UNSIGNED NOT NULL,
  `t_customer_name` varchar(50) NOT NULL DEFAULT '0',
  `t_customer_address` varchar(50) NOT NULL DEFAULT '0',
  `t_customer_phone` varchar(50) NOT NULL DEFAULT '0',
  `t_customer_email` varchar(50) NOT NULL DEFAULT '0',
  `t_customer_eventDate` varchar(50) NOT NULL DEFAULT '0',
  `t_customer_eventID` varchar(50) NOT NULL DEFAULT '0',
  `t_customer_eventCost` varchar(50) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `management_system_tb`
--

INSERT INTO `management_system_tb` (`t_id`, `t_customer_name`, `t_customer_address`, `t_customer_phone`, `t_customer_email`, `t_customer_eventDate`, `t_customer_eventID`, `t_customer_eventCost`) VALUES
(1, 'Jordan', '20392 Farm Ln, UT', '9920939212', 'joe22@gmail.com', 'Mar 19, 2021', 'Corrupted Storage', '302'),
(2, 'Ian Jones', '49320 random rd, idaho', '8019238843', 'jnian@gmail.com', 'April 02, 2021', 'LCD Blue Screen', '197'),
(4, 'Jeeter Jordan', '29932 Farmer Street Road, idaho', '2130484384', 'jjordann@gamil.com ', 'June 12, 2021', 'RAM Not Found', '254');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `management_system_tb`
--
ALTER TABLE `management_system_tb`
  ADD PRIMARY KEY (`t_id`);

--
-- Indexes for table `management_system_tb`
--
ALTER TABLE `management_system_tb`
  ADD PRIMARY KEY (`t_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `management_system_tb`
--
ALTER TABLE `management_system_tb`
  MODIFY `t_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `management_system_tb`
--
ALTER TABLE `management_systemDetail_tb`
  MODIFY `t_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
