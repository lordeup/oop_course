@echo off

chcp 1251

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

call %PROGRAM% 2> %OUT%
fc %OUT% tests\noParams-out.txt
if errorlevel 1 goto err
echo Test: No params PASSED

call %PROGRAM% tests\missing.txt > %OUT%
fc %OUT% tests\fileMissing-out.txt
if not errorlevel 0 goto err
echo Test: File missing PASSED

call %PROGRAM% tests\matrix1.txt > %OUT%
fc %OUT% tests\InvertMatrix1-out.txt
if errorlevel 1 goto err
echo Test: InvertMatrix1 PASSED

call %PROGRAM% tests\matrix2.txt > %OUT%
fc %OUT% tests\InvertMatrix2-out.txt
if errorlevel 1 goto err
echo Test: InvertMatrix2 PASSED

call %PROGRAM% tests\matrixDeterminantNull.txt > %OUT%
fc %OUT% tests\matrixDeterminantNull-out.txt
if errorlevel 1 goto err
echo Test: matrixDeterminantNull PASSED

echo All tests passed
exit / B 0

:err
echo Program testing failed
exit / B 1