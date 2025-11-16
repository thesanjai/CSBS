<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<script>
        function validateForm() {
            var inputText = document.getElementById("inputText").value;
            if (inputText == "") {
                alert("Text box cannot be empty");
            }
        }

</script>
    
    <?php
    $validationMessage = "";
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $inputText = $_POST["inputText"];
    if (strtoupper($inputText) == "SASTRA") {
        $validationMessage = "Text is valid!";
    } else {
        $validationMessage = "Text must be 'SASTRA'";
    }
    echo "<p style=color:blue> $validationMessage </p>"; 
    }
    ?>
    <form method="POST" action="" onsubmit="validateForm()">
    <label for="inputText">Enter Text:</label>
    <input type="text" id="inputText" name="inputText">
    <input type="submit" value="Submit"  >
</form>
</body>
</html>