FROM nginx:1.21.6

WORKDIR /home/

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./mini_server.c /home/
COPY ./build_server.sh /home/

RUN chmod +x build_server.sh \
    && apt-get update \
    && apt-get install -y gcc spawn-fcgi libfcgi-dev curl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    && adduser --disabled-password --gecos "" user2 \
    && mkdir -p /home/nginx_temp \
    && chown -R user2:user2 /home/nginx_temp /var/log/nginx /var/cache/nginx \
    && chmod -R 755 /home/nginx_temp \
    && chown -R user2:user2 /home/ \
    && chmod -R 755 /home/

USER user2

ENTRYPOINT ["/home/build_server.sh"]