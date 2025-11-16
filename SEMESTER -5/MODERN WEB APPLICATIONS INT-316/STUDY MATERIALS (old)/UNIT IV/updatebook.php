<html>
<head>

<style>
	h1{
		text-align:center;
	}
table{
		border-collapse:collapse;
	}
	table,td,th{
		border:2px solid green;

	}

	td,th{
		padding:10px;
		font-size:16pt;

	}
</style>
</head>
<body>
<h1>Books List</h1>
<?php // dbexample1.php
	require_once 'login.php';

	$conn = new mysqli($hn, $un, $pw, $db);

	if ($conn->connect_error) 
		die("Fatal Error");

	$title = $_POST['title'];
	$author = $_POST['author'];
	$price = $_POST['cost'];
	$available = $_POST['available'];
	$bookid = $_POST['bookid'];
	$op = $_POST['submit'];
	
	if($op=="update"){
		$stmt = $conn->prepare("UPDATE books set title= ?, price = ?, author = ?, available= ? WHERE id =?");
		$stmt->bind_param("sdssi",$title,$price,$author, $available,$bookid);
		$result=$stmt->execute();

		if (!$result) 
			die("Fatal Error");
		echo "<h2>Book details updated successfully...</h2>";
	}else if($op=="delete"){
		$stmt = $conn->prepare("DELETE FROM books WHERE id =?");
		$stmt->bind_param("i",$bookid);
		$result=$stmt->execute();

		if (!$result) 
			die("Fatal Error");
		echo "<h2>Book details deleted successfully...</h2>";

	}
	$conn->close();

?>
<h3><a href='bookhome.html'>Home Page</a></h3>
</body>
</html>