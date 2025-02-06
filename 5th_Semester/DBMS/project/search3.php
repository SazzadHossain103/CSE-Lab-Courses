<?php
// Include the database connection
include 'config.php';

// Check if the search term is provided (via AJAX POST request)
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['searchTerm'])) {
    // Get the search term and sanitize input
    $searchTerm = trim($_POST['searchTerm']);
    
    // Prepare the SQL statement to search for books
    $sql = "SELECT * FROM `book_info` WHERE name LIKE '%{$searchTerm}%' OR title LIKE '%{$searchTerm}%' OR category LIKE '%{$searchTerm}%' ";
    $stmt = mysqli_query($conn, $sql);

    // Bind parameters and execute the statement
    // $searchParam = "%" . $searchTerm . "%";
    // $stmt->bind_param("ss", $searchParam, $searchParam);
    // $stmt->execute();

    // Get the result set
    // $result = $stmt->get_result();

    // Display search results
    if (mysqli_num_rows($stmt) > 0) {
        while ($row = $stmt->fetch_assoc()) {
            echo '<div class="search-item row w-100">';
              echo '<div class="col-2 ps-3">';
                    echo '<img src="added_books/' . $row['image'] . '"  width="50px">';
              echo '</div>';
              echo '<div class="col-6 pt-1">';
                echo '<h4>' . htmlspecialchars($row['name']) . '</h4>';
                echo '<p>Author: ' . htmlspecialchars($row['title']) . '</p>';
              echo '</div>';
              echo '<div class="col-4 d-flex justify-content-between align-items-center">';
                // echo '<form action="delete_book.php" method="POST" class="inline-form">';
                // echo '<input type="hidden" name="book_id" value="' . htmlspecialchars($row['book_id']) . '">';
                // echo '<button type="submit" class="dlt-btn">Delete</button>';
                // echo '</form>';
                echo '<p class="pt-3">TK. ' . htmlspecialchars($row['price']) . '</p>';
                echo '<a href="book_details.php?details=' . htmlspecialchars($row['bid']) . '" class="btn btn-primary">Buy Now</a>';
              echo '</div>';
            echo '</div>';
        }
    } else {
        echo '<p>No results found.</p>';
    }

    // Close statement and connection
    $stmt->close();
    $conn->close();
}
?>
