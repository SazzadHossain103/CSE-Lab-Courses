<?php
// Database connection
include("dbConnect.php");


// Add book to database
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $title = $_POST['title'];
    $author = $_POST['author'];

    $filename = $_FILES["fileup"]["name"];
    $tempname = $_FILES["fileup"]["tmp_name"];
    $folder = "image/".$filename;
    move_uploaded_file($tempname, $folder);
    // if(move_uploaded_file($tempname, $folder);)

    $sql = "INSERT INTO books (title, author, filename) VALUES ('$title', '$author', '$folder')";

    if ($conn->query($sql) === TRUE) {
        header("Location: index.php");
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

$conn->close();
?>
