<?php
// Database connection
include("dbConnect.php");


// Fetch books from database
$sql = "SELECT * FROM books";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    while($row = $result->fetch_assoc()) {
        echo '<div class="book-item">';
        echo '<div class="row">';
        echo '<div class="col-2">';
        echo '<img src="'.$row['filename'].'" height="100px" width="100px">';
        echo '</div>';
        echo '<div class="col">';
        echo '<h3>' . $row['title'] . '</h3>';
        echo '<p>Author: ' . $row['author'] . '</p>';
        echo '</div>';
        echo '</div>';
        // echo '<h3>' . $row['title'] . '</h3>';
        // echo '<p>Author: ' . $row['author'] . '</p>';
        echo '<form action="delete_book.php" method="POST">';
        echo '<input type="hidden" name="book_id" value="' . $row['id'] . '">';
        echo '<button type="submit" class="dlt-btn" >Delete</button>';
        echo '<a href="edit.php?id='.$row['id'].'" class="edit-btn" >Edit</a>';
        echo '</form>';
        echo '</div>';
    }
} else {
    echo "0 results";
}
$conn->close();
?>
