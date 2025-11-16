<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Odd or Even Checker</title>
</head>
<body>

<form method="post" action="">
    <label for="number">Enter a number:</label>
    <input type="text" id="number" name="number" required>
    <input type="submit" value="Check">
</form>

<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get the value from the HTML text box
    $number = $_POST['number'];

    // Check if the input is a number
    if (is_numeric($number)) {
        // Check if the number is even or odd
        if ($number % 2 == 0) {
            echo "<p style=color:green;>The number $number is Even.</p>";
        } else {
            echo "<p style=color:red;>The number $number is Odd.</p>";
        }
    } else {
        echo "<p>Please enter a valid number.</p>";
    }
}
?>

</body>
</html>
