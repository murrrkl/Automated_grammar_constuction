<?php

$host = '127.0.0.1';
$username = 'kiko';
$pass = '12345678K';
$db = 'Situations';
//$conn = new PDO("mysql:host=$host;dbname=$db", $username, $pass);

if (!empty($_POST)) {
    if (trim($_POST['name'] === '')) {
        echo "<script>alert('Название ситуации не может быть пустым!');</script>";
    } else if (trim($_POST['description'] === '')) {
        echo "<script>alert('Описание ситуации не может быть пустым!');</script>";
    } else {
        $name = $_POST['name'];
        $description = $_POST['description'];
    }
}
?>

<body>
<div style = "display: flex; flex-direction: column;  height: 100vh; align-items: center; justify-content: center;">
    <form method="POST">
        <div style="display: flex; justify-content: center; align-items: center; flex-direction: column;">
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
        background-color: Lavender;
    }

    input {
        width: 630px;
        height: 50px;
        font-size: 13px;
        font-family: "Evolventa-Regular";
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
        font-family: "Evolventa-Regular";
        background: white;
        border-radius: 25px;
        border: none;
        resize: none;
        outline: none;
        -moz-appearance: none;
        padding: 20px;
        margin-bottom: 20px;
    }

    h1 {
        font-family: "Evolventa-Regular";
        width: 100%;
        text-align: center;
        color: DarkSlateBlue;
    }

    button {
        width: 500px;
        height: 50px;
        background-color: MediumPurple;
        font-family: "Evolventa-Regular";
        border: none;
        border-radius: 25px;
        font-size: 18px;

    }


</style>