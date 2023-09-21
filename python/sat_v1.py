#!/usr/bin/python3

import sys
import glob
import fileinput

#Use this utility to combine files into one file

file_list = glob.glob( '*.log*' )

with open( 'test.txt', 'w' ) as t1:
    input_lines = fileinput.input(file_list)
    t1.writelines(input_lines)

'''
    for file_ in files:
        for line in open( file_, 'r' ):
            result.write( line )
'''

