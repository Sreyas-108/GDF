#!/bin/bash
function createPage
{
	filename='temp'									
	outfile='q_out_list.html'	
    echo "<html>" > $outfile
	echo "<head>" >> $outfile
	echo "<title>" >> $outfile
	echo "List of Query Results" >> $outfile
	echo "</title>" >> $outfile
	echo "</head>" >> $outfile
	echo "<body>" >> $outfile
	echo "<ul>" >> $outfile
<<<<<<< HEAD
	while read -r line									#Loop to go through each relation in an html file
||||||| merged common ancestors
	IFS=$'\n'			
	while read line										#Loop to go through each relation in an html file
=======
	IFS=$'\n'			
	while read line						#Loop to go through each relation in an html file
>>>>>>> 92501922a95c19c88e3ff80e3a078a4666fadde8
	do
		echo "<li>$line</li>" >> $outfile
		echo $line
	done < $filename
	echo "</ul>" >> $outfile
	echo "</body>" >> $outfile
	echo "</html>" >> $outfile
	rm temp
}

createPage $@
