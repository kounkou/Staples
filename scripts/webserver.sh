#!/bin/bash

while true
do 
  echo -e "HTTP/1.1 200 OK\n\n {"example":"value"}" | nc -l -p 1500 -q 1
done
