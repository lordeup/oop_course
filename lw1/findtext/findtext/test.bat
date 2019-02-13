@echo off

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

echo No params
call %PROGRAM%  2>%OUT%
fc %OUT% tests\noParams-out.txt
if errorlevel 1 goto err
echo Test: No params SUCCEED

echo File missing
call %PROGRAM% tests\missing.txt "Lorem ipsum" > %OUT%
fc %OUT% tests\fileMissing-out.txt
if not errorlevel 0 goto err
echo Test: File missing SUCCEED

echo Empty search string
call %PROGRAM% tests\textFile.txt "" > %OUT%
fc %OUT% tests\emptyString-out.txt
if not errorlevel 0 goto err
echo Test: Empty search string SUCCEED

echo Empty text file
call %PROGRAM% tests\textFileEmpty.txt "Lorem" > %OUT%
fc %OUT% tests\textFileEmpty-out.txt
if not errorlevel 1 goto err
echo Test: Empty text file SUCCEED

echo Text not found
call %PROGRAM% tests\textFile.txt "Elon Musk" > %OUT%
fc %OUT% tests\textNotFound-out.txt
if not errorlevel 0 goto err
echo Test: Text not found SUCCEED

echo Find the text in file
call %PROGRAM% tests\textFile.txt "Lorem ipsum" > %OUT%
fc %OUT% tests\findTextFile-out.txt
if errorlevel 1 goto err
echo Test: Find the text in file SUCCEED

echo Search expressions are case-sensitive
call %PROGRAM% tests\textFile.txt "Amet" > %OUT%
fc %OUT% tests\textRegister-out.txt
if errorlevel 1 goto err
echo Test: Search expressions are case-sensitive SUCCEED

echo Searching repeated
call %PROGRAM% tests\textFile.txt "sir" > %OUT%
fc %OUT% tests\textRepeated-out.txt
if errorlevel 1 goto err
echo Test: Searching repeated SUCCEED

echo All tests passed
exit / B 0

:err
echo Program testing failed
exit / B 1
