@echo off

if "%1" == "Project" goto buildstep
goto exit

:buildstep
	if exist x:\build.txt (
		set /p build=<x:\build.txt
		set /a build=build+1
	) else (
		set build=1)
	echo Current build is %build%
	echo | set /p=%build% > x:\build.txt
	powershell -c (New-Object Media.SoundPlayer "C:\Windows\Media\alert.wav").PlaySync();
	goto end

:exit
	echo Nothing to do
	goto end

:end
