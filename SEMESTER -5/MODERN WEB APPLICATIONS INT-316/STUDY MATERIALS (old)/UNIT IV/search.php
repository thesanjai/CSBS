<html>
	<head>
	<title>Table Example</title>
<style>
	table{
		border-collapse:collapse;
	}
	table,td{
		border:2px solid green;

	}

	td{
		padding:10px;
		font-size:16pt;

	}

	input,option,select{

		font-size:16pt;
	}
</style>

</head>
<body>
<center>
<h1>Book Store</h1>
<?php // dbexample1.php
	require_once 'login.php';

	$conn = new mysqli($hn, $un, $pw, $db);

	$bookid = $_POST['bookid'];
	if ($conn->connect_error) 
		die("Fatal Error");

	$query = "SELECT * FROM books where id = $bookid";

	$result = $conn->query($query);

	if (!$result) 
		die("Fatal Error");
 
	//echo $result->num_rows;
	
	$rows = $result->num_rows;
	if($rows>0){
		$row = $result->fetch_assoc()  ;//$result->fetch_array(MYSQLI_ASSOC);
?>
	
<form method="post" action="updatebook.php">
<table>
<tr>
	<td><label>Book Id</label></td>
	<td><input  type="text" name="bookid" length="20" maxlength="20" value="<?= $row['id'] ?>"/></td>
</tr>
<tr>
	<td><label>Book Title</label></td>
	<td><input  type="text" name="title" length="20" maxlength="20" value="<?= $row['title'] ?>"/></td>
</tr>
<tr>
	<td><label>Author Name</label></td>
	<td><input  type="text" name="author" length="20" maxlength="20" value="<?= $row['author'] ?>"/></td>
</tr>
<tr>
	<td><label>Cost</label></td>
	<td><input  type="text" name="cost" length="20" maxlength="10" value="<?= $row['price'] ?>"/></td>
</tr>
<tr>
	<td><label>Available</label></td>
	<td><input type="radio" name="available" value="Y"/>Yes
		<input type="radio" name="available" value="N"/>No</td>
</tr>

<tr>
	<td  colspan="2" align="center"><input type="reset" value="Clear"/>
		<input type="submit" name="submit" value="update"/>
		<input type="submit" name="submit" value="delete"/></td>
</tr>
</form>
</table>



<?php
	}
	else {
?>

	<h3>No Data Found</h3>
<?php
	}
	$result->close();
	$conn->close();

?>




</center>
<h3><a href='bookhome.html'>Home Page</a></h3>
</body>
