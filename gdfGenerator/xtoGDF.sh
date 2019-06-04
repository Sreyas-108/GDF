#!/bin/bash

function xtoGDF {
    filename=$1
    
    outname=''

    array=()
    sn=''
    pn=''
    on=''
    udi=''
    toWrite=''
    
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

        #code to create 7 column format
        read -ra array <<< "$line"
        sn=${array[0]}
        pn=${array[1]}
        on=${array[2]}
        
        cum="$sn $pn $on"
        uid=$(echo "$cum" | md5sum)

        IFS=' '
        read -ra uidArr <<< "$uid"
        IFS='|'
        
        uid=${uidArr[0]}

        #code to append data to GDF file
        toWrite="$uid|${array[0]}||${array[1]}||${array[2]}|"
       
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
