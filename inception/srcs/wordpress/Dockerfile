FROM "alpine:3.18.6"

LABEL version="0.1"
LABEL description="I kinda already knew how to do this part"

RUN mkdir -p /app
WORKDIR /app

RUN apk --no-cache update && apk --no-cache add curl php81 php81-fpm php-phar fcgi php81-mysqli php81-cgi php81-iconv && rm -rf /var/cache/apk

COPY ./wp_install.sh /usr/bin/wp_install.sh
RUN chmod +x /usr/bin/wp_install.sh

RUN wget -O wordpress.tar.gz https://wordpress.org/wordpress-6.5.3.tar.gz
RUN tar -zxf wordpress.tar.gz
RUN mv wordpress/* .
RUN rm -rf wordpress.tar.gz wordpress

RUN curl -o /usr/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x /usr/bin/wp

EXPOSE 9000

CMD ["/usr/bin/wp_install.sh"]
