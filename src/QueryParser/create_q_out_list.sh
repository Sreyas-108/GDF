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
	while read -r line									#Loop to go through each relation in an html file
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
