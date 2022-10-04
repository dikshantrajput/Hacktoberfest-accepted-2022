<?php
include('./database.php');

$fname = $_POST['FName'];
$lname = $_POST['LName'];
$mname = $_POST['MName'];
// $name = $fname . $Mname . $lname;
$passwd = $_POST['password'];
$cn = "91" . $_POST['contactno'];
$acn = "91" . $_POST['acontactno'];
$age = $_POST['Age'];
$email = $_POST['Email'];
$bdate = $_POST['bdate'];
$sex = $_POST['Sex'];
$hno = $_POST['hno'];
$coname = $_POST['cname'];
$loname = $_POST['lname'];
$cityname = $_POST['cityname'];
$sname = $_POST['sname'];
// $add = $_POST['hno'] . ", " . $_POST['cname'] . ", " . $_POST['lname'] . ", " . $_POST['cityname'] . ", " . $_POST['sname'];
$ctype = $_POST['ctype'];
$cnumber = $_POST['cnumber'];
$cname = $_POST['cardname'];
$pref = $_POST['pref1'];
$hoi = $_POST['pref2'];


$sql = "INSERT INTO users (first_name , middle_name , last_name , email , password , phone_number , alternative_phone_number , age , birthdate , gender , house_number , colony , locality , city , state , card_type , card_number , card_name , pref1 , pref2 ) VALUES ('$fname', '$mname', '$lname', '$email', '$passwd', '$cn', '$acn', '$age', '$bdate', '$sex', '$hno', '$coname', '$loname', '$cityname', '$sname', '$ctype', '$cnumber', '$cname', '$pref', '$hoi')";
if ($db->query($sql)) {
    echo "<script>alert('Succesfully Registered')</script>";
} else {
    echo "Error: " . $db->error."<br>";
}

?> 
  
