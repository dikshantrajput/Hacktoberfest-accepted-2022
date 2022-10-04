<?php
include 'database.php';
$id = $_GET['id'];

$result = mysqli_query($conn, "SELECT * FROM users WHERE id = '$id'");
$result_arr = mysqli_fetch_array($result);

if (isset($_POST['submit'])) {
    $name = $_POST['name'];
    $phone = $_POST['phone'];
    $update = mysqli_query($conn, "UPDATE users SET name='$name', phone='$phone' WHERE id = '$id'");
    echo "Berhasil update data";
    header("Location: index.php");
}


?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update</title>
</head>

<body>

    <form action="edit.php?id=<?= $id; ?>" method="POST">
        <p>name</p>
        <input type="text" name="name" value="<?= $result_arr['name'] ?>">
        <p>phone number</p>
        <input type="number" name="phone" value="<?= $result_arr['phone'] ?>">
        <button type="submit" name="submit">Submit</button>
        <a href="index.php">Back</a>

    </form>

</body>

</html>