#!/bin/bash
<<c1
# Problem Statement:

  Create a script which monitors the processes running on a system time to time - say every 15 minutes. 
  If any running process is down it sends a mail immediately to the system administrator on a given e-mail address.

# In this shell script using infinity while loop for checking Running process continously
# we can also use command 'cron job' for scripts run automatically time to time(https://phoenixnap.com/kb/set-up-cron-job-linux)
# if we use 'cron job' command that time we don't need while loop in shell script, just remove while loop syntax in the script
# 'grep' command use in Linux for the filter searches a file for a particular pattern of characters
# '-lt' use to compare two arguments (True if arg1 less than arg2)
# Date : 26-feb-2022
# Thak you Roshni joshi  
# Group 08
c1

while [ 1 ]
do
	# email address eg(abc@gmail.com) 
        To="abc@gmail.com"

        echo "start time" >> ts.txt
        echo $(date +"%H:%M:%S") >> ts.txt
        echo "start time"
        d=$(date +"%H:%M:%S")
        echo $d

        echo "$(ps axo stat,pid,comm,start,s)" >> ts.txt
        cat ts.txt | awk '{ print $5 }'>>ex.txt
        ps axo stat,pid,comm,start,s
        
	# check if any running process is down
        k="$(grep -c "S" ts.txt)"
        echo $k
        if [ 1 -lt $k ]
        then
        	echo "Some Process is down"
        	echo " Some of the system process is down "|sendmail $To
        else
        	echo " Working fine "
        fi
        
        echo "end time"
        echo $(date +"%H:%M:%S")
        echo "end time">> ts.txt
        echo $(date +"%H:%M:%S") >> ts.txt
        echo "sleep for 15 minutes"
        echo "*******">> ts.txt
        #sleep for 15 minutes
        sleep 15m
done
