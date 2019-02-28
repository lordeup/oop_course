@echo off

chcp 1251

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

call %PROGRAM% 2> %OUT%
fc %OUT% tests\noParams-out.txt
if errorlevel 1 goto err
echo Test: No params PASSED

call %PROGRAM% "" > %OUT%
fc %OUT% tests\emptyString-out.txt
if not errorlevel 0 goto err
echo Test: Empty search string PASSED

call %PROGRAM% 400 > %OUT%
fc %OUT% tests\test-400-out.txt
if not errorlevel 0 goto err
echo Test: Test-400 PASSED

call %PROGRAM% "Hello" > %OUT%
fc %OUT% tests\test-string-out.txt
if not errorlevel 0 goto err
echo Test: Test-string PASSED

call %PROGRAM% 6 > %OUT%
fc %OUT% tests\test6-out.txt
if errorlevel 1 goto err
echo Test: Test-6 PASSED

call %PROGRAM% 61 > %OUT%
fc %OUT% tests\test61-out.txt
if errorlevel 1 goto err
echo Test: Test-61 PASSED

call %PROGRAM% 255 > %OUT%
fc %OUT% tests\test255-out.txt
if errorlevel 1 goto err
echo Test: Test-255 PASSED

call %PROGRAM% 256 > %OUT%
fc %OUT% tests\test256-out.txt
if errorlevel 1 goto err
echo Test: Test-256 PASSED

call %PROGRAM% 0 > %OUT%
fc %OUT% tests\test0-out.txt
if errorlevel 1 goto err
echo Test: Test-0 PASSED

call %PROGRAM% -1 > %OUT%
fc %OUT% tests\test-1-out.txt
if errorlevel 1 goto err
echo Test: Test- -1 PASSED

echo All tests passed
exit / B 0

:err
echo Program testing failed
exit / B 1