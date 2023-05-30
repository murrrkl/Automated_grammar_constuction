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


if (!empty($_POST)) {
    if (trim($_POST['name'] === '')) {
        echo "<script>alert('Название ситуации не может быть пустым!');</script>";
    } else if (trim($_POST['description'] === '')) {
        echo "<script>alert('Описание ситуации не может быть пустым!');</script>";
    } else {
        $name = $_POST['name'];
        $description = $_POST['description'];
        $sql = $conn->prepare("INSERT INTO mySituations(`name`, `description`) VALUES (?, ?);");
        $dbg = $sql->execute([$name, $description]);
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
    @font-face {
        font-family: "Evolventa-Regular";
        src: url(fonts/Evolventa-Regular.otf);
    }

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