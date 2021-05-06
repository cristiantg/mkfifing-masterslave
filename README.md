# mkfifing-masterslave

This project will help you to communicate your independent docker containers (under the same machine and docker-compose.yml) via independent mkfifo files. For instance, send a signal from your WEB container to your KALDI container to decode audio files and obtain the result.


1. Run before ```docker-compose.yml``` the script: ```init.sh```

1. Run ```docker-compose build```and ```docker-compose up -d ```. There are three containers in ```docker-compose.yml``` (WEB, BBDD, KALDI) and several shared volumes (e.g., /ipc). There will be five important files on ```/ipc```: ```start.sh```, ```server.sh```, ```serverID.sh```, ```request``` and ```response```.

1. Please notice that you will need to run inside the WEB container```make cli prepareCli``` if you make changes to ```cli.c``` or ```prepareClic.```. And copy/replace the output files ```cli``` and ```prepareCli```.

1. Run ```start.sh```. It is set in the entrypoint of KALDI. Thus, ```server.sh``` will be listening new requests forever.

1. A client app makes a http request to WEB. WEB runs on a JavaScript-node script```prepareCli request response ID```. This will trigger ```server.sh``` on KALDI.

1. KALDI creates three new files are automatically on /ipc: ```serverID.sh```, ```requestID``` and ```responseID```. ID=<login><idaudio>.

1. ```serverID.sh``` is initiated on the background.

1. KALDI answers WEB that the process has been initiated correctly: ```OK```.

1. WEB runs on a JavaScript-node script ```cli requestID responseID /restasr/opt/kaldi  _input_folder _input_file _output_folder _output_file _speaker_id _log_file_path serverID.sh```. This will trigger ```serverID.sh``` on KALDI.

1. KALDI starts the ASR process with ```server-load.sh /restasr/opt/kaldi  _input_folder _input_file _output_folder _output_file _speaker_id _log_file_path serverID.sh```

1. KALDI notifies WEB that the process has been finished correctly and the process ```serverID.sh``` ends.

1. WEB removes the files ```serverID.sh```, ```requestID``` and ```responseID```.

1. WEB sends the ASR transcription results to the client app.



## Contact
Cristian Tejedor-García
Email: cristian [dot] tejedorgarcia [at] ru [dot] nl
