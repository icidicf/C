#!/bin/bash

gcc -ansi -I../include -Wall -DLINUX -D_GNU_SOURCE init.c reread.c single.c  -o reread  -L../lib -lapue -lpthread
