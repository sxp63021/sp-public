#!/usr/bin/python3

import sys, getopt

def parse_input_args(argv):
    inputfile = ''
    outputfile = ''
    try:
        opts, args = getopt.getopt(argv, "hi:o:",["ifile=","ofile="])
    except getopt.GetoptError:
        print ("sat_file_split.py -i <inputfile> -o <outputfile>")
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print ("sat_file_split.py -i <inputfile> -o <outputfile>")
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg
    print ("Input file is: ", inputfile)
    print ("Output file is: ", outputfile)
    return inputfile, outputfile

#match1 = "Begin startTestcase - campaignName:"
match1 = "Test Case Execution request received"

def read_and_split_file(i,o):
    ofile = ""
    with open(i, encoding = "ISO-8859-1") as fp:
        cnt = 0
        f = None
        flag = False
        for line in fp:
            if (match1 in line):
                cnt += 1
                flag = True
                ofile = o + "_" + str(cnt)
                if (f != None):
                    f.closed
                f = open(ofile, "w+")
                print("line {} contents{}".format(cnt,line))
                    

            if (flag): 
                f.write(line)
        if (f != None):
            f.closed
    print ("Done with file")


if __name__ == "__main__":
    (i,o) = parse_input_args(sys.argv[1:])
    print ("i: ", i)
    print ("o: ", o)
    read_and_split_file(i,o)

