#!/bin/bash

#batch download nhentai source
#param[1] image url
#param[2] total page number
#param[3] Y/y to check file list exist, other or empty do nothing
#eg: run.bat https://i.nhentai.net/galleries/804518/5.jpg 6

#echo $1
#echo $2
#echo $3

#create filelist.txt
./wGetListGen $1 $2

#download
wget -i filelist.txt -o log.txt -p -P Author_Unknown

#check file list 
./wGetListGen $1 $2 Y


















