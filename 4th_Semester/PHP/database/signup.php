<?php
include("dbConnect.php");


if(isset($_POST["ans"])){


    $email = $_POST["email"];
    $password = $_POST["password"];
    $username = $_POST["username"];
    $studentId = $_POST["studentId"];
    $confirmpassword = $_POST["confirmpassword"];
   
    // $sql = "INSERT INTO signup (studentId ,  username , email , password ) VALUES ('$studentId','$username',  '$email', '$password') ";

    if($password == $confirmpassword){
        $sql = "INSERT INTO signup (studentId ,  username , email , password ) VALUES ('$studentId','$username',  '$email', '$password') ";

        try{
            mysqli_query($conn, $sql);
            header("location:welcome.php");
        }
        catch(mysqli_sql_exception){
            echo"not connect";
        }
    }
    else echo"not connect";


    // $res = mysqli_query($conn, $sql);
    // $count = mysqli_num_rows($res);

    

    // if($count){
        // include("welcome.php");
    //     header("location:welcome.php");
    // }
    // else{
    //     alert ("login failed");
    // }

    mysqli_close($conn);
}


?>