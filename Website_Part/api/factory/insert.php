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
    if($waterrejected==1)
    {
        $waterrejected="Full";
    }
    else if($waterrejected==0)
    {
        $waterrejected="Not Full";
    }
    $colorrejected = $_GET['colorrejected'];
    if($colorrejected==1)
    {
        $colorrejected="Full";
    }
    else if($colorrejected==0)
    {
        $colorrejected="Not Full";
    }
    $weightrejected = $_GET['weightrejected'];
    if($weightrejected==1)
    {
        $weightrejected="Full";
    }
    else if($weightrejected==0)
    {
        $weightrejected="Not Full";
    }
    $shaperejected = $_GET['shaperejected'];
    if($shaperejected==1)
    {
        $shaperejected="Full";
    }
    else if($shaperejected==0)
    {
        $shaperejected="Not Full";
    }
    $qualified = $_GET['qualified'];
    if($qualified==1)
    {
        $qualified="Full";
    }
    else if($qualified==0)
    {
        $qualified="Not Full";
    }
    $flamedetect = $_GET['flamedetect'];
    if($flamedetect==1)
    {
        $flamedetect="Full";
    }
    else if($flamedetect==0)
    {
        $flamedetect="Not Full";
    }
    $intencontrol = $_GET['intencontrol'];
     if($intencontrol==2)
    {
        $intencontrol="high";
    }
    else if($intencontrol==1)
    {
        $intencontrol="Medium";
    }
    else if($intencontrol==0)
    {
        $intencontrol="Low";
    }
    $tempdetect = $_GET['tempdetect'];
    if($tempdetect==1)
    {
        $tempdetect="high";
    }
    else if($tempdetect==0)
    {
        $tempdetect="Low";
    }
    // Include data base connect class
    $filepath = realpath (dirname(__FILE__));
	require_once($filepath."/db_connect.php");

 
    // Connecting to database 
    $db = new DB_CONNECT();
 
    // Fire SQL query to insert data in EGO Factory
    $result = mysql_query("INSERT INTO factory(alldetect,waterdetect,colordetect,weightdetect,shapedetect,qualifieddetect,waterrejected,colorrejected,weightrejected,shaperejected,qualified,flamedetect,intencontrol,tempdetect) VALUES('$alldetect','$waterdetect','$colordetect','$weightdetect','$shapedetect','$qualifieddetect','$waterrejected','$colorrejected','$weightrejected','$shaperejected','$qualified','$flamedetect' ,'$intencontrol','$tempdetect')");
 
    // Check for succesfull execution of query
    if ($result) {
        // successfully inserted 
        $response["success"] = 1;
        $response["message"] = "Factory Database successfully created.";
 
        // Show JSON response
        echo json_encode($response);
    } else {
        // Failed to insert data in database
        $response["success"] = 0;
        $response["message"] = "Something has been wrong";
 
        // Show JSON response
        echo json_encode($response);
    }
} else {
    // If required parameter is missing
    $response["success"] = 0;
    $response["message"] = "Parameter(s) are missing. Please check the request";
 
    // Show JSON response
    echo json_encode($response);
}
?>