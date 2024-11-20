<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>lab5.php database connection</title>

    <!--Bootstap Latest compiled and minified CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">

</head>
<!-- http://localhost:8080/SazzadPHP/lab5/ -->
<body class="d-flex flex-column justify-content-center align-items-center h-100">
    <h1>Loging page</h1>
    <!-- <form action="./login.php" method="post" >
        <label for="email">Email: </label><br>
        <input type="email" name="email" id="email" ><br><br>
        <label for="password">Password: </label><br>
        <input type="password" name="password" id="password"><br><br>
        <input type="submit" value="Login" name="ans">
    </form> -->
    <form action="./signup.php" method="post" >
        <div class="mb-3">
            <label for="studentId">Student Id : </label>
            <input type="text" name="studentId" id="studentid">
        </div>
        <div class="mb-3">
            <label for="username">Username : </label>
            <input type="text" name="username" id="studentid">
        </div>
        <label for="email">Email: </label>
        <input type="email" name="email" id="email" ><br><br>
        <label for="password">Password: </label>
        <input type="password" name="password" id="password"><br><br>
        <div class="mb-3">
            <label for="confirmpassword">Confirm password : </label>
            <input type="password" name="confirmpassword" id="confirmpassword">
        </div>
        <input type="submit" value="Singup" name="ans">
    </form>





    <!--Bootstap Latest compiled JavaScript -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>

</body>
</html>
