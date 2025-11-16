<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>    
</head>
<body>
    <h1 style="color:Orange;"> Login Page </h1>
<script>
    function fun1() 
    {
        var input1 = document.getElementById("txtbox1").value;
        var input2 = document.getElementById("txtbox2").value;
        const mobilePattern = /^[0-9]{10}$/;
        if (input1 == "" || input2== ""){ 
            alert("Text box cannot be empty");
            return false;}
        else if (input1.length < 3 || input2.length > 15) {
            alert("Name must be between 3 and 15 characters long");
            return false;}
        else if(!mobilePattern.test(input2)){ 
            alert("Mobile number must be exactly 10 digits");
            return false;}
    }
    //document.getElementById("btn").addEventListener("click",fun1());
</script>
<form method="POST" action="display.php" onsubmit="return fun1()" >
       <label for="txtbox1">enter your name:</label>
       <input type="text" id="txtbox1" name="txtbox1" require><br>
       <br><label for="txtbox2">enter your mobileNumber:</label>
       <input type="text" id="txtbox2" name="txtbox2" require>
       <input type="submit" value="Submit" id="btn" name="btn">
    </form>
</body>
</html>