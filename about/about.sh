#!/bin/bash

function about {
    filename=$1
    IFS='.'

    fileArr=()
    read -ra fileArr <<< "$filename"

    tmpname1=${fileArr[0]}_tmp1.gdf
    
    count=0

    while IFS= read -r line
    do
        if [[ $count -eq 0 ]]
        then
            echo "$line" > "$tmpname1"
        else
            echo "$line" >> "$tmpname1"
        fi
        let count=$count+1
    done < "$1"

    
    tmpname2=${fileArr[0]}_tmp2.gdf
    sort -k 2,2 --field-separator='|' "$tmpname1" > "$tmpname2"

    IFS='|'

    tmpname3=${fileArr[0]}_tmp3.gdf

    count=0
    while IFS= read -r line
    do
        IFS='|'
        segment=()
        read -ra segment <<< "$line"

        if [[ $count -eq 0 ]]
        then
            echo "${segment[1]}" > $tmpname3
        else
            echo "${segment[1]}" >> $tmpname3
        fi
        let count=$count+1
    done < "$tmpname2"

    aboutFile=${fileArr[0]}_about.gdf
    uniq "$tmpname3" > "$aboutFile"
    rm $tmpname1 $tmpname2 $tmpname3
    IFS=' '
}

about $@
