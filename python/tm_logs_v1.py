#!/usr/bin/python3

import sys, getopt

def parse_input_args(argv):
    inputfile = ''
    outputfile = ''
    try:
        opts, args = getopt.getopt(argv, "hi:",["ifile="])
    except getopt.GetoptError:
        print ("tm_logs_v1.py -i <inputfile>")
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print ("tm_logs_v1.py -i <inputfile>")
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
    print ("Input file is: ", inputfile)
    return inputfile

#match1 = "Begin startTestcase - campaignName:"
match1 = "Test Case Execution request received"
#empty list
tm_list = []
tm_list.append("running as Administrator")
tm_list.append("number of cells set")
tm_list.append("Process ID for")
tm_list.append("Test Case Execution Job")
tm_list.append("Updating module params")
tm_list.append("reinit")
tm_list.append("Resolved env var C:/SAT/SA_EXE")
tm_list.append("updateCurrentCellIPs")
tm_list.append("updateENBReboot")
tm_list.append("updateSAConfig")
tm_list.append("return when startAllBands is called")
tm_list.append("TC_EXE: exit code for installLicens")
tm_list.append("started in TestCast")
tm_list.append("has been starte")
tm_list.append("onConnectionEstablished")
#tm_list.append("TE log:")
tm_list.append("TCI connection")
tm_list.append("TRI/TCI")
tm_list.append("VERDICT")
tm_list.append("SA is")
tm_list.append("SA con")
tm_list.append("satVersion")
tm_list.append("started in TestCast")
tm_list.append("onConnectionClosed")

def print_string_of_intrest(i):
    for s in tm_list:
        if (s in i):
            print("{}".format(i))

def read_and_print_logs(i):
    with open(i, encoding = "ISO-8859-1") as fp:
        cnt = 0
        f = None
        flag = False
        for line in fp:
            if (match1 in line):
                cnt += 1
                flag = True
                print("line {} contents{}".format(cnt,line))
            print_string_of_intrest(line)

    print ("Done with file")


if __name__ == "__main__":
    (i) = parse_input_args(sys.argv[1:])
    print ("i: ", i)
    read_and_print_logs(i)

