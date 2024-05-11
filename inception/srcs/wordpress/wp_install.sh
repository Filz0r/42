#!/bin/sh


if [ ! -f "/app/initialized" ]; then
    echo "Wordpress not initialized!"
    echo "Waiting for database to get online"
    sleep 10;
        
    cp wp-config-sample.php wp-config.php
    sed -i "s/username_here/$MYSQL_USER/" wp-config.php
    sed -i "s/password_here/$MYSQL_USER_PASSWORD/" wp-config.php
    sed -i "s/database_name_here/$WORDPRESS_DB_NAME/" wp-config.php
    sed -i "s/localhost/mariadb/" wp-config.php
    sed -i "s/put your unique your unique phrase here/vaiamerda/g" wp-config.php

    sed -i "s/listen \= 127\.0\.0\.1\:9000/listen \= 9000/" /etc/php81/php-fpm.d/www.conf 

    wp core install --allow-root --url=$WORDPRESS_DOMAIN --title="fparreir's cool website" --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email

    wp user create $WORDPRESS_ADMIN $WORDPRESS_ADMIN_EMAIL --role=administrator --user_pass=$WORDPRESS_ADMIN_PASSWORD
    wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --user_pass=$WORDPRESS_USER_PASSWORD
    wp theme activate twentytwentytwo
    touch initialized
    echo Starting wordpress!
else
    echo Starting wordpress!
    sleep 5;
fi
#
php-fpm81 -R --nodaemonize --force-stderr 
