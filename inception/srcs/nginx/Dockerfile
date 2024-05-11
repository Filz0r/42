FROM "alpine:3.18.6"

LABEL version="0.1"
LABEL description="nginx runs the internet"

RUN apk --no-cache update && apk add --no-cache nginx openssl && rm -rf /var/cache/apk

COPY ./default.conf /etc/nginx/http.d/.
RUN mkdir -p /etc/nginx/certs/

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/certs/privatekey.key -out /etc/nginx/certs/certificate.crt -subj "/C=PT/L=Lisboa/O=42Lisboa/OU=Student/CN=${WORDPRESS_DOMAIN}"

EXPOSE 443 

CMD ["nginx", "-g", "daemon off;"]
