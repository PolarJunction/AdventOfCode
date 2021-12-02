@echo off
for /D %%i in (*) do cd %%i && make && cd ..