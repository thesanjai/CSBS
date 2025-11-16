<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    // Starting a session
    session_start();

    // Storing session data
    $_SESSION["user"] = "Prabaharan";

    // Accessing session data
    if(isset($_SESSION["user"])) {
        echo "User is " . $_SESSION["user"];
    }

    ?>

</body>
</html>