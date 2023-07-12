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

$res = $conn->query("SELECT name, description FROM mySituations");

echo "<div style='display: flex; justify-content: center;'> <div style=' text-align: left; background-color: white; width: 800px; margin-top: 40px; border-radius: 30px; '><table id = 'database'><tr><th>Название </th><th> Обоснование </th><th></th></tr>";
foreach($res as $row){
    echo "<tr>";
    echo "<td class = 'name'>" . $row["name"] . "</td>";
    echo "<td class = 'description'>" . $row["description"] . "</td>";
    echo "<td><form action='SituationsReview.php' method='post'>
                        <input type='hidden' name='name' value='" . $row["name"] . "' />
                        <input type='submit' class='btn' value='Удалить'>
                    </form></td>";
    echo "</tr>";
}
echo "</table> </div> </div>";

if(isset($_POST["name"]))
{


        $sql = "DELETE FROM mySituations WHERE name = :username";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":username", $_POST["name"]);
        $stmt->execute();

        // Удаление грамматики с данным названием и информации о ней
        $name = $_POST['name'];

        $grammaFile =  __DIR__ . '/tomita/' . $name. ".cxx";
        unlink($grammaFile); // Удаление грамматики
        $grammabin =  __DIR__ . '/tomita/' . $name. ".bin";
        unlink($grammabin); // Удаление бинарного файла грамматики
        $gzt =  __DIR__ . '/tomita/mydic.gzt.bin';
        unlink($gzt); // Удаление бинарного  файла корневого словаря

        $sql = "SELECT COUNT(*) FROM mySituations WHERE name != ''";
        $res = $conn->query($sql);
        $count = $res->fetchColumn();

        for ($i = 1; $i <= $count; $i++) {
            array_map('unlink', glob("tomita/*.bin"));
        }


        // Удаление информации из конфигурационного файла
        $configFile =  __DIR__ . "/tomita/config.proto";
        $current = file_get_contents($configFile);

        $currentx = "\n\nArticles = [\n";
        $currentx .= '  { Name = "' . $name . '" }';
        $currentx .= "\n]\n\n";
        $currentx .= "Facts = [\n";
        $currentx .= '  { Name = "' . $name . '" }';
        $currentx .= "\n]";

        $current = str_replace($currentx, "", $current); // Удаление фрагмента

        file_put_contents($configFile, $current); // Вносим полученные данные в конфигурационный файл
        header("Location: SituationsReview.php");

        // Удаление информации из корневого словаря
        $factsFile =  __DIR__ . "/tomita/mydic.gzt";

        $current = file_get_contents($factsFile);
        $currentx = "\n";
        $currentx .= 'TAuxDicArticle "' . $name . '"';
        $currentx .= "\n{\n";
        $currentx .= '    key = { "tomita:' . $name . '.cxx" type=CUSTOM }';
        $currentx .= "\n}\n";

        $current = str_replace($currentx, "", $current); // Удаление фрагмента

        file_put_contents($factsFile, $current); // Вносим полученные данные в корневой словарь

        // Удаление информации из файла с описанием файлов
        $factsFile =  __DIR__ . "/tomita/fact_types.proto";
        $lines = file($factsFile); //file in to an array
        file_put_contents($factsFile, '');

        $flag = false;
        $current = "";

        for ($i = 0; $i < count($lines); $i++) {
            $str = $lines[$i];
            if (strpos($str, $name) !== false) {
                $flag = true;
            }
            if ($flag === false) {
                $current .= $str;
            } else if (strpos($str, "}") !== false) {
                $flag = false;
            }
        }

        file_put_contents($factsFile, $current); // Вносим полученные данные в корневой словарь в файл с описанием фактов
        header("Location: SituationsReview.php"); // Обновление страницы
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

