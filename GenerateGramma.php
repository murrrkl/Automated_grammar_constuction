<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
        <a class = "menu" href="special.php" style="margin-left: 30px;">Меню специалиста</a>
    </div>
</header>

<div style = "display: flex; flex-wrap:wrap; justify-content: center; align-items: center; padding-top: 50px; ">
    <div class = "step done">1</div>
    <div class = "line"></div>
    <div class = "step done">2</div>
    <div class = "line"></div>
    <div class = "step done">3</div>
    <div class = "line"></div>
    <div class = "step">4</div>
</div>
<form action="GenerateGramma.php" method="POST">
<div style="display: flex; flex-direction: column;  align-items: center; margin-top: 100px; margin-bottom: 100px;">
    <center>
        <button id = "load" name = "generate" type="submit">Сгенерировать грамматику</button>
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

    .menu:hover {
        color: purple;
        cursor: pointer;
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

    #load {
        background-color: DarkSlateBlue;
        color: white;
        margin-top: 10px;
        width: 300px;
        height: 50px;
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
    }

    button:hover {
        box-shadow: 0 15px 20px rgba(59, 0, 105, .4);
    }
</style>

<?php
if (isset($_POST['generate'])) {
    // Получение выходного файла
    $last_line = system('docker run --rm -v /var/www/html/knowledge:/mnt nlpub/tomita bash /mnt/auto.sh', $retval);

    $myFile = "knowledge/output.txt";
    $lines = file($myFile); //file in to an array

    $stack = array(); // Все найденнные поля фактов
    $countFact = array(); // Количество обнаруженных полей одного типа

    $required = array(); // обязательные поля фактов
    $optional = array(); // необязательные поля фактов


    for ($i = 0; $i < count($lines); $i++) {
        $str = $lines[$i];
        if (strpos($str, '=') !== false) {
            $result = substr($str, 0, strpos($str, '=') - 1);
            if (!in_array($result, $stack)) {
                array_push($stack, $result);
                array_push($countFact, 1);
            } else {
                $key = array_search($result,  $stack);
                $countFact[$key]++;
            }
        }

    }

    $max = max($countFact); // Максимальное кол-во встречаемых полей фактов одного типа

    for ($j = 0; $j < count($countFact); $j++) {
        if ($countFact[$j] >= $max * 0.8) {
            array_push( $required, $stack[$j]);
        } else {
            array_push( $optional, $stack[$j]);
        }
    }

    if (count($required) > 0) {
        echo '<center><h1>Обязательные поля фактов: </h1> </center>';
        for ($j = 0; $j < count($required); $j++) {
            echo '<center><div class = "facts">' . $required [$j] . '</div> </center>';
        }
    }

    if (count($optional) > 0) {
        echo '<center><h1>Необязательные поля фактов:</h1> </center>';
        for ($j = 0; $j < count($optional); $j++) {
            echo '<center><div class = "facts">' . $optional [$j] . '</div> </center>';
        }
    }
}
?>