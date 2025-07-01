#!/bin/bash

gcc -o server mini_server.c -lfcgi
spawn-fcgi -p 8080 ./server
service nginx start
tail -f /dev/null
