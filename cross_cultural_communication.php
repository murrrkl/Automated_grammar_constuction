<body>
<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
    </div>
</header>

<div style = "display: flex; flex-direction: column;  align-items: center; margin-top: 100px; margin-bottom: 30px;">
    <form method="POST">
        <textarea name="a" type="text" placeholder="Введите описание вашей ситуации ..."></textarea>

        <div style="display: flex; justify-content: center; align-items: center;">
            <button name = "submit">Получить обоснование</button>
        </div>
    </form>
</div>
</body>

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

    @font-face {
        font-family: "Evolventa-Regular";
        src: url(fonts/Evolventa-Regular.otf);
    }

    body {
        background-color: Lavender;
        font-family: "Evolventa-Regular";
    }

    textarea {
        width: 630px;
        height: 300px;
        font-size: 13px;
        background: white;
        border-radius: 25px;
        border: none;
        resize: none;
        outline: none;
        -moz-appearance: none;
        padding: 20px;
        margin-bottom: 20px;
    }

    button {
        width: 500px;
        height: 50px;
        background-color: MediumPurple;
        border: none;
        border-radius: 25px;
        font-size: 18px;
        font-family: "Evolventa-Regular";

    }

    #answer {
        font-size: 16px;
        padding: 60px;
    }


</style>

<?php

if(isset($_POST['submit'])) {
    $a = $_POST['a'];
    if ($a != "") {
        // Запись полученного описания ситуации в файл
        $a = str_replace('.', '', $a);
        $fp = fopen("tomita/test.txt", "w");
        fwrite($fp, $a);
        fclose($fp);

        // Получение выходного файла
        $last_line = system('docker run --rm -v /var/www/html/tomita:/mnt nlpub/tomita bash /mnt/auto.sh', $retval);

        $myFile = "tomita/output.txt";
        $lines = file($myFile);//file in to an array

        $host = '127.0.0.1';
        $username = 'root';
        $pass = '12345678K';
        $db = 'Situations';

        $conn = new PDO("mysql:host=localhost; charset=utf8; dbname=$db", $username, $pass);

        if (count($lines) > 1) {
            $mySituation = $lines[1];
            $mySituation = substr($mySituation,1,-1);

            // Поиск по БД
            $sth = $conn->prepare("SELECT * FROM `mySituations` WHERE `name` = :name");
            $sth->execute(array('name' => $mySituation));
            $array = $sth->fetch(PDO::FETCH_ASSOC);
            $description = $array['description'];

            echo '<center><div id="answer">' . $description . '</div> </center>';

        } else {
            $sql = $conn->prepare("INSERT INTO Unrecognized(`description`) VALUES (?);");
            $dbg = $sql->execute([$a]);
            echo '<script>alert("Ситуация не распознана!")</script>';
        }

    } else {
        echo '<script>alert("Описание ситуации не может быть пустым!")</script>';
    }
}
?>

