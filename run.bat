@echo off

rem batch download nhentai source
rem param[1] image url
rem param[2] total page number if only 2 params, start page number if 3 params
rem param[3] total page number if 3 params
rem eg: run.bat https://i.nhentai.net/galleries/804518/5.jpg 6 
rem eg: run.bat https://i.nhentai.net/galleries/804518/5.jpg 6 13


set startNumber=1

if "%~3" == "" ( 
  set /a lastNumber=%2
) ^
else ( 
  set startNumber=%2
  set /a lastNumber=%3
)

echo range: from %startNumber% to %lastNumber%

rem create filelist.txt
wGetListGen.exe %1 %startNumber% %lastNumber%

rem download
wget -i filelist.txt -o log.txt -p -P Author_Unknown

rem check file
wGetListGen.exe %1 %startNumber% %lastNumber% check
