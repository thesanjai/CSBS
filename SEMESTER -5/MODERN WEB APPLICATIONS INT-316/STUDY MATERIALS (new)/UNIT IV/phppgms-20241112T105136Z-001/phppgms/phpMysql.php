<?php
// assumed: database, table created  as database: lpdb, user: lph, pswd: csbs
$conn = new mysqli("localhost","lph","csbs","lpdb");
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Insert data if form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $mobile_number = $_POST['mobile_number'];
// Prepare SQL to insert data
    $sql = "INSERT INTO lptbl (name, mobileno) VALUES ('$name', '$mobile_number')";
    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
// Close connection
$conn->close();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Store Name and Mobile Number</title>
</head>
<body>
    <h2>Enter your name and mobile number</h2>
    <form method="POST" action="">
        <label for="name">Name:</label><br>
        <input type="text" id="name" name="name" required><br><br>
        <label for="mobile_number">Mobile Number:</label><br>
        <input type="text" id="mobile_number" name="mobile_number" required><br><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>
