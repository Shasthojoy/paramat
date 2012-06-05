#! /bin/bash

./gen_mul.sh ../src/main.c test1.oct $1
cd ../src
make
cd ../test_gen
RES1="`../src/a.out | sed 's/\.[0-9]*//g' | grep '[0-9]\+ [0-9]\+' | sed 's/^ //g' | sed 's/ +/ /g'`"
RES2="`octave -q test1.oct | sed 's/\.[0-9]*//g' | grep '[0-9]\+ \+[0-9]\+' | sed 's/^ \+//g' | sed 's/ \+/ /g'`"
cd ../src
make clean
cd ../test_gen

echo ' '
#echo $RES1
echo ' '
#echo $RES2
echo ' '
if test "$RES1" = "$RES2"; then
    echo 'OK'
else
    echo 'KO'
fi
