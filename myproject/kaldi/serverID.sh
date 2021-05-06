#!/bin/bash
#SLAVE

salida() {
        echo -e "\n[Server-Interruptus]\n\n"
        exit $1
}
trap 'salida 2' 2

  ( cat <&3 | while read inp
    do
        /ipc/server-load.sh $inp
        # Answer to the client: ctm file path
        IFS=' ' read -ra ADDR <<< "$inp"
        echo ${ADDR[3]}/${ADDR[4]} >&4
    done ) 3<$1 4>$2
