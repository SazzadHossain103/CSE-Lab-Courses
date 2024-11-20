<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Upload</title>
    <!--Bootstap Latest compiled and minified CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <form action="" method="POST" enctype="multipart/form-data">
        <input type="file" name="fileup">
        <input type="submit" name="ans" value="submit">
    </form>

<?php
// Database connection
include("dbConnect.php");

if(isset($_POST["ans"])) {
    $filename = $_FILES["fileup"]["name"];
    $tempname = $_FILES["fileup"]["tmp_name"];
    $folder = "image/".$filename;

    // Move uploaded file to destination folder
    if (move_uploaded_file($tempname, $folder)) {
        // Insert file path into database
        $sql1 = "INSERT INTO fileup (filename) VALUES ('$folder')";
        $res = $conn->query($sql1);

        if ($res === TRUE) {
            // Retrieve and display uploaded images
            $sql = "SELECT * FROM fileup"; 
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                // Output data of each row
                while($row = $result->fetch_assoc()) {
                    
                    echo '<div class="row">';
                    echo '<div class="col">';
                    echo '<img src="'.$row['filename'].'" height="100px" width="100px">';
                    echo '</div>';
                    echo '<div class="col">';
                    echo '<p>Name : </p>';
                    echo '</div>';
                    echo '</div>';
                }
            } else {
                echo "0 results";
            }
        } else {
            echo "Error: " . $sql1 . "<br>" . $conn->error;
        }
    } else {
        echo "Sorry, there was an error uploading your file.";
    }
}
$conn->close();
?>



<!--Bootstap Latest compiled JavaScript -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>


