cd /var/www/html
wp core download --allow-root
mv /wp-config.php .
wp core install --url="aedouard.42.fr" --allow-root
