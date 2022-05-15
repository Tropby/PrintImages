@echo off
   
set PRINTER="HP LaserJet Pro MFP M127fw"
set DIRECTORY="C:\Users\tropby\Pictures"
 
:start
    PrintImages.exe %PRINTER% %DIRECTORY%
    timeout /T 5
goto start