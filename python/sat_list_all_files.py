#!/usr/bin/python3

import sys 
import getopt
import os

def print_rec_dir(i):
    walk_dir = i
    print('walk_dir = ' + walk_dir)

    if os.path.exists(walk_dir):
        print('Exists ', walk_dir)
    else:
        print('Does not Exist ', walk_dir)
        return

    for root,subdirs,files in os.walk(walk_dir):
#        print('--\nroot = ' + root)
        for f in files:
            print(root + '/' + f)
#        print('walk_dir (abs) = ' + os.path.abspath(walk_dir))

    print ("Done with directory")


if __name__ == "__main__":
    print_rec_dir("C:/SAT")

