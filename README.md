# Automated_grammar_constuction

# Настройка сервера

Установка Linux, Nginx, MySQL, PHP:  https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mysql-php-lemp-stack-ubuntu-18-04-ru

Docker: https://www.digitalocean.com/community/tutorials/docker-ubuntu-18-04-1-ru

Tomita-Docker: https://hub.docker.com/r/nlpub/tomita

# Выдача прав доступа

`sudo chmod 777 /var/run/docker.sock` 

# MySQL

CREATE DATABASE Situations CHARACTER SET utf8;

CREATE TABLE mySituations(name varchar(20) NOT NULL,description text NOT NULL) CHARACTER SET=utf8;

# Установка PDO

sudo apt update
sudo apt install php7.2-mysql
sudo apt-get install pdo-mysql
