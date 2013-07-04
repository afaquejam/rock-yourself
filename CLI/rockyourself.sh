#!/bin/bash
# Brought to you by AKI

prefix="http://www.youtube.com/results?search_query="
suffix="+lyrics"

is_songslist_empty=`cat songslist | wc -l`
if [ $is_songslist_empty -eq 0 ]; then
	echo "\n Ok now we've got a problem here!\n Either you have not written something in your songslist or you have written just one line and have not pressed Enter before saving. \n In either case, write a line or more and make sure you hit enter before saving the songslist. \n Different software, Different rules! What can we do? \n"
else 
  while read line; do
    if [ -n "$line" ]; then
      search_query=`echo $line | sed 's/ /+/g'`
      wget --quiet -O resultPage $prefix$search_query$suffix
      isEmpty=`cat resultPage`

      if [ -n "$isEmpty" ]; then
        resource_url=`sed -n "/id=\"search-results\"/,/<\/span>/p" resultPage | grep -io 'href.*" c' | grep -o '".*"' | sed 's/"/"www.youtube.com/'| sed 's/"//g'`
        echo "\n Downloading $line stuff from the internet .... \n"
        youtube-dl -o videofile $resource_url

        if [ -f "videofile" ]; then
      	  echo "\n Stuff related to $line Downloaded. How about we add a little processing to it? \n"
      	  filename=`echo $line | sed 's/ /_/g'`
          ffmpeg -v 0 -i videofile -f mp3 -ab 192000 -vn $filename.mp3

          if [ -f "$filename.mp3" ]; then
            echo "\n Got $line stuff successfully, maybe :P \n" 
          else
            echo "\n Oops, something happened during processing. Probably the downloaded stuff was bad."
          fi 
          rm resultPage videofile
        else 
          echo "\n Check you SongsList Mate! May be Youtube got confused about $line. \n"
      	  rm resultPage
        fi 
    
      else
        echo "\n Well, this software kinda gets stuff from the Internet. Make sure you're connected to it. Cheers! \n"
      fi     
    fi
  done < songslist 
fi
