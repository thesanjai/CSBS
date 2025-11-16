<?php
// Database connection details
$host = 'localhost';    // or 127.0.0.1
$dbname = 'lpdb';
$username = 'lph';     // your MySQL username
$password = 'csbs';         // your MySQL password

// Create connection
$conn = new mysqli($host, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// SQL query to fetch name and mobile number
$sql = "SELECT name, mobileno FROM lptbl";
$result = $conn->query($sql);

// Check if there are results and display them in a form
if ($result->num_rows > 0) {
    // Output data of each row in a form with textboxes
    while($row = $result->fetch_assoc()) {
        echo '<form>';
        echo 'Name: <input type="text" name="name" value="' . $row["name"] . '" readonly><br><br>';
        echo 'Mobile Number: <input type="text" name="mobile" value="' . $row["mobileno"] . '" readonly><br><br>';
        echo '</form>';
    }
} else {
    echo "0 results";
}

// Close connection
$conn->close();
?>
