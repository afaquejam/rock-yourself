#!/bin/bash

prefix="http://www.youtube.com/results?search_query="
suffix="+lyrics"

while read line; do    
    modified=`echo $line | sed 's/ /+/g'`
    wget -O resultPage $prefix$modified$suffix
    theurl=`sed -n "/id=\"search-results\"/,/<\/span>/p" resultPage | grep -io 'href.*" c' | grep -o '".*"' | sed 's/"/"www.youtube.com/'| sed 's/"//g'`
    echo $theurl
    youtube-dl -o videofile $theurl
    filename=`echo $line | sed 's/ /_/g'`
    ffmpeg -i videofile -f mp3 -ab 192000 -vn $filename.mp3
    rm resultPage videofile
done < songslist
