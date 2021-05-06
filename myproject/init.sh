#/bin/sh
  
mpath="../ipc"
[ -d $mpath ] && rm -rf $mpath
mkdir -p $mpath ../raw_data ../output
mkfifo $mpath/request $mpath/response
