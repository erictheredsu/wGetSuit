@echo off

rem batch download nhentai source
rem param[1] image url
rem param[2] total page number
rem eg: run.bat https://i.nhentai.net/galleries/804518/5.jpg 6

rem create filelist.txt
wGetListGen.exe %1 %2

rem download
wget -i filelist.txt -o log.txt -p 