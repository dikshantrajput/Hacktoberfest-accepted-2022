<?php 
include './database.php';
session_start();
$id = $_GET['id'];
$delete_query = "DELETE FROM users WHERE id = '$id'";
$result = mysqli_query($db, $delete_query);
if ($result) {
    echo "<center><h1>Deleted User with E-Mail ".$_SESSION['login_user']." </h1></center>";;
} else {
    echo "Error: " . $db->error."<br>";
}
?>