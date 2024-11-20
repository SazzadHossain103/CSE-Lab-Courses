<!DOCTYPE html>
<head>
    <title>ans3</title>
</head>
<body>
    <form action="./ans3.php" method="post">
        <input type="text" name="number1"><br><br>
        <input type="text" name="number2"><br><br>
        <input type="submit" value="submit" name="ans"><br> <br> 
    </form>
<?php
if(isset($_POST["ans"])){
$x = $_POST["number1"];
$y = $_POST["number2"];
function prime($x,$y){
    for($i=$x; $i<=$y; $i++){
        $f=0;
        for($j=2; $j<$i; $j++){
            if($i%$j==0){$f=1;break;}
        }
        if($f==0)echo "{$i} ";
    }
}
echo "Output : ";
prime($x,$y);
}
?>
</body>
</html>