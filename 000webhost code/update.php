<?php

$temperature=$_GET['temperature'];
$humidity=$_GET['humidity'];
$air=$_GET['air'];


$db=mysqli_connect("localhost","id22277741_waterscarcity","harini1828@K","id22277741_project1")or die(mysqli_connect_error());

  $query=mysqli_query($db,"UPDATE `enviro_monitor` SET `temperature`=$temperature,`humidity`=$humidity,`air`=$air WHERE 1") or die(mysqli_error(db));



?>