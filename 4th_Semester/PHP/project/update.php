
<?php
// Database connection
include("dbConnect.php");
// Edit book to database
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $title = $_POST['title'];
    $author = $_POST['author'];

    $sql2 = "UPDATE books SET  title='$title', author='$author' WHERE id=$id";
    $res = mysqli_query($conn,$sql2);
    if ($res) {
        header("Location: index.php");
    } else {
        echo "Error: " . $sql2 . "<br>" . $conn->error;
    }
}

$conn->close();
?>