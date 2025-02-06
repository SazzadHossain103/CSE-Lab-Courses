<!DOCTYPE html>
<html lang="en">
<link rel="stylesheet" href="./css/hello.css">
<style>
  
  .sub-menu-wrap {
    position: fixed;
    top: 6%;
    right: -1%;
    width: 320px;
    max-height: 0px;
    overflow: hidden;
    transition: max-height 0.5s;
    z-index: 100;

  }

  .sub-menu-wrap.open-menu {
    max-height: 400px;
  }

  .sub-menu {
    background: #fff;
    padding: 20px;
    margin: 10px;
    border-bottom-right-radius: 16px;
    border-bottom-left-radius: 16px;
  }

  .user-info {
    display: flex;
    align-items: center;
  }

  .user-info h3 {
    font-weight: 500;
  }

  .user-info img {
    width: 60px;
    border-radius: 50%;
    margin-right: 15px;
  }

  .sub-menu hr {
    border: 0;
    height: 1px;
    width: 100%;
    background: #ccc;
    margin: 15px 10px;
  }

  .sub-menu-link {
    display: flex;
    align-items: center;
    text-decoration: none;
    color: #525252;
    margin: 12px e;
  }

  .sub-menu-link p {
    width: 100%;
  }

  .sub-menu-link img {
    width: 40px;
    background: #e5e5e5;
    border-radius: 50%;
    padding: 8px;
    margin-right: 15px;
  }

  .sub-menu-link span {
    font-size: 22px;
    transition: transform 0.5s;
  }

  .sub-menu-link:hover span {
    transform: translateX(5px);
  }

  .sub-menu-link:hover p {
    font-weight: 600;
  }

  .link_btn {
    background-color: brown;
    padding: 6px;
    border-radius: 10px;
    margin-left: 10px;
    color: white;
    font-weight: 500;
  }

  .logo a{
    color: white !important;
    font-size: 35px;
    font-weight: bold;
  }
  

    /* Sub-navbar styles for the search bar */
  .sub-navbar {
    background-color: #444;
    padding: 10px 20px;
    position: sticky;
    top: 70px !important;
    z-index: 10;
  }
  
  .search-form {
    display: flex;
    justify-content: center;
    align-items: center;
  }
  
  .search-input {
    padding: 10px;
    font-size: 16px;
    border-radius: 5px;
    width: 400px;
    border: 1px solid #ccc;
  }
  
  .search-btn {
    padding: 10px 20px;
    font-size: 16px;
    background-color: #007bff;
    color: white;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    margin-left: 10px;
  }
  
  .search-btn:hover {
    background-color: #0056b3;
  }


  .search-input {
      width: 400px;
    }

    .search-container{
      position: absolute;
      width: 100%;
      display: flex;
      justify-content: center;
    }
    .search-content {
      /* position: absolute; */
      margin-top: 10px;
      border: 1px solid #ccc;
      background-color: #fff;
      max-height: 500px;
      width: 700px;
      overflow-y: auto;
      display: none;
      z-index: 100;
      /* Initially hidden */
    }
    .search-content .search-item{
      display: flex;
      /* width: 500px; */
    }
    header {
    background: #333 !important;
    /* padding: 10px 20px; */
  }
  .nav a, .nav button{
    color: white !important;
    font-size: 20px;
    font-weight: 300;
  }
  .nav a:hover,.nav .dropdown button:hover{
    color: #007bff !important;
  }
  .nav .dropdown-content a{
    color: #333 !important;
  }
  
  /* .sub-menu-wrap{
    z-index: 100;
    top: 70;
  } */
   .dropbtn{
    background: none;
   }
</style>

