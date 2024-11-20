<!DOCTYPE html>
<head>
    <title>ans5</title>
</head>
<body>
    <form action="./ans5.php" method="post">
    <input type="text" name="number1"><br><br>
        <input type="submit" value="submit" name="ans"><br> <br> 
    </form>
</body>
</html>

<?php
if(isset($_POST["ans"])){
echo "Output : ";
$x = $_POST["number1"];
if($x==61)echo"Brasilia";
else if($x==71)echo"Salvador";
else if($x==11)echo"Sao Paulo";
else if($x==21)echo"Rio de Janeiro";
else if($x==32)echo"Juiz de Fora";
else if($x==19)echo"Campinas";
else if($x==27)echo"Vitoria";
else if($x==31)echo"Belo Horizonte";
}
?>
