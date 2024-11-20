<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Book Library</title>
    <!--Bootstap Latest compiled and minified CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">

    <link rel="stylesheet" href="styles.css">
</head>

<body>
    <div class="container-fluid">
        <!-- <h2>Book Search</h2> -->

        <h1 class="hdline">Books Library</h1>
        <hr>
        <div class="row">
            <div class="col-3 p-4 pt-5">

                <form action="add_book.php" method="POST" class="mb-3" enctype="multipart/form-data">
                    <h2>Add New Book</h2>
                    <input type="text" name="title" placeholder="Enter book title" required>
                    <input type="text" name="author" placeholder="Enter author" required>
                    <input type="file" name="fileup" required>
                    <button type="submit">Add Book</button>
                </form>
            </div>
            <div class="col ps-3 pe-3">
                <div class="book-list">
                    <h2 class="text-center mb-3 ">All Books </h2>
                    <!-- Book list will be displayed here -->
                    <?php include 'display_books.php'; ?>
                </div>
            </div>
            <div class="col-3 p-4 pt-5">
                <form action="" method="POST" class="mb-3">
                    <!-- <label for="searchTerm">Search for books:</label> -->
                    <input type="text" id="searchTerm" name="searchTerm" placeholder="Search books" required>
                    <button type="submit">Search</button>
                </form>
                <?php
                include("search.php");
                ?>
            </div>
        </div>



    </div>

    <!--Bootstap Latest compiled JavaScript -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>

</html>