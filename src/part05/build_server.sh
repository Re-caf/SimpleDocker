#!/bin/bash

gcc -o server mini_server.c -lfcgi
if [ $? -eq 0 ]; then
    spawn-fcgi -p 8080 ./server
    service nginx start
    exec /bin/bash
else
    echo "Compilation failed!"
    exit 1
fi
