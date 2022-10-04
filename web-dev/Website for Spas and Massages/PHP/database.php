<?php

define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_DATABASE', 'rksm');
$db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE);
// creating database if not exist
$create_query = "CREATE DATABASE IF NOT EXISTS rksm";
if($db->query($create_query)===TRUE) {
  // echo "Database created successfully. <br>";
} else {
  echo "Error: " . $db->error."<br>";
}


// using iwpassignments Database
$use_query = "USE rksm";
if($db->query($use_query)===TRUE) {
  // echo "Using rksm Database. <br>";
} else {
  echo "Error: " . $db->error."<br>";
}

// creating table if not exists
$create_login_table = "CREATE TABLE IF NOT EXISTS users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(255) NOT NULL,
    middle_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    phone_number VARCHAR(255) NOT NULL,
    alternative_phone_number VARCHAR(255) NOT NULL,
    age VARCHAR(255) NOT NULL,
    birthdate VARCHAR(255) NOT NULL,
    gender VARCHAR(255) NOT NULL,
    house_number VARCHAR(255) NOT NULL,
    colony VARCHAR(255) NOT NULL,
    locality VARCHAR(255) NOT NULL,
    city VARCHAR(255) NOT NULL,
    state VARCHAR(255) NOT NULL,
    card_type VARCHAR(255) NOT NULL,
    card_number VARCHAR(255) NOT NULL,
    card_name VARCHAR(255) NOT NULL,
    pref1 VARCHAR(255) NOT NULL,
    pref2 VARCHAR(255) NOT NULL
  )";

  if($db->query($create_login_table)) {
    // echo "Table created successfully. <br>";
  } else {
    // echo "Table Exists " . $db->error."<br>";
  }

?>