FROM "alpine:3.18.6"

LABEL version="0.1"
LABEL description="I followed a tutorial"

RUN apk update
RUN apk add --no-cache mariadb mariadb-common mariadb-client && rm -rf /var/cache/apk

COPY ./mariadb_install.sh /usr/bin/mariadb_install.sh
RUN chmod +x /usr/bin/mariadb_install.sh


HEALTHCHECK --start-period=5m CMD mariadb -e 'SELECT @@datadir;' || exit 1

CMD ["/usr/bin/mariadb_install.sh"]
EXPOSE 3306
