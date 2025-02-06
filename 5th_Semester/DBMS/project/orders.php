<?php

include 'config.php';
session_start();

$user_id = $_SESSION['user_id'];

if(!isset($user_id)){
   header('location:login.php');
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Orders</title>

   <!-- font awesome cdn link  -->
   <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
   <link rel="stylesheet" href="./css/hello.css">

<style>
    .placed-orders .title{
  text-align: center;
  margin-bottom: 20px;
  text-transform: uppercase;
  color:black;
  font-size: 40px;
}
   .placed-orders .box-container{
  max-width: 1200px;
  margin:0 auto;
  display:flex;
  flex-wrap: wrap;
  align-items: center;
  gap:20px;
}

.placed-orders .box-container .empty{
  flex:1;
}

.placed-orders .box-container .box{
  flex:1 1 400px;
  border-radius: .5rem;
  padding:15px;
  border:2px solid brown;
  background-color: white;
  padding:10px 20px;
}

.placed-orders .box-container .box p{
  padding:10px 0 0 0;
  font-size: 20px;
  color:gray;
}

.placed-orders .box-container .box p span{
  color:black;
}

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
.placed-orders{
        display: flex;
        justify-content: center;
    }
    .title{
         text-align: center;
      }
</style>

</head>
<body>
   
<?php include 'index_header.php'; ?>
<h1 class="title">placed orders</h1>
<section class="placed-orders">
   <table>
      <thead>
         <th>Order Id</th>
         <th>Order Date</th>
         <th>Name</th>
         <th>Mobile Number</th>
         <th>Email Id</th>
         <th>Address</th>
         <th>Payment Method</th>
         <th>Your orders</th>
         <th>Total price</th>
         <th>Payment status</th>
         <th>Print Recipt</th>

      </thead>
      <tbody>
      <?php
        $select_book = mysqli_query($conn, "SELECT * FROM `confirm_order`WHERE user_id = '$user_id' ORDER BY order_date DESC") or die('query failed');
        if(mysqli_num_rows($select_book) > 0){
            while($fetch_book = mysqli_fetch_assoc($select_book)){
      ?>
         <tr>
            <td><?php echo $fetch_book['order_id']; ?></td>
            <td><?php echo $fetch_book['order_date']; ?></td>
            <td><?php echo $fetch_book['name']; ?></td>
            <td><?php echo $fetch_book['number']; ?></td>
            <td><?php echo $fetch_book['email']; ?></td>
            <td><?php echo $fetch_book['address']; ?></td>
            <td><?php echo $fetch_book['payment_method']; ?></td>
            <td><?php echo $fetch_book['total_books']; ?></td>
            <td>Tk <?php echo $fetch_book['total_price']; ?>/-</td>
            <td><span style="color:<?php if($fetch_book['payment_status'] == 'pending'){ echo 'orange'; }else{ echo 'green'; } ?>;"><?php echo $fetch_book['payment_status']; ?></span> </td>
            <td><a href="invoice.php?order_id=<?php echo $fetch_book['order_id']; ?>" target="_blank">Print Recipt</a></td>
         </tr>
         <?php
       }
      }else{
         echo '<p class="empty">You have not placed any order yet!!!!</p>';
      }
      ?>
      </tbody>
   </table>

   

</section>








<?php include 'index_footer.php'; ?>

<!-- custom js file link  -->
<script src="js/script.js"></script>

</body>
</html>