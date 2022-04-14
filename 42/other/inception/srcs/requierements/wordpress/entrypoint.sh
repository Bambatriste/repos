cd /var/www/html
wp core download --allow-root
mv /wp-config.php .
until mysqladmin -hmariadb -u${SQL_ROOT_USER} -p${SQL_ROOT_PWD} ping && mariadb -hmariadb -u${SQL_ROOT_USER} -p${SQL_ROOT_PWD} -e "SHOW DATABASES;" | grep ${SQL_DB}; do
	sleep 2
done
echo "SQL ADMIN REACHED"
wp core install --url="aedouard.42.fr" --allow-root

php-fpm -F -R
root

