@echo off

chcp 1251

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

call %PROGRAM% 2> %OUT%
fc %OUT% tests\noParams-out.txt
if errorlevel 1 goto err
echo Test: No params PASSED

call %PROGRAM% tests\missing.txt "Lorem ipsum" > %OUT%
fc %OUT% tests\fileMissing-out.txt
if not errorlevel 0 goto err
echo Test: File missing PASSED

call %PROGRAM% tests\textFile.txt "" > %OUT%
fc %OUT% tests\emptyString-out.txt
if not errorlevel 0 goto err
echo Test: Empty search string PASSED

call %PROGRAM% tests\textFileEmpty.txt "Lorem" > %OUT%
fc %OUT% tests\textFileEmpty-out.txt
if not errorlevel 1 goto err
echo Test: Empty text file PASSED

call %PROGRAM% tests\textFile.txt "Elon Musk" > %OUT%
fc %OUT% tests\textNotFound-out.txt
if not errorlevel 0 goto err
echo Test: Text not found PASSED

call %PROGRAM% tests\textFile.txt "Lorem ipsum" > %OUT%
fc %OUT% tests\findTextFile-out.txt
if errorlevel 1 goto err
echo Test: Find the text in file PASSED

call %PROGRAM% tests\textFile.txt "Amet" > %OUT%
fc %OUT% tests\textRegister-out.txt
if errorlevel 1 goto err
echo Test: Search expressions are case-sensitive PASSED

call %PROGRAM% tests\textFile.txt "sir" > %OUT%
fc %OUT% tests\textRepeated-out.txt
if errorlevel 1 goto err
echo Test: Searching repeated PASSED

echo All tests passed
exit / B 0

:err
echo Program testing failed
exit / B 1
