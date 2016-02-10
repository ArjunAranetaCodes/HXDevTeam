<?php
	include 'db.inc.php';
	
	$username = "";
	$password = "";
	
	if(!empty($_POST['username']) && !empty($_POST['password'])){
		$username = $_POST['username'];
		$password = $_POST['password'];
		
		// Create connection
		$conn = new mysqli($servername, $serverusername, $serverpassword, $dbname);

		// Check connection
		if ($conn->connect_error) {
			die("Connection failed: " . $conn->connect_error);
		} 
		
		$sql = "SELECT id, username FROM tbl_accounts where username = '$username' and password = '$password'";
		$result = $conn->query($sql);

		if ($result->num_rows > 0) {
			echo "Match Found!";
		} else {
			echo "No Match Found!";
		}
		$conn->close();
		
	}else{
		echo "Please fill in username and password!";
		die();
	}
?>
