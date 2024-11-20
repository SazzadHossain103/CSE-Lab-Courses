<!DOCTYPE html>
<head>
    <title>ans4</title>
</head>
<body>
    <form action="./ans4.php" method="post">
        <span>num1 </span><input type="text" name="number1"><br> <br>
        <span>num2 </span><input type="text" name="number2"><br> <br>
        <span>result </span><input type="text" name="result" value="
       
<?php
$x = $_POST["number1"];
$y = $_POST["number2"];
$a = $_POST["ans"];
function add($x,$y){
    echo $x+$y ,' ';
}
function mul($x,$y){
    echo $x*$y ,' ';
}
function sub($x,$y){
    echo $x-$y ,' ';
}
function div($x,$y){
    echo $x/$y ,' ';
}

if($a=='add'){
    add($x,$y);
}
if($a=='sub'){
    sub($x,$y);
}
if($a=='mul'){
    mul($x,$y);
}
if($a=='div'){
    div($x,$y);
}
?>
        "> <br><br>
        <input type="submit" value="add" name="ans">
        <input type="submit" value="sub" name="ans">
        <input type="submit" value="mul" name="ans">
        <input type="submit" value="div" name="ans">
    </form>
</body>
</html>
