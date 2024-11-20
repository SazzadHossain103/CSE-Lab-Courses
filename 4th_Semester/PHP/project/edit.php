<?php

// Database connection
include("dbConnect.php");

$id = $_GET['id'];

// Fetch books from database
$sql = "SELECT * FROM books where id={$id}";
$result = $conn->query($sql);
$row = mysqli_fetch_assoc($result);

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Books Library</title>
    <!--Bootstap Latest compiled and minified CSS -->
    <!-- <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"> -->
    <!-- <link rel="stylesheet" href="styles.css"> -->
</head>
<body>
    <div class="container">
        <h1 class="hdline">Books Library</h1>
        <form action="#" method="POST" class="mb-3" enctype="multipart/form-data">
            <input type="text" name="title" value="<?php echo $row['title']  ?>" placeholder="Enter book title" required>
            <input type="text" name="author" value="<?php echo $row['author']  ?>" placeholder="Enter author" required>
            <button type="submit">Edit Book</button>
        </form>
        <div class="book-list">
            <h2 class="text-center mb-3 ">All Books </h2>
            <!-- Book list will be displayed here -->
            <?php include 'display_books.php'; ?>
        </div>
    </div>

    <!--Bootstap Latest compiled JavaScript -->
<!-- <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script> -->
</body>
</html>

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
        header("Location: admin.php");
    } else {
        echo "Error: " . $sql2 . "<br>" . $conn->error;
    }
}

$conn->close();
?>