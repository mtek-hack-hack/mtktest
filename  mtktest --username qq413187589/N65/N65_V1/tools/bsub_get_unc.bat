@echo off
bsub -I tools\get_unc.bat
call set_unc_path.bat
del /F /Q set_unc_path.bat




