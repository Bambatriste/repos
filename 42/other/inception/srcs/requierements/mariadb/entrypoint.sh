
if ! cat /var/lib/mysql/.mariadb_installed 2 > dev/null; then
  mysql_install_db;
  touch /var/lib/mysql/.mariadb_installed;
fi

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

if ! cat /var/lib/mysql/.mariadb_configured 2 > dev/null;then
  mariadb -u root < /tmp/sql_config.sql;
  touch /var/lib/mysql/.mariadb_configured;
fi

mysqladmin shutdown;
mysqld_safe;
