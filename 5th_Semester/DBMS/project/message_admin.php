<?php
include 'config.php';

session_start();

$admin_id = $_SESSION['admin_id'];

if(!isset($admin_id)){
    header('location:admin_login.php');
 };


if (isset($_GET['delete_msg'])) {
    $msg_id = $_GET['delete_msg'];
    mysqli_query($conn, "DELETE FROM `msg` WHERE id = '$msg_id'") or die('query failed');
    header('location:message_admin.php');
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/register.css">
    <link rel="stylesheet" href="./css/index_book.css">
    <title>Messages</title>

    <style>
        table {
    width: 80%;
    border-collapse: collapse;
    margin: 20px 0;
    font-size: 18px;
    text-align: left;
}

th, td {
    padding: 12px;
    border: 1px solid #ddd;
}

th {
    background-color: #f2f2f2;
    color: #333;
}

tr:hover {
    background-color: #f5f5f5;
}
.show-products{
        display: flex;
        justify-content: center;
    }
    </style>
</head>

<body>
    <?php
    include 'admin_header.php';
    ?>
    <section class="show-products">
        <table>
            <thead>
                <th>Message ID</th>
                <th>Name</th>
                <th>Email ID</th>
                <th>Number</th>
                <th>Message</th>
                <th>Date</th>
                <th>Delete</th>
            </thead>
            <tbody>
            <?php
            $select_user = mysqli_query($conn, "SELECT id,name,email,number,msg,date FROM msg") or die('query failed');
            if (mysqli_num_rows($select_user) > 0) {
                while ($fetch_user = mysqli_fetch_assoc($select_user)) {
            ?>
                <tr>
                    <td><?php echo $fetch_user['id']; ?></td>
                    <td><?php echo $fetch_user['name']; ?></td>
                    <td><?php echo $fetch_user['email']; ?></td>
                    <td><?php echo $fetch_user['number']; ?></td>
                    <td><?php echo wordwrap($fetch_user['msg'], 30, "<br>\n", TRUE); ?></td>
                    <td><?php echo $fetch_user['date']; ?></td>
                    <td><a href="message_admin.php?delete_msg=<?php echo $fetch_user['id']; ?>" onclick="return confirm('delete this message?');">Delete</a></td>
                </tr>
                <?php
                }
            } else {
                echo '<p class="empty">No any message recived yet!</p>';
            }
            ?>
            </tbody>
        </table>
        
    </section>
</body>

</html>