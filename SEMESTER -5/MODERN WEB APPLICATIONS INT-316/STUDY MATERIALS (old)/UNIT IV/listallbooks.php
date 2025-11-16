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

	$query = "SELECT * FROM books";

	$result = $conn->query($query);

	if (!$result) 
		die("Fatal Error");

	//echo $result->num_rows;
	
	$rows = $result->num_rows;
?>
	<table align="center">
	<tr>
		<th>Book Id</th>
		<th>Author</th>
		<th>Title of the Book</th>
	</tr>
<?php
	for ($j = 0 ; $j < $rows ; ++$j)
	{
		$row = $result->fetch_assoc()  ;//$result->fetch_array(MYSQLI_ASSOC);
		echo '<tr><td>' . htmlspecialchars($row['id']) . '</td>';
		echo '<td>' . htmlspecialchars($row['author']) . '</td>';
		echo '<td>' . htmlspecialchars($row['title']) . '</td></tr>';
		
	}

?>
	</table>
<?php

	$result->close();
	$conn->close();

?>
<h3><a href='bookhome.html'>Home Page</a></h3>
</body>
</html>