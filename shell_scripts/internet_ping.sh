#=========================================================================
#Name        : internet_ping.sh
#Description : This script pings google.com 1 packet and returns the 
#               result. It sleep for 2 seconds before trying again next time
#              In the process time on PC is captured as well
#Where to run: terminal supporting shell scripts
#========================================================================
while true
do
date
ping www.google.com -n 1 | grep -Ev "statistics|Packets: Sent|round trip|Minimum"
sleep 2
done

