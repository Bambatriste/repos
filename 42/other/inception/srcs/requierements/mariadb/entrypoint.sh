mysqld_safe&

until mysqladmin ping;
do
sleep 1;
echo "test";
done

cd /root/

#export SQL_ROOT_USER=aedouard;
#export SQL_ROOT_PWD=nelito444^^;
#export SQL_BASIC_USER=basic_user;
#export SQL_BASIC_PWD=bonjour1234;
#export SQL_DB=wordpress;

mariadb -e "CREATE USER '$SQL_ROOT_USER'@'%' IDENTIFIED BY '$SQL_ROOT_PWD'"
mariadb -e "GRANT ALL PRIVILEGES ON * . * TO '$SQL_ROOT_USER'@'%'"
mariadb -e "FLUSH PRIVILEGES"
mariadb -e "CREATE DATABASE IF NOT EXISTS $SQL_DB"

## CREE UN USER PAS ADMIN */

mariadb -e "CREATE USER '$SQL_BASIC_USER'@'mariadb'"
mariadb -e "GRANT ALL PRIVILEGES ON $SQL_DB . * TO '$SQL_BASIC_USER'@'mariadb'"
mariadb -e "FLUSH PRIVILEGES"

## SUPPRIME LA CO ROOT
mariadb -e "DELETE FROM mysql.user WHERE user=''"
mariadb -e "DELETE FROM mysql.user WHERE user='root'"
mariadb -e "FLUSH PRIVILEGES"

killall mysqld
mysqld
