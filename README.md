# Automated_grammar_constuction

# Настройка сервера

Установка Linux, Nginx, MySQL, PHP:  https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mysql-php-lemp-stack-ubuntu-18-04-ru

Docker: https://www.digitalocean.com/community/tutorials/docker-ubuntu-18-04-1-ru

Tomita-Docker: https://hub.docker.com/r/nlpub/tomita

# Выдача прав доступа

`sudo chmod 777 /var/run/docker.sock` 

# MySQL

`CREATE DATABASE Situations CHARACTER SET utf8;`

`CREATE TABLE mySituations(name varchar(20) NOT NULL,description text NOT NULL) CHARACTER SET=utf8;`


# Установка PDO

`sudo apt update`

`sudo apt install php7.2-mysql`

`sudo apt-get install pdo-mysql`

# Описание и назначение файлов
index.php - Главная страница: предоставляет возможность выбора режима работы "Пользователь" или "Специалист"

cross_cultural_communication - Режим работы пользователя: необходимо ввести описание ситуации, если ситуация есть в системе - пользователь получит обоснование, иначе нераспознанная ситуация сохранится в системе.

Пример описания ситуации:
`Я женщина 60 лет, моя талия составляет 92 см, по каким то причинам отправили на лечение`

special.php - Меню специалиста предусматривает 4 режима: Добавление ситуации, Просмотр ситуаций, Загрузка архива грамматик, Просмотр нераспознанных ситуаций

SituationReview.php - Просмотр всех ситуаций в системе с возможностью удаления ситуации из БД (как следствие - удаление грамматкии для распознавания и удаление информации о ней из файлов mydic.gzt, config.proto, fact_types.proto в директории tomita).

LoadKnowledge.php - Подгрузка архива грамматик и файла с описанием фактов. Имеется возможность скачивания в формате zip-архива. Пример файлов можно найти в папке knowledge Situations.cxx и Facts.proto

Unrecognized.php - Просмотр нераспознанных в системе ситуаций с возможностью их удаления.

# Добавление ситуации
Добавление ситуации состоит из 4 шагов:
SituationAdd.php - 1 шаг: Требует ввести название ситуации и её описание, после чего добавляет новую ситуацию в БД.

Пример названия:
`Situation_first`

Пример обоснования:
`С 2008 года в Японии действует «метаболический закон». Таким образом страна решила бороться с лишним весом жителей, тем самым делая их более здоровыми. По закону, у людей в возрасте от 40 до 75 лет измеряют размер талии, который не должен быть более 85 см у мужчин и 90 см у женщин. В случае превышения нормы жителю Японии оказывают специальную медицинскую поддержку по контролю веса, но без всяких штрафов и наказаний. Тем самым страна заботится о своих гражданах.`

LoadExample.php - 2 шаг: Требует подгрузку примеров описаний добавляемой ситуации в виде файла в формате txt. Пример файла можно найти в директории knowledge файл test.txt

GenerateGramma.php - 3 шаг: При нажатии на кнопку "Сгенерировать" формируется новая грамматика и вносится информация о ней в соответсвующии файлы (В директории tomita файлы mydic.gzt, config.proto, fact_types.proto). Название файла с грамматикой совпадает с названием добавляемой сиутации. Как следствие, данная ситуация может быть распознана в системе. 

Done.php - 4 шаг: Информирует о завершении процесса формирования грамматики, даёт возможность скачать файл для проверки, а также подгрузить альтернативную версию в случае необходимости.
