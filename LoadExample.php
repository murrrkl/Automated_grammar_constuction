<?php
if (isset($_POST['upload_btn'])) {
    if (isset($_FILES['example']) & $_FILES['example']['error'] === UPLOAD_ERR_OK) {

            // Информация о файле с примерами
            $exampleName = $_FILES['example']['name'];
            $exampleNameNameCmps = explode(".", $exampleName);
            $exampleNameExtension = strtolower(end($exampleNameNameCmps));

            if (in_array($exampleNameExtension, array('txt'))) {
                    if(!move_uploaded_file($_FILES["example"]["tmp_name"],  __DIR__ . '/knowledge/' . "test.txt")) {
                        echo '<script>alert("Во время загрузки файла произошла ошибка!")</script>';
                    } else {
                        echo '<script>alert("Файл успешно загружен!")</script>';
                        header("Location: GenerateGramma.php");
                    }
            } else {
                echo '<script>alert("Файл с примерами имеет неверный формат!")</script>';
            }
    } else {
        echo '<script>alert("Файл с примерами описаний ситуации не выбран!")</script>';
    }

}

?>

<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
        <a class = "menu" href="special.php" style="margin-left: 30px;">Меню специалиста</a>
    </div>
</header>

<div style = "display: flex; flex-wrap:wrap; justify-content: center; align-items: center; padding-top: 50px;">
    <div class = "step done">1</div>
    <div class = "line"></div>
    <div class = "step done">2</div>
    <div class = "line"></div>
    <div class = "step">3</div>
    <div class = "line"></div>
    <div class = "step">4</div>
</div>
<form action="LoadExample.php" method="POST" enctype="multipart/form-data">
    <div style="display: flex; flex-direction: column;  height: 100vh; align-items: center; margin-top: 100px;">
        <center>
            <h1>Загрузите файл с примерами описаний ситуации</h1>
            <div style="display: flex; flex-wrap: wrap; width: 300px; flex-direction: column;  height: 100vh; align-items: center; margin-top: 100px;">
                <input id = "input_example" type="file"  name="example">
                <button id="input_button_example" onclick="document.getElementById('input_example').click()" type="button">Выберите файл</button>
                <button id = "load" name = "upload_btn" type="submit">Загрузить</button>
            </div>

        </center>
    </div>
</form>

<style>

    * {

        margin: 0;
        padding:0;
    }

    @font-face {
        font-family: "Evolventa-Regular";
        src: url(fonts/Evolventa-Regular.otf);
    }

    body {
        font-family: "Evolventa-Regular";
        background-color: Lavender;
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

    h1 {
        color: DarkSlateBlue;
    }

    #load {
        background-color: DarkSlateBlue;
        color: white;
        height: 45px;
        margin-top: 10px;
    }

    button {
        width: 300px;
        height: 50px;
        background-color: white;
        justify-content: center;
        align-items: center;
        transition: 0.3s;
        text-decoration: none;
        display: inline-block;
        font-family: "Evolventa-Regular";
        border: none;
        border-radius: 45px;
        margin-bottom: 10px;
        padding:5px 32px;
        text-align: center;
        letter-spacing: 2px;
        font-size: 14px;
        color: black;
    }

    #input_example{
        opacity: 0;
        visibility: hidden;
        position: absolute;
    }

    button:hover {
        box-shadow: 0 15px 20px rgba(59, 0, 105, .4);
    }
</style>

<script>

    document.getElementById('input_example').addEventListener('change', function(){
        let input_button = document.getElementById("input_button_example");
        let input_button_text = input_button.innerText;

        if( this.value ){
            input_button.innerText = "Файл выбран";
        } else {
            input_button.innerText = input_button_text;
        }
    });

</script>