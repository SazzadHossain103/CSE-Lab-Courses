<!DOCTYPE html>
<head>
    <title>ans2</title>
</head>
<body>
    <form action="./ans2.php" method="post">
        <input type="text" name="number1"><br><br>
        <input type="submit" value="submit" name="ans"><br> <br> 
    </form>
<?php
if(isset($_POST["ans"])){
$x = $_POST["number1"];
function pattern($x){
    for($i=1; $i<=$x; $i++){
        for($j=1; $j<=$i; $j++){
            echo "{$i} ";
        }
        echo "<br>";
    }
}
echo "Output : <br>";
pattern($x);
}
?>
</body>
</html>