<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1> content from the page 1 </h1>
    <?php
    echo "cookie variabel 'txtbox1': taken from first page, its value is  " . $_COOKIE["txtbox1"] 
    //echo "<br><h2 style=color:red> no cookies used - content cannot be taken across the pages </h2>"; 
    ?>
    <br>
    <a href="exercise8.php"> go to first page</a>
</body>
</html>