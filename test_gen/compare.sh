#! /bin/bash

./gen_mul.sh 'test' 'test1.oct' $1

RES1="`./a.out test1.pm test2.pm | sed 's/\.[0-9]*//g' | grep '[0-9]\+ [0-9]\+' | sed 's/^ //g' | sed 's/ +/ /g'`"
RES2="`octave -q test1.oct | sed 's/\.[0-9]*//g' | grep '[0-9]\+ \+[0-9]\+' | sed 's/^ \+//g' | sed 's/ \+/ /g'`"

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
