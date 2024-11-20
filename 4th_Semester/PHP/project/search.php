<?php
// Database connection
include("dbConnect.php");

// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get the search term from the form
    $searchTerm = $_POST['searchTerm'];

    // Prepare the SQL statement to search for books
    $sql = "SELECT * FROM books WHERE title LIKE ? OR author LIKE ?";
    $stmt = $conn->prepare($sql);

    // Bind parameters and execute the statement
    $searchParam = "%" . $searchTerm . "%";
    $stmt->bind_param("ss", $searchParam, $searchParam);
    $stmt->execute();

    // Get the result set
    $result = $stmt->get_result();

    // Display search results
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo '<div class="book-item">';
            echo '<h3>' . $row['title'] . '</h3>';
            echo '<p>Author: ' . $row['author'] . '</p>';
            echo '<form action="delete_book.php" method="POST">';
            echo '<input type="hidden" name="book_id" value="' . $row['id'] . '">';
            echo '<button type="submit" class="dlt-btn" >Delete</button>';
            echo '<a href="edit.php?id='.$row['id'].'" class="edit-btn" >Edit</a>';
            echo '</form>';
            echo '</div>';
        }
    } else {
        echo "No results found.";
    }

    // Close statement and connection
    $stmt->close();
    $conn->close();
}
?>