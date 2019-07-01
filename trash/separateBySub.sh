#!/bin/bash
function separateBySub
{
	filename=$1									
	outname=''
	rel=(NaN NaN NaN NaN NaN NaN NaN)
	IFS=$'\n'			
	while read line										#Loop to go through each relation in a gdf file
	do
		IFS='|' read -r -a rel<<<"$line"				#Reading the line into array 'rel' separated by '|'
		local outfile=${rel[1]}.gdf
		flag=$(ls | grep $outfile)						#Flag to check for existence of the filename
		if [[ -z $flag ]]
		then
			touch $outfile								#Creating the file from subject's name if it doesn't exist
		fi
		echo $line >> $outfile							#Appending the relation
		IFS=$'\n'
	done < $filename
}

separateBySub $@										#calling the function