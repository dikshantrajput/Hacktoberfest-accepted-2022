<?php
include('./database.php');
session_start();

$myusername = $_POST['email'];
$mypassword = $_POST['password'];
$sql = "SELECT * FROM users WHERE email = '$myusername' and password = '$mypassword'";
$result = mysqli_query($db, $sql);
$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
$count = mysqli_num_rows($result);

// If result matched $myusername and $mypassword, table row must be 1 row

if ($count == 1) {
    $_SESSION['login_user'] = $myusername;
    echo "<script> alert('Succesfully logged in.') </script>";
    header("location: ../Pages/dashboard.php");
    exit();
} 
else 
{
    echo "<script> alert('Please check your credentials and try again.') </script>";
    exit();
}
?>