
<?php

$db=mysqli_connect("localhost","id22277741_waterscarcity","harini1828@K","id22277741_project1")or die(mysqli_connect_error());

  $query=mysqli_query($db,"SELECT * FROM enviro_monitor") or die(mysqli_error(db));
while($row=mysqli_fetch_array($query))
{
$temperature=$row['temperature'];
$humidity=$row['humidity'];
$air=$row['air'];
}



?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Environment Monitor</title>
    <style>
        body {
            background-image: url('first1.png');
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            display: flex;
            align-items: center;
            justify-content: center; /* Center content horizontally */
            height: 100vh; /* Make the body take full viewport height */
            background-color: #CFCFC4;
            flex-direction: column; /* Align content vertically */
        }
        .container {
            display: flex;
            flex-direction: row;
            align-items: center;
            width: 100%;
        }
        .image-container {
            flex: 1;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .image-container img {
            max-height: 80vh; /* Ensure the image fits within the viewport height */
            max-width: 100%;
        }
        .content {
            flex: 1;
            padding: 20px;
            font-size: 30px;
            background-color: #ffffff; /* Box color */
            border-radius: 10px; /* Rounded corners */
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); /* Shadow for the box */
            margin: 0 auto; /* Center the box horizontally */
            max-width: 400px; /* Set maximum width for better readability */
        }
        .header-text {
            font-size: 24px;
            text-align: center;
            margin-bottom: 20px;
            color:white;
        }
        h3 {
            margin: 10px 0;
        }
    </style>
</head>
<body>
    <div class="header-text">Our actions today determine the world we leave for tomorrow</div>
    <div class="container">
        <div class="content">
            <h3>Temperature:  <?php echo $temperature;?>°C</h3>
            <h3>Humidity: <?php echo $humidity;?>%</h3>
            <h3>Air quality: <?php echo $air;?></h3>
        </div>
    </div>
</body>
</html>












<!--<!DOCTYPE html>-->
<!--<html lang="en">-->
<!--<head>-->
<!--    <meta charset="UTF-8">-->
<!--    <meta name="viewport" content="width=device-width, initial-scale=1.0">-->
<!--    <title>Environment Monitor</title>-->
<!--</head>-->
<!--<body>-->
    
<!--<h3>Temperature: <?php echo $temperature;?></h3>-->
<!--<h3>Humidity : <?php echo $humidity;?></h3>-->
<!--<h3> Air quality : <?php echo $air;?></h3>-->
<!--</body>-->
<!--</html>-->