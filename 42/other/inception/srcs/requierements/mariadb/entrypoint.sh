set -m

if ! cat /var/lib/mysql/.mariadb_installed 2 > /dev/null; then
  mysql_install_db 2> /dev/null;
  touch /var/lib/mysql/.mariadb_installed;
  echo "MARIADB INTALLED";
fi

mysqld_safe &

mysqladmin ping 2> /dev/null;
while [ $? -ne 0 ]; do echo "waiting for sql to setup .."; sleep 1; mysqladmin ping 2>/dev/null; done;

echo "PING SUCCESS TO MYSQL";

#export SQL_ROOT_USER=aedouard;
#export SQL_ROOT_PWD=nelito444;
#export SQL_BASIC_USER=basic_user;
#export SQL_BASIC_PWD=bonjour1234;
#export SQL_DB=wordpress;

if ! cat /var/lib/mysql/.mariadb_configured 2> /dev/null;then
  mysql < /tmp/sql_config.sql;
  touch /var/lib/mysql/.mariadb_configured;
  echo "SQL CONFIG DONE";
fi

fg
