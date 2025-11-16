<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1 style="color:blue"> Welcome Page......</h1> 
<?php
    $validationMessage = "";
    if($_SERVER["REQUEST_METHOD"] == 'POST') {
        $inputtxt1 = $_POST["txtbox1"];
        $inputtxt2= $_POST["txtbox2"];
        if (strtoupper($inputtxt1) == "PRABAHARAN" && $inputtxt2=="9894930946")
            $validationMessage = "You are Valid User... <br> welcome " . $inputtxt1 . "Your MobileNo:" . $inputtxt2;
        else
        $validationMessage = "Invalid User";
        
        setcookie("txtbox1",$inputtxt1,time()+3600, "/");
    }
    echo $validationMessage;  
    ?>
<br><br>
<form method="POST" action="nextPage.php">
<input type="submit" value="Next Page">
</form>
</body>
</html>