<body>
  <header>
    <div class="logo">
      <a href="index.php">BookNest</a>
    </div>
    <div class="nav">
      <a href="index.php">Home</a>
      <div class="dropdown">
        <button class="dropbtn">Category </button>
        <!-- <a href="" class="">Category </a> -->
        <div class="dropdown-content">
          <a href="index.php#New">New Arrived</a>
          <a href="index.php#Adventure">Adventure</a>
          <a href="index.php#Magical">Magic</a>
          <a href="index.php#Knowledge">Knowledge</a>

        </div>
      </div>
      <a href="contact-us.php">Contact US</a>
      <a href="cart.php">Cart</a>
      <a href="orders.php">Orders</a>
    </div>
    <div class="user-box" style="display: flex; align-items:center;">
      <!-- <a class="Btn" href="search_books.php"><img style="height:30px;" src="./images/sea2.png" alt=""></a> -->
      <?php if (isset($_SESSION['user_name'])) {
        echo ' <img style="height:40px; margin-left:10px ;" src="images/ds2.png" class="user-pic" onclick="toggleMenu()" />';
      } else {
        echo '<div class="use_links"><a class="link_Btn" style="background-color: #007bff;
        padding: 6px 15px;
        border-radius: 6px 15px;
        margin-left: 10px;
        color: white;
        font-weight: 500;" href="login.php">Login</a>
        <a class="link_Btn" style="background-color: #007bff;
        padding: 6px 15px;
        border-radius: 6px 15px;
        margin-left: 10px;
        color: white;
        font-weight: 500;" href="register.php">Register</a></div>';
      } ?>
    </div>

  </header>
  <div class="sub-menu-wrap" id="subMenu">
    <div class="sub-menu">
      <div class="user-info">
        <img src="images/ds2.png" />
        <div class="user-info" style="display: block;">
          <h3>Hello, <?php echo $_SESSION['user_name'] ?></h3>
          <h6><?php echo $_SESSION['user_email'] ?></h6>
        </div>
      </div>
      <hr />
      <a href="cart.php" class="sub-menu-link">
        <p>Cart</p>
        <span>></span>
      </a>
      <a href="contact-us.php" class="sub-menu-link">
        <p>Contact Us</p>
        <span>></span>
      </a>
      <a href="orders.php" class="sub-menu-link">
        <p>Order history</p>
        <span>></span>
      </a>
      <a href="logout.php" class="sub-menu-link">
        <p style="background-color: red; border-radius:8px; text-align:center; color:white; font-weight:600; margin-top:5px; padding:5px;">Logout</p>
      </a>
    </div>
  </div>

  <div class="sub-navbar">
    <form action="#" method="POST" class="search-form" onsubmit="return false" ;>
      <input type="text" id="searchTerm" name="searchTerm" placeholder="Search for books..." class="search-input" onkeyup="performSearch()" />
      <button type="submit" class="search-btn">Search</button>
    </form>
    <div class="search-container">
      <div id="search-results" class="search-content"></div>
    </div>
  </div>

  <script>
    function performSearch(searchTerm = null) {
      const inputField = document.getElementById("searchTerm");
      const resultsContainer = document.getElementById("search-results");

      // Use the provided searchTerm (from button click) or get it from the input field
      const term = searchTerm !== null ? searchTerm : inputField.value.trim();

      if (term === "") {
        resultsContainer.style.display = "none"; // Hide results if input is empty
        resultsContainer.innerHTML = "";
        return;
      }

      // AJAX request to perform the search
      const xhr = new XMLHttpRequest();
      xhr.open("POST", "search3.php", true);
      xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
      xhr.onreadystatechange = function() {
        if (xhr.readyState === 4 && xhr.status === 200) {
          resultsContainer.innerHTML = xhr.responseText;
          resultsContainer.style.display = "block"; // Show results
        }
      };
      xhr.send("searchTerm=" + encodeURIComponent(term));
    }

    // Hide the search results when clicking outside
    document.addEventListener("click", function(event) {
      const resultsContainer = document.getElementById("search-results");
      const searchInput = document.getElementById("searchTerm");

      // Check if the click is outside the search input or results container
      if (
        resultsContainer.style.display === "block" &&
        !resultsContainer.contains(event.target) &&
        event.target !== searchInput
      ) {
        resultsContainer.style.display = "none"; // Hide results
      }
    });

    // Handle form submission to make the "Search" button work
    document.querySelector(".search-form").addEventListener("submit", function(event) {
      event.preventDefault(); // Prevent the default form submission
      const searchTerm = document.getElementById("searchTerm").value.trim();
      performSearch(searchTerm);
    });
  </script>

  <script>
    let subMenu = document.getElementById("subMenu");

    function toggleMenu() {
      subMenu.classList.toggle("open-menu");
    }
  </script>
</body>

</html>