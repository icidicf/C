#!/bin/bash

sudo  apt-get install libcurl4-gnutls-dev 

gcc -o multhread -g multithread.c -lcurl -lpthread

