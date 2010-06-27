tools\echo1 -n "Set UNC_PATH=" > set_unc_path.bat
tools\pwd1 >>  set_unc_path.bat
set_unc_path.bat 
copy /Y set_unc_path.bat  %UNC_PATH%\

