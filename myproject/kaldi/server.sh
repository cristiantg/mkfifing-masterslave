#!/bin/bash

# MASTER

salida() {
	echo -e "\n[Server-Interruptus]\n\n"
	exit $1
}
trap 'salida 2' 2


# Loop forever (just in case the client closes the pipe)
# We expect inp ID
while true
do
  ( cat <&3 | while read inp
    do
	vol_path="/ipc"
	myReq=${vol_path}/request$inp
	myRes=${vol_path}/response$inp
	mkfifo $myReq $myRes
	myServer=${vol_path}/server${inp}.sh

	cp ${vol_path}/serverID.sh $myServer
	chmod 774 $myServer
	nohup $myServer $myReq $myRes > /dev/null 2>&1 &
	# Answer to the client with the task done
	#echo $inp >&4
	IFS=' ' read -ra m_array <<< "$inp"
	echo  OK $inp>&4
    done ) 3</ipc/request 4>/ipc/response
done
