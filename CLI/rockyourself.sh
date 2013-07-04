#!/bin/bash

prefix="http://www.youtube.com/results?search_query="
suffix="+lyrics"

while read line; do    
    search_query=`echo $line | sed 's/ /+/g'`
    wget --quiet -O resultPage $prefix$search_query$suffix
    isEmpty=`cat resultPage`
    if [ -n "$isEmpty" ]; then
      resource_url=`sed -n "/id=\"search-results\"/,/<\/span>/p" resultPage | grep -io 'href.*" c' | grep -o '".*"' | sed 's/"/"www.youtube.com/'| sed 's/"//g'`
      echo "\n Downloading $line stuff from the internet .... \n"
      youtube-dl -o videofile $resource_url

      if [ -f "videofile" ]; then
      	echo "\n Stuff related to $line Downloaded. How about we add a little processing to it?"
      	filename=`echo $line | sed 's/ /_/g'`
        ffmpeg -i videofile -f mp3 -ab 192000 -vn $filename.mp3

        if [ -f "$filename.mp3" ]; then
          echo "Got $line stuff successfully, maybe :P" 
        else
          echo "Oops, something happened during processing. Probably the downloaded stuff was bad."
        fi 
        rm resultPage videofile
      else 
        echo "\n Check you SongsList Mate! May be Youtube got confused about $line. \n"
      	rm resultPage
      fi 
      
    else
      echo "\n Well, this software kinda gets stuff from the Internet. Make sure you're connected to it. Cheers! \n"
    fi     
done < songslist
