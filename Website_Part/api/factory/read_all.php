<?php

header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");


//Creating Array for JSON response
$response = array();
 
// Include data base connect class
$filepath = realpath (dirname(__FILE__));
require_once($filepath."/db_connect.php");

 // Connecting to database 
$db = new DB_CONNECT();	
 
 // Fire SQL query to get all data from factory
$result = mysql_query("SELECT *FROM factory") or die(mysql_error());
 
// Check for succesfull execution of query and no results found
if (mysql_num_rows($result) > 0) {
    
	// Storing the returned array in response
    $response["factory"] = array();
 
	// While loop to store all the returned response in variable
    while ($row = mysql_fetch_array($result)) {
        // temperoary user array
        $factory = array();
        $factory["id"] = $row["id"];
        $factory["alldetect"] = $row["alldetect"];
		$factory["waterdetect"] = $row["waterdetect"];
        $factory["colordetect"] = $row["colordetect"];
        $factory["weightdetect"] = $row["weightdetect"];
        $factory["shapedetect"] = $row["shapedetect"];
        $factory["qualifieddetect"] = $row["qualifieddetect"];
        $factory["waterrejected"] = $row["waterrejected"];
        $factory["colorrejected"] = $row["colorrejected"];
        $factory["weightrejected"] = $row["weightrejected"];
        $factory["shaperejected"] = $row["shaperejected"];
        $factory["qualified"] = $row["qualified"];
        $factory["flamedetect"] = $row["flamedetect"];
        $factory["intencontrol"] = $row["intencontrol"];
        $factory["tempdetect"] = $row["tempdetect"];

		// Push all the items 
        array_push($response["factory"], $factory);
    }
    // On success
    $response["success"] = 1;
 
    // Show JSON response
    echo json_encode($response);
}	
else 
{
    // If no data is found
	$response["success"] = 0;
    $response["message"] = "No data on factory found";
 
    // Show JSON response
    echo json_encode($response);
}
?>