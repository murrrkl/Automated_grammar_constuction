<?php



if (isset($_POST['upload_btn'])) {
    if (isset($_FILES['gramma']) & $_FILES['gramma']['error'] === UPLOAD_ERR_OK) {
        if (isset($_FILES['fact']) & $_FILES['fact']['error'] === UPLOAD_ERR_OK) {
            // Информация о файле с грамматикой
            $grammaName = $_FILES['gramma']['name'];
            $grammaNameNameCmps = explode(".", $grammaName);
            $grammaNameExtension = strtolower(end($grammaNameNameCmps));

            // Информация о файле с фактками
            $factName = $_FILES['fact']['name'];
            $factNameNameCmps = explode(".", $factName);
            $factNameExtension = strtolower(end($factNameNameCmps));


            if (in_array($grammaNameExtension, array('cxx'))) {
                if (in_array($factNameExtension, array('proto'))) {
                    if(!move_uploaded_file($_FILES["gramma"]["tmp_name"],  __DIR__ . '/knowledge/' . "Situations.cxx") || !move_uploaded_file($_FILES["fact"]["tmp_name"],  __DIR__ . '/knowledge/' . "Facts.proto")) {
                        echo '<script>alert("Во время загрузки файлов произошла ошибка!")</script>';
                    } else {
                        echo '<script>alert("Файлы успешно загружены!")</script>';
                        header("Location: special.php");
                    }
                } else {
                    echo '<script>alert("Файл с фактками имеет неверный формат!")</script>';
                }

            } else {
                echo '<script>alert("Файл с граматикой имеет неверный формат!")</script>';
            }

        } else {
            echo '<script>alert("Файл с фактами не выбран!")</script>';
        }
    } else {
        echo '<script>alert("Файл с граматикой не выбран!")</script>';
    }

}

?>

<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
        <a class = "menu" href="special.php" style="margin-left: 30px;">Меню специалиста</a>
    </div>
</header>

<form action="Load_Knowledge.php" method="POST" enctype="multipart/form-data">
    <div style="display: flex; flex-direction: column;  height: 100vh; align-items: center; margin-top: 100px;">
    <center>
        <h1>Загрузите файлы с грамматикой и фактами</h1>
        <div style="display: flex; flex-wrap: wrap; width: 300px; flex-direction: column;  height: 100vh; align-items: center; margin-top: 100px;">
            <input id = "input_gramma" type="file"  name="gramma">
            <button id="input_button_gramma" onclick="document.getElementById('input_gramma').click()" type="button">Выберите файл</button>
            <input id = "input_fact" type="file"  name="fact">
            <button id ="input_button_fact" onclick="document.getElementById('input_fact').click()" type="button">Выберите файл</button>
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

    h1 {
        color: DarkSlateBlue;
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

    #input_gramma {
        opacity: 0;
        visibility: hidden;
        position: absolute;
    }

    #input_fact {
        opacity: 0;
        visibility: hidden;
        position: absolute;
    }

    button:hover {
        box-shadow: 0 15px 20px rgba(59, 0, 105, .4);
    }
</style>

<script>

    document.getElementById('input_gramma').addEventListener('change', function(){
        let input_button = document.getElementById("input_button_gramma");
        let input_button_text = input_button.innerText;

        if( this.value ){
            input_button.innerText = "Граматика выбрана";
        } else {
            input_button.innerText = input_button_text;
        }
    });

    document.getElementById('input_fact').addEventListener('change', function(){
        let input_button = document.getElementById("input_button_fact");
        let input_button_text = input_button.innerText;

        if( this.value ){
            input_button.innerText = "Файл с фактами выбран";
        } else {
            input_button.innerText = input_button_text;
        }
    });
</script>


