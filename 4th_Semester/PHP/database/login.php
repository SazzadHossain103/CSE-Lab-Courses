<?php
include("dbConnect.php");


if(isset($_POST["ans"])){


    $email = $_POST["email"];
    $password = $_POST["password"];
   
    $sql = "select * from signup where email='$email' and password='$password' ";


    $res = mysqli_query($conn, $sql);
    $count = mysqli_num_rows($res);


    if($res==1){
        // include("welcome.php");
        header("location:welcome.php");
    }
    else {
        echo"not connect";
    }
    mysqli_close($conn);
}


?>
