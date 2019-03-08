@echo off

chcp 1251

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"
set TEMP_FILE_CRYPT="%TEMP%\outCrypt.txt"
set TEMP_FILE_DECRYPT="%TEMP%\outDecrypt.txt"

call %PROGRAM% 2> %OUT%
fc %OUT% tests\noParams-out.txt
if errorlevel 1 goto err
echo Test: No params PASSED

call %PROGRAM% crypt tests\missingIn.txt %TEMP_FILE_CRYPT% 99 > %OUT%
fc %OUT% tests\fileMissing-out.txt
if errorlevel 1 goto err
echo Test: File missing PASSED

call %PROGRAM% crypt tests\input1.txt %TEMP_FILE_CRYPT% 256 > %OUT%
fc %OUT% tests\test256-out.txt
if errorlevel 1 goto err
echo Test: Test-256 PASSED

call %PROGRAM% crypt tests\input1.txt %TEMP_FILE_CRYPT% -1 > %OUT%
fc %OUT% tests\test-1-out.txt
if errorlevel 1 goto err
echo Test: Test- -1 PASSED

call %PROGRAM% crypt tests\input1.txt %TEMP_FILE_CRYPT% "Hello" > %OUT%
fc %OUT% tests\test-string-out.txt
if errorlevel 1 goto err
echo Test: Test-string PASSED

call %PROGRAM% unknownMode tests\input1.txt %TEMP_FILE_CRYPT% 99 > %OUT%
fc %OUT% tests\unknownMode-out.txt
if errorlevel 1 goto err
echo Test: UnknownMode PASSED

call %PROGRAM% crypt tests\input1.txt %TEMP_FILE_CRYPT% 255
call %PROGRAM% decrypt %TEMP_FILE_CRYPT% %TEMP_FILE_DECRYPT% 255
fc %TEMP_FILE_DECRYPT% tests\input1.txt
if errorlevel 1 goto err
echo Test: Correct input1 PASSED

call %PROGRAM% crypt tests\input2.txt %TEMP_FILE_CRYPT% 99
call %PROGRAM% decrypt %TEMP_FILE_CRYPT% %TEMP_FILE_DECRYPT% 99
fc %TEMP_FILE_DECRYPT% tests\input2.txt
if errorlevel 1 goto err
echo Test: Correct input2 PASSED

echo All tests passed
exit / B 0

:err
echo Program testing failed
exit / B 1