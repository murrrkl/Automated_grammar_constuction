<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
        <a class = "menu" href="special.php" style="margin-left: 30px;">Меню специалиста</a>
    </div>
</header>

<div style = "display: flex; flex-wrap:wrap; justify-content: center; align-items: center; padding-top: 50px;">
    <div class = "step done">1</div>
    <div class = "line"></div>
    <div class = "step">2</div>
    <div class = "line"></div>
    <div class = "step">3</div>
    <div class = "line"></div>
    <div class = "step">4</div>

</div>

<style>

    * {

        margin: 0;
        padding:0;
    }

    @font-face {
        font-family: "Evolventa-Regular";
        src: url(fonts/Evolventa-Regular.otf);
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

    .step {
        width: 50px;
        height: 50px;
        border-radius: 50%;
        border: 1px solid MediumPurple;
        font-family: "Evolventa-Regular";
        text-align: center;
        color: white;
        padding: 0;
        display: flex;
        justify-content: center;
        align-items: center;
        font-size: 18px;
    }

    .done {
        background-color: #8436bf9d;
    }

    .line {
        width: 100px;
        height: 3px;
        background-color: MediumPurple;
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


if (!empty($_POST)) {
    if (trim($_POST['name'] === '')) {
        echo "<script>alert('Название ситуации не может быть пустым!');</script>";
    } else if (trim($_POST['description'] === '')) {
        echo "<script>alert('Описание ситуации не может быть пустым!');</script>";
    } else {
        $sql = "SELECT COUNT(*) FROM mySituations WHERE name != ''";
        $res = $conn->query($sql);
        $count = $res->fetchColumn();

        for ($i = 1; $i <= $count; $i++) {
            array_map('unlink', glob("tomita/*.bin"));
        }

        $name = $_POST['name'];
        $description = $_POST['description'];
        $sql = $conn->prepare("INSERT INTO mySituations(`name`, `description`) VALUES (?, ?);");
        $dbg = $sql->execute([$name, $description]);
        header("Location: LoadExample.php");
    }
}

?>
<meta charset="utf-8" />
<body>
<div style = "display: flex; flex-direction: column;  height: 100vh; margin-top: 100px;">
    <form method="POST">
        <div style="display: flex; align-items: center; flex-direction: column;">
            <input name="name" type="text" placeholder="Введите название ситуации">
            <textarea name="description" type="text" placeholder="Введите обоснование ситуации..."></textarea>
        </div>
        <div style="display: flex; justify-content: center; align-items: center;">
            <button name = "submit">Сохранить</button>
        </div>
    </form>
</div>
</body>

<style>
    body {
        font-family: "Evolventa-Regular";
        background-color: Lavender;
    }

    input {
        width: 630px;
        height: 50px;
        font-size: 13px;
        background: white;
        border-radius: 25px;
        border: none;
        padding: 20px;
        margin-bottom: 20px;
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
</style>