#!/bin/bash

if [[ $1 == "--help" ]]
then
        echo "make_lib [file].c [libname]"
        echo "Just enter the file name without .c or .o and enter the library name"
else
        gcc -c -fPIC $1.c -o $1.o
        stat=$?
        echo "$stat"
        if [[ stat -eq 0 ]]  
        then
                gcc -shared -o lib$2.so $1.o
                stat=$?
                if [[ stat -eq 0 ]]
                then
                        echo "Successfully compiled and created an archive. Library ready to use!"
                else
                        echo "ERROR: compilation and executable file creation successful but creating the shared library has run into some issue"
                        gcc -shared -o lib$2.so $1.o
                fi
        else
                echo "Error while compiling code!!"
                gcc -c $1.c -o $1.o
        fi
fi
