FROM nginx
USER root
WORKDIR /home/

COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./mini_server.c /home/
COPY ./build_server.sh /home/

RUN chmod +x build_server.sh \
    && apt-get update \
    && apt-get install -y gcc spawn-fcgi libfcgi-dev curl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    && adduser --disabled-password --gecos "" nginx_user \
    && mkdir -p /home/nginx_temp \
    && chown -R nginx_user:nginx_user /home/nginx_temp /var/log/nginx /var/cache/nginx \
    && chmod -R 755 /home/nginx_temp \
    && chown -R nginx_user:nginx_user /home/ \
    && chmod -R 755 /home/

USER nginx_user

ENTRYPOINT ["/home/build_server.sh"]
