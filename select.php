<?php
	$servername = "localhost";
	$username = "root1";
	$password = "";
	$dbname = "db_web1";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	} 

	$sql = "SELECT id, username FROM tbl_accounts where username = 'admin' and password = 'admin1'";
	$result = $conn->query($sql);

	if ($result->num_rows > 0) {
		echo "Match Found!";
	} else {
		echo "No Match Found!";
	}
	$conn->close();
?>
