#!/bin/bash

# echo "Content-type: text/html"
echo "Content-type: application/json"
echo ""

# Make sure we have been invoked properly.

if [ "$REQUEST_METHOD" != "GET" ]; then
   echo "<hr>Script Error:"\
        "<br>Usage error, cannot complete request, REQUEST_METHOD!=GET."\
        "<br>Check your FORM declaration and be sure to use METHOD=\"GET\".<hr>"
   exit 1
fi

# If no search arguments, exit gracefully now.

if [ -z "$QUERY_STRING" ]; then
   exit 0
else
   # No looping this time, just extract the data you are looking for with sed:
   DATE=`echo   "$QUERY_STRING" | sed -n 's/^.*val_x=\([^&]*\).*$/\1/p' | sed "s/%20/ /g"`
   NAME=`echo   "$QUERY_STRING" | sed -n 's/^.*val_y=\([^&]*\).*$/\1/p' | sed "s/%20/ /g"`
   PRICE=`echo  "$QUERY_STRING" | sed -n 's/^.*val_z=\([^&]*\).*$/\1/p' | sed "s/%20/ /g"`
   QTY=`echo    "$QUERY_STRING" | sed -n 's/^.*val_t=\([^&]*\).*$/\1/p' | sed "s/%20/ /g"`
   ACTION=`echo "$QUERY_STRING" | sed -n 's/^.*val_u=\([^&]*\).*$/\1/p' | sed "s/%20/ /g"`

   if [ "$ACTION" = "1" ]; then
      # add a staple
      # 1. find the number of elements
      NB=`grep -o 'exp' /tmp/data | wc -l`
      # 2. write the new element
      prepareForAdd=$(cat /tmp/data | sed 's/}}}}/},/')
      strToAdd=$(echo \""s$((${NB} + 1))"\" :{ \"exp\" : \"$DATE\", \"name\" : \"$NAME\", \"price\" : \"$PRICE\", \"qty\" : \"$QTY\" }}}})
      # print the json file 
      resultant="$prepareForAdd $strToAdd"
      echo $resultant   

      echo "" > /tmp/data
      echo $resultant > /tmp/data

      # clear
      NB=0
      prepareForAdd=""
      resultant=""

      # echo $NB
      # echo "DATE : $DATE"
      # echo "NAME : $NAME"
      # echo "PRIX : $PRICE"
      # echo "QTTY : $QTY"
   elif [ "$ACTION" = "2" ]; then
      # This is the old way of giving back the json to the client
      # cat /tmp/data

      # Here is the way I am wanting to do it
      # jsonifier("use staples_database; select * from staples_root") > /tmp/data.json 
      # cat /tmp/data.json
   elif [ "$ACTION" = "3" ]; then
      echo "Delete function is WIP"
   fi
fi

exit 0

