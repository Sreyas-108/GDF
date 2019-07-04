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
	IFS=$'\n'			
	while read line										#Loop to go through each relation in a gdf file
	do
		IFS='|' read -r -a rel<<<"$line"				#Reading the line into array 'rel' separated by '|'
		echo "<li>$line</li>" >> $outfile
	done < $filename
	echo "</ul>" >> $outfile
	echo "</body>" >> $outfile
	echo "</html>" >> $outfile
}

createPage $@