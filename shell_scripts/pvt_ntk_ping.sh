#!/usr/bin/bash
#=========================================================================
#Name        : pvt_ntk_ping.sh
#Description : Script to ping all the IPs on the private network
#Where to run: in Cygwin windows or where shell is supported
#output      : 
#             FAILURE CASE
#             ==============
#             $ ./pvt_ntk_ping.sh
#             .10 dn .11 dn .12 dn .13 dn
#             ...
#             .80 dn .81 dn .82 dn .83 dn
#             
#             SUCCESS CASE
#             ==============
#             .10 up .11 up .12 up .13 up
#             ...
#             .50 dn .51 up .52 dn .53 dn
#             .80 dn .81 dn .82 dn .83 dn
#             
#CAUTION     : IT TAKES A LONG TIME TO PING ALL IP
#========================================================================

var1="10 11 12 13"
var2="20 21 22 23"
var3="30 31 32 33"
var4="40 41 42 43"
var5="14 15 16 17"
var6="50 51 52 53"
var7="60 61 62 63"
var8="70 71 72 73"
var9="80 81 82 83"

for i in 1 2 3 4 5 6 7 8 9
do
	v="var$i"
	output=""
	date
	for j in ${!v}
	do
		ping -c 1 "192.168.2.$j" > /dev/null
		if [ $? -eq 0 ]; then
		output="$output $j up"
        else
		output="$output $j dn"
        fi
    done
	echo $output
done

