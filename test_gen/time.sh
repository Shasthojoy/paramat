#! /bin/bash

echo 'Generating tests...'
./gen_mul 'test1.pm' 'test2.pm' test1.oct $1 $2
echo 'Tests generated'

echo 'Running program...'
time ./mul_test test1.pm test2.pm > /dev/null

echo ' '
echo 'Program terminated'
echo ' '
echo 'Done'

