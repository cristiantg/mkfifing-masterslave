#!/bin/bash
  
#$1 kaldi_path
#$2 input_dir
#$3 input_file
#$4 output_dir
#$5 output_id
#$6 speaker_id
#$7 logfile

conv=$5_conv.wav
sox $2/$3 -r 16000 -c 1 -b 16 $2/$conv
/opt/kaldi/egs/restasr/uber_single.sh $1 $2 $conv $4 $5 $6 > $7 2>&1
