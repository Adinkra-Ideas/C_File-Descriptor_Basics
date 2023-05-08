#!/bin/sh
make
./read_line Makefile > Makefile_output
make fclean
clear

# diff exits with a status of 0 if no difference: https://www.ibm.com/docs/en/aix/7.1?topic=d-diff-command
if [ ! "$(diff -U 3 Makefile_output Makefile)" ];
then
  echo
  echo "*==================================================================*"
  echo "* Default Test Using "Makefile" as Input Was Successful              *"
  echo "* You Can Run Your Custom Tests With [./read_line your_file_path]  *"
  echo "*==================================================================*"
  echo
else
  diff -U 3 Makefile_output Makefile
fi

rm -f Makefile_output
 
