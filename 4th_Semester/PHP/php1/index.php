<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Basic php</title>
</head>
<!-- http://localhost/PHP/php1/index.php -->

<body>

    <form action="index.php" method="post">
        <label for="x">x : </label>
        <input type="number" name="x"><br>
        <label for="y">y : </label>
        <input type="number" name="y"><br><br>

        <input type="submit" value="Submit" name="ans" ><br><br>
    </form>
    
</body>
</html>


<?php 
// echo "hello Sazzad";

//  varibale and data type
$string = "sazzad";
$number = 21;
$bool = true;

// oparators ( + , - , *, /, **, % )
if(isset($_POST["ans"])){
    $x = $_POST["x"];
    $y = $_POST["y"];
    $total = $x ** $y;
    echo"Ans = {$total} <br> ";
}


$foods = array("apple", "mango", "banana");
array_push($foods, "orange");
// array_pop($foods);
// array_shift($foods); //first value delete
// echo count($foods);
// $foods = array_reverse($foods);

foreach($foods as $prt){
    echo " {$prt} <br> ";
}

$country = array("Bangladesh"=>"Dhaka", "japan"=>"kyoto", "india"=>"delhi");  //key => value

foreach($country as $key => $value){
    echo "{$key} = {$value} <br> ";
}

?>