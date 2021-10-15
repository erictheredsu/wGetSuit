#!/bin/bash

#batch download nhentai source
#param[1] image url
#param[2] total page number
#eg: run.bat https://i.nhentai.net/galleries/804518/5.jpg 6

echo $1
echo $2

#create filelist.txt
./wGetListGen $1 $2

#download
wget -i filelist.txt -o log.txt -p 




















