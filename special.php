<body>
<header>
    <div class="header">
        <a class = "menu" href="index.php">Главная</a>
    </div>
</header>

<div style = "display: flex; flex-direction: column;  height: 100vh; align-items: center; margin-top: 200px;">
    <a class="btn" href="SituationsReview.php">
        Просмотр БД
    </a>
    <a class="btn" href="SituationAdd.php">
        Добавить новую ситуацию
    </a>
    <a class="btn" href="Load_Knowledge.php">
        Загрузить архив грамматик
    </a>

    <div>
</body>

<style>
    * {

        margin: 0;
        padding:0;
    }

    .header{
        background-color: white;
        padding: 1.3em 1em; /* поля вокруг текста */
        background-color:rgba(255, 255, 255, 0.7);
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
        font-family: Evolventa-Regular;
    }

    .btn {
        width: 300px;
        height: 50px;
        background-color: white;
        justify-content: center;
        align-items: center;
        transition: 0.3s;
        text-decoration: none;
        display: inline-block;
        line-height: 45px;
        border-radius: 45px;
        margin-bottom: 20px;
        padding:5px 32px;
        text-align: center;
        letter-spacing: 2px;
        font-size: 18px;
        color: black;
        font-family: "Evolventa-Regular";
    }

    .btn:hover {
        box-shadow: 0 15px 20px rgba(59, 0, 105, .4);
    }

</style>