<?php

include('database.php');

$results = mysqli_query($conn, "SELECT * FROM users");

?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <a href="add.php">Add data</a>
    <ul>
        <?php
        foreach ($results as $result) { ?>
            <li><?= $result['id']; ?></li>
            <li><?= $result['name']; ?></li>
            <li><?= $result['phone']; ?></li>
            <a href="edit.php?id=<?= $result['id'] ?>">Edit</a>
            <a href="delete.php?id=<?= $result['id'] ?>">Delete</a>
            <br>

        <?php
        }
        ?>
    </ul>
</body>

</html>