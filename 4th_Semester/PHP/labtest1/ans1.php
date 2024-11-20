<!DOCTYPE html>
<head>
    <title>ans1</title>
</head>
<body>
    <form action="./ans1.php" method="post">
        <input type="text" name="number1"><br><br>
        <input type="text" name="number2"><br><br>
        <input type="submit" value="submit" name="ans"><br> <br> 
    </form>
<?php
if(isset($_POST["ans"])){
$x = $_POST["number1"];
$y = $_POST["number2"];
function evenNum($x,$y){
    for($i=$x; $i<=$y; $i++){
        if($i%2==0){
            echo $i ,'  ';
        }
    }
}
echo "Output : ";
evenNum($x,$y);
}
?>
</body>
</html>