mysqld&

until mysqladmin ping;
do
sleep 1;
echo "test";
done

cd /root/

mariadb -e "CREATE USER '$MYSQL_ROOT_USER'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'"
mariadb -e "GRANT ALL PRIVILEGES ON * . * TO '$MYSQL_ROOT_USER'@'%'"
mariadb -e "FLUSH PRIVILEGES"
mariadb -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE"

## SUPPRIME LA CO ROOT
mariadb -e "DELETE FROM mysql.user WHERE user=''"
mariadb -e "DELETE FROM mysql.user WHERE user='root'"
mariadb -e "FLUSH PRIVILEGES"

killall mysqld
mysqld
