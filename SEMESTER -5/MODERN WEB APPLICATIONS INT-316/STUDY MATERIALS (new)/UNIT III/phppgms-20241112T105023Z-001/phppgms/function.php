<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    function add($a,$b)
    {
        return $a+$b;
    }
    $num1=100;
    $num2=200;
    echo"fun call: addition()".add($num1,$num2);
    echo"<br><br>";
    print("fun call: addition()".add($num1,$num2));
    ?>
</body>
</html>