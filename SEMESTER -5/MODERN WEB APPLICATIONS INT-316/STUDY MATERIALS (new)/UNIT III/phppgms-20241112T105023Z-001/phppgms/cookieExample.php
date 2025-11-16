<?php
// Set a cookie named "cookieVar" with value "CSBS-2024" that expires in 1 hour (3600 seconds)
setcookie("cookieVar", "CSBS-2024", time() + 3600, "/"); // The "/" means the cookie is available for the entire domain

// Check if cookie is set global variable 
if (isset($_COOKIE["cookieVar"])) {
    echo "'cookieVar:' is set!<br>";
    echo "Value: " . $_COOKIE["cookieVar"];
} else {
    echo "CookieVar is not set!";
}
?>