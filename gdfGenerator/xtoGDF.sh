#!/bin/bash

function xtoGDF {
    filename=$1
    
    outname=''
    
    udi=''
    
    #code to extract the primary name of the file
    IFS='.'
    fileArr=()
    read -ra fileArr <<< "$filename"
    outname="${fileArr[0]}.gdf"
    
    IFS='|'
    
    count=0
    while IFS= read -r line
    do
        array=()
        uidArr=()

        ############ Code to create 7 column format ##############
        read -ra array <<< "$line"


        cum="${array[0]} ${array[1]} ${array[2]}"
        uid=$(echo "$cum" | md5sum)

        IFS=' '
        read -ra uidArr <<< "$uid"
        IFS='|'

        uid=${uidArr[0]}

        ############# Code to append data to GDF file #############
        toWrite="$uid|${array[0]}|${array[3]}|${array[1]}|${array[4]}|${array[2]}|${array[5]}"
        if [[ $count -eq 0 ]]
        then
            echo "$toWrite" > "$outname"
        else
            echo "$toWrite" >> "$outname"
        
        fi

        let count=$count+1
    done < "$1"

    #set the IFS back to default
    IFS=' '
}

xtoGDF $@
