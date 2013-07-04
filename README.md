A project to get some stuff from the internet. Mostly interesting stuff. 

Requirements: A computer with Ubuntu Linux some kind of internet connectivity.
Depends: wget, youtube-dl, ffmpeg
If you don't have these, install them by using apt-get install ...

Download the debian package, install it using ubuntu software center or using command line:
sudo dpkg -i package-rockyourself_1.0_all.deb

Thatś it! It's installed.

Command line usage:
open up terminal.
Just create a text file containing list of your song queries as you search in YouTube. For best results write first the artist name followed by the song name. For example you can create file named songslist having contents:

linkin park papercut
wiz khalifa we own it 
bon jovi its my life

// End of file. Make sure you end your file with an empty line. No need to include this line.

After saving just run this command:
rockyourself songslist

and watch the magic. Within minutes your music files will be in the folder where you ran the command.

In case you are not happy with this stuff, then you can simply remove by using this command:
aptitude remove package-rockyourself

There you go, be happy!

Note: This is a software, it will provide you correct results for correct input. Make sure you input some meaningfull. For example if you just put like bon jovi, then how does the computer know to  which song it has downlaod. Well, it downloads the most popular song of that artist. Don't put something weird like robin hood song. You will be surprised with the results.


Here are of the test cases against which I have tested the software: 

0. Install wget, youtube-dl and ffmpeg if not installed.
1. No internet connection/ problem with the wget.
2. Failed to Dowload video, youtube-dl error. 
3. Failed to convert to mp3/ ffmpeg error.

4. The songlist file is empty or no LF character.
5. Blank lines in between the song entries.
6. All garbage enteries.
7. Starts with a garbage entry.
8. Alternating garbage entries.
9. Ends with a garbage entry.