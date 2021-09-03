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
 
// Check if we got the field from the user
if (isset($_GET["id"])) {
    $id = $_GET['id'];
 
     // Fire SQL query to get factory data by id
    $result = mysql_query("SELECT *FROM factory WHERE id = '$id'");
	
	//If returned result is not empty
    if (!empty($result)) {

        // Check for succesfull execution of query and no results found
        if (mysql_num_rows($result) > 0) {
			
			// Storing the returned array in response
            $result = mysql_fetch_array($result);
			
    		// temperoary user array
            $factory = array();
            $factory["id"] = $result["id"];
            $factory["alldetect"] = $result["alldetect"];
            $factory["waterdetect"] = $result["waterdetect"];
            $factory["colordetect"] = $result["colordetect"];
            $factory["weightdetect"] = $result["weightdetect"];
            $factory["shapedetect"] = $result["shapedetect"];
            $factory["qualifieddetect"] = $result["qualifieddetect"];
            $factory["waterrejected"] = $result["waterrejected"];
            $factory["colorrejected"] = $result["colorrejected"];
            $factory["weightrejected"] = $result["weightrejected"];
            $factory["shaperejected"] = $result["shaperejected"];
            $factory["qualified"] = $result["qualified"];
            $factory["flamedetect"] = $result["flamedetect"];
            $factory["intencontrol"] = $result["intencontrol"];
            $factory["tempdetect"] = $result["tempdetect"];
          
            $response["success"] = 1;

            $response["factory"] = array();
			
			// Push all the items 
            array_push($response["factory"], $factory);
 
            // Show JSON response
            echo json_encode($response);
        } else {
            // If no data is found
            $response["success"] = 0;
            $response["message"] = "No data on factory found";
 
            // Show JSON response
            echo json_encode($response);
        }
    } else {
        // If no data is found
        $response["success"] = 0;
        $response["message"] = "No data on factory found";
 
        // Show JSON response
        echo json_encode($response);
    }
} else {
    // If required parameter is missing
    $response["success"] = 0;
    $response["message"] = "Parameter(s) are missing. Please check the request";
 
    // echoing JSON response
    echo json_encode($response);
}
?>