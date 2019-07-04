#!/bin/bash
function replaceString
{
	filename='temp'
	string=''
	count=0
	while read -r line
	do
		if [[ $count -eq 0 ]]
		then
			string=$line
		else
			string=$string'\\n'$line
		fi
		count=$count+1
	done < $filename	
	string="var testStringShort=\"$string\""
	#echo $string
	filename='renderer.js'
	sed -i "0,/testStringShort/c $string" $filename
}

replaceString $@
