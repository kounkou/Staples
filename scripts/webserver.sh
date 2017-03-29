#!/bin/bash
#---------------------------------
#
# FILE : webserver.sh  
#
# DESCRITION :
# webserver script is a server side application
# The server application will send the 
# Json data to the client application
#
#---------------------------------

USAGE="Usage : command"
DATA_PATH="/tmp/"

# generate_data function
generate_data()
{
   echo 'Enter : function generate_data()'
   if [ ! -f ${DATA_PATH}/data ]
   then
      cp -rf data /tmp/
   fi
   echo 'Exit  : function generate_data()'
}

# launch_server function
launch_server()
{
   echo 'Enter : function launch_server()'
   while true
   do 
      information=`cat ${DATA_PATH}/data`
      echo -e "HTTP/1.1 200 OK\n\n ${information}" | nc -l -p 80 -q 1
   done
   echo 'Exit  : function launch_server()'
}

if [ $# != 0 ]
then
   echo $USAGE
   exit 1
fi

#---------------------------------
generate_data
launch_server

