<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Checking...! Are you my Friend....?</h2>
    <form method="post" action="">
        <label for="txtName">Enter Your Name [check you are my friend or not..?]: </label>
        <input type="text" id="txtName" name="txtName" required>
        <input type="submit" value="Submit">
    </form>

    <?php
    $flg=FALSE;
    $position=0;
    $friend="" ;
    $arrayFriends = array('Krupahari','Gowri','Keerthana','karthika','kruthika','Asma', 'kamala');

    function showFriends()
    {  global $arrayFriends;
        for ($i=0; $i< 5;$i++)
            print("$arrayFriends[$i]<br>"); 
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $friend= $_POST['txtName'];
    for ($i=0;$i<count($arrayFriends);$i++)
    {
    if( strtolower($friend)==strtolower($arrayFriends[$i]))
    {   $flg=TRUE;
        $position=$i+1;
        break;  }
    }
    if ($flg==TRUE)
        {
            echo "<p style=color:blue> Congratulations..! you are my Friend, found @ $position </p>";
            showFriends();
        }
    else
        {
        echo "<p style=color:blue> Not found </p>"; 
        showFriends();
        }
    }
    ?>
</body>
</html>