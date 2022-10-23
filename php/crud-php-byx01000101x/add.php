<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add</title>
</head>

<body>
    <form action="add.php" method="POST">
        <input type="text" name="name" placeholder="enter name..." required>
        <input type="number" name="phone" placeholder="enter number..." required>
        <button type="submit" name="submit"> Submit </button>
        <a href="index.php"> Back </a>
    </form>
</body>

</html>


<?php

include('database.php');

if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $phone = $_POST['phone'];

    $insert = mysqli_query($conn, "INSERT INTO users(name, phone) VALUES ('$name', '$phone')");

    echo "user berhasil di tambahkan";
    header('index.php');
}

?>