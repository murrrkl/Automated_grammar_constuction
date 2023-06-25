<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
        <a class = "menu" href="special.php" style="margin-left: 30px;">Меню специалиста</a>
    </div>
</header>

<style>

    * {

        margin: 0;
        padding:0;
    }

    .header{
        background-color:rgba(255, 255, 255, 0.7);
        padding: 1.3em 1em; /* поля вокруг текста */


    }

    .menu {
        text-transform: uppercase;
        padding: 0.5em 1em;
        color: gray;
        text-decoration: none;
        transition: 0.3s;
        letter-spacing: 2px;
    }
    .menu:hover {
        color: purple;
        cursor: pointer;
    }
</style>

<?php

$username = 'root';
$pass = '12345678K';
$db = 'Situations';

try {
    // подключаемся к серверу
    $conn = new PDO("mysql:host=localhost; charset=utf8; dbname=$db", $username, $pass);
    //echo "Database connection established";
}
catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$res = $conn->query("SELECT description FROM Unrecognized");

echo "<div style='display: flex; justify-content: center;'> <div style=' text-align: left; background-color: white; width: 800px; margin-top: 40px; border-radius: 30px; '><table id = 'database'><tr><th> Описание ситуации </th><th></th></tr>";
foreach($res as $row){
    echo "<tr>";
    echo "<td class = 'description'>" . $row["description"] . "</td>";
    echo "<td><form action='Unrecognized.php' method='post'>
                        <input type='hidden' name='description' value='" . $row["description"] . "' />
                        <input type='submit' class='btn' value='Удалить'>
                    </form></td>";
    echo "</tr>";
}
echo "</table> </div> </div>";

if(isset($_POST["description"]))
{
    try {
        $sql = "DELETE FROM Unrecognized WHERE description = :user_description";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":user_description", $_POST["description"]);

        $stmt->execute();
        header("Location: Unrecognized.php");
    }
    catch (PDOException $e) {
        echo "Database error: " . $e->getMessage();
    }
}
?>




<style>
    * {
        box-sizing: border-box;
    }

    @font-face {
        font-family: "Evolventa-Regular";
        src: url(fonts/Evolventa-Regular.otf);
    }

    body {
        background-color: Lavender;
        font-family: "Evolventa-Regular";
    }

    .btn {
        margin-left: 20px;
        width: 150px;
        height: 40px;
        background-color: Lavender;
        justify-content: center;
        align-items: center;
        transition: 0.3s;
        text-decoration: none;
        display: inline-block;
        border-radius: 45px;
        padding:5px 2px;
        text-align: center;
        letter-spacing: 2px;
        border: none;
        color: black;
    }

    td {
        vertical-align: top;
        padding-top: 30px;
    }


    .btn:hover {
        box-shadow: 0 15px 20px rgba(59, 0, 105, .4);
        cursor: pointer;
    }

    #database {
        padding: 30px;
        margin: auto;
        text-align: left;
    }


    .name {
        width: 150px;
    }

    .description {
        width: 400px;
        height: 200px;

    }

</style>


