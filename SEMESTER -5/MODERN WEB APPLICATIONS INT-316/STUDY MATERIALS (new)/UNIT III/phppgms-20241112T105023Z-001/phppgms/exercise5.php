<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Check the entered city in the list</h2>
    <form method="post" action="">
        <label for="txtCity">Enter the City: </label>
        <input type="text" id="txtCity" name="txtCity" required>
        <input type="submit" value="Submit">
    </form>

    <?php
    $flg=FALSE;
    $position=0;
    $city="" ;
    $arrayCity = array('thanjavur','trichy','madurai','salem','chennai');

    function showCity()
    {  global $arrayCity;
        for ($i=0; $i< 5;$i++)
            print("$arrayCity[$i]<br>"); 
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $city= $_POST['txtCity'];
    for ($i=0;$i<count($arrayCity);$i++)
    {
    if( strtolower($city)==strtolower($arrayCity[$i]))
    {   $flg=TRUE;
        $position=$i+1;
        break;  }
    }
    if ($flg==TRUE)
        {
            echo "<p style=color:blue> found @ $position </p>";
            showCity();
        }
    else
        {
        echo "<p style=color:blue> Not found </p>"; 
            showCity();
        }
    }
    ?>
</body>
</html>