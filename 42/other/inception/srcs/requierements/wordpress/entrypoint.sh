cd /var/www/html
wp core download --allow-root
mv /wp-config.php .
until mysqladmin -hmariadb -u${SQL_ROOT_USER} -p${SQL_ROOT_PWD} ping && mariadb -hmariadb -u${SQL_ROOT_USER} -p${SQL_ROOT_PWD} -e "SHOW DATABASES;" | grep ${SQL_DB}; do
	sleep 2
done
echo "SQL ADMIN REACHED"
wp core install --url="aedouard.42.fr" --title="first website" --admin_user="${SQL_ROOT_USER}"
--admin_password="${SQL_ROOT_PWD}" --admin_email="bonjour1234@hotmail.fr" --skip-email --allow-root

php-fpm7.3 -F;

