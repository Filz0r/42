#!/bin/sh

if [ -e "$MYSQL_DIR/mysql" ]; then
    echo "Database already exists"
else
    echo "Initializing database"
    sed -i "s/\#bind\-address\=0\.0\.0\.0/bind\-address\=0\.0\.0\.0/" /etc/my.cnf.d/mariadb-server.cnf
    sed -i "s/skip\-networking/#skip\-networking/" /etc/my.cnf.d/mariadb-server.cnf
    mariadb-install-db --user=mysql --datadir=$MYSQL_DIR &> /dev/null

    chown -R mysql:mysql $MYSQL_DIR
    mariadbd --datadir=$MYSQL_DIR --socket=$MYSQL_SOCKET --user=mysql &> /dev/null & 
    pid=$!
    sleep 2;

    echo "Setting up root password and creating database"
    mysqladmin --socket=$MYSQL_SOCKET -uroot password "$MYSQL_ROOT_PASSWORD"
    
    mysql --socket=$MYSQL_SOCKET -uroot -p"$MYSQL_ROOT_PASSWORD" -e "CREATE DATABASE IF NOT EXISTS $WORDPRESS_DB_NAME;"

    mysql --socket=$MYSQL_SOCKET -uroot -p"$MYSQL_ROOT_PASSWORD" -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';"
    mysql --socket=$MYSQL_SOCKET -uroot -p"$MYSQL_ROOT_PASSWORD" -e "GRANT ALL PRIVILEGES ON $WORDPRESS_DB_NAME.* TO '$MYSQL_USER'@'%';"
    mysql --socket=$MYSQL_SOCKET -uroot -p"$MYSQL_ROOT_PASSWORD" -e "FLUSH PRIVILEGES;"

    kill $pid
fi

echo "Launching MariaDB database" 

mariadbd --user=mysql --datadir=$MYSQL_DIR --socket=$MYSQL_SOCKET --bind-address=0.0.0.0 --port=3306

