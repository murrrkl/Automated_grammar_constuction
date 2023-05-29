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

        if (count($lines) > 1) {
            $mySituation = $lines[1];
            $mySituation = substr($mySituation,1,-1);

            $host = '127.0.0.1';
            $username = 'root';
            $pass = '12345678K';
            $db = 'Situations';
            //$conn = new PDO("mysql:host=$host;dbname=$db", $username, $pass);


            // Поиск по БД mySituations (id, name, description)


        } else {
            echo '<script>alert("Ситуация не распознана!")</script>';
        }

    } else {
        echo '<script>alert("Описание ситуации не может быть пустым!")</script>';
    }
}
?>

<body>
<div style = "display: flex; flex-direction: column;  height: 100vh; align-items: center; justify-content: center;">
    <h1>Введите описание вашей ситуации</h1>
    <form method="POST">
        <textarea name="a" type="text"></textarea>

        <div style="display: flex; justify-content: center; align-items: center;">
            <button name = "submit">Получить обоснование</button>
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



