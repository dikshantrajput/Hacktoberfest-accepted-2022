<?php session_start();
include('../PHP/database.php');
$user = $_SESSION['login_user'];
if (empty($user)) {
    echo "script";
    header("location: ./login.html");
    exit();
} ?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard</title>
</head>
<body>



<?php
                $user = $_SESSION['login_user'];
                $sql = "SELECT * from users where email='$user'";
                $result = mysqli_query($db, $sql);
                $count = mysqli_num_rows($result);
                if($count == 0){
                    echo "No user available.";
                }
                while ($fetch = mysqli_fetch_assoc($result)) {
                    echo '<div class="card my-2">
                        <div class="card-body">
                            <center><h1 class="card-title"> Welcome' . $fetch['first_name'] . '</h1>
                            <p class="card-text"> Your Email is' . $fetch['email'] . '</p>
                            <p> Your Contact Number is' . $fetch['phone_number']  .  '</p>
                            <a class="btn btn-success" href="./PHP/update.php?id='.$fetch['id'] .'"role="button">Edit Password</a>
                            <a class="btn btn-danger" href="../PHP/delete.php?id=' . $fetch['id'] . '" role="button">Delete User</a>
                            </center>
                        </div>
                    </div>';
                }
?>

</body>
</html>

