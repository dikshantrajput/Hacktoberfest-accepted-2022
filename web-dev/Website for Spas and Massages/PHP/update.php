<?php
include("./database.php");
session_start();
$id = $_GET['id'];
$password = $_GET["password"];
$sql = "UPDATE users SET password='$password' WHERE id='$id'";
if ($db->query($sql)) {
    echo "<center><h1>Updated Password to ".$password. " </h1></center>";
} else {
    echo "Error: " . $db->error . "<br>";
}
?>