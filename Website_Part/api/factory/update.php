<?php


header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");

//Creating Array for JSON response
$response = array();
 
// Check if we got the field from the user
if (isset($_GET['alldetect']) && isset($_GET['waterdetect']) && isset($_GET['colordetect']) && isset($_GET['weightdetect']) && isset($_GET['shapedetect']) && isset($_GET['qualifieddetect'])  && isset($_GET['waterrejected'])  && isset($_GET['colorrejected'])&& isset($_GET['weightrejected']) && isset($_GET['shaperejected']) && isset($_GET['qualified']) && isset($_GET['flamedetect'])&& isset($_GET['intencontrol'])  && isset($_GET['tempdetect'])  ) {

    $alldetect = $_GET['alldetect'];
    $waterdetect = $_GET['waterdetect'];
    $colordetect = $_GET['colordetect'];
    $weightdetect = $_GET['weightdetect'];
    $shapedetect = $_GET['shapedetect'];
    $qualifieddetect = $_GET['qualifieddetect'];
    $waterrejected = $_GET['waterrejected'];
    $colorrejected = $_GET['colorrejected'];
    $weightrejected = $_GET['weightrejected'];
    $shaperejected = $_GET['shaperejected'];
    $qualified = $_GET['qualified'];
    $flamedetect = $_GET['flamedetect'];
    $intencontrol = $_GET['intencontrol'];
    $tempdetect = $_GET['tempdetect'];

    
 
    // Include data base connect class
	$filepath = realpath (dirname(__FILE__));
	require_once($filepath."/db_connect.php");

	// Connecting to database
    $db = new DB_CONNECT();
 
	// Fire SQL query to update factory data by id
    $result = mysql_query("UPDATE factory SET alldetect= '$alldetect',waterdetect= '$waterdetect' ,colordetect= '$colordetect' ,weightdetect= '$weightdetect' ,shapedetect= '$shapedetect' ,qualifieddetect= '$qualifieddetect' ,waterrejected= '$waterrejected' ,colorrejected= '$colorrejected' ,weightrejected= '$weightrejected' ,shaperejected= '$shaperejected' ,qualified= '$qualified' ,flamedetect= '$flamedetect' ,intencontrol= '$intencontrol' ,tempdetect= '$tempdetect'  WHERE id = '$id'");
 
    // Check for succesfull execution of query and no results found
    if ($result) {
        // successfully updation of Data 
        $response["success"] = 1;
        $response["message"] = "Factory Data successfully updated.";
 
        // Show JSON response
        echo json_encode($response);
    } else {
 
    }
} else {
    // If required parameter is missing
    $response["success"] = 0;
    $response["message"] = "Parameter(s) are missing. Please check the request";
 
    // Show JSON response
    echo json_encode($response);
}
?>