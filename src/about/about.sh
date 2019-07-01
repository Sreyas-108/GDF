#!/bin/bash

#### Function to generate a file that will have name of all the unique subjects

function about {
    filename=$1
    IFS='.'                                 #delimiter set to '.'
    
    
    fileArr=()                              
    read -ra fileArr <<< "$filename"        #Split the name of File using '.' as the delimiter

    tmpname1=${fileArr[0]}_tmp1.gdf         #Create name of 1st temporary file
    
    count=0

    #### This loop will copy the content of the GDF file as the input into another temporary file ####

    while IFS= read -r line                 #Read the file line by line
    do
        if [[ $count -eq 0 ]]               #For the 1st iteration, create the file
        then
            echo "$line" > "$tmpname1"
        else
            echo "$line" >> "$tmpname1"     #For other iterations, append to the file
        fi
        let count=$count+1
    done < "$1"                             

    
    tmpname2=${fileArr[0]}_tmp2.gdf         #Create name of the 2nd temporary file
    sort -k 2,2 --field-separator='|' "$tmpname1" > "$tmpname2"     #Sort the data in 1st temporary file and store it in the 2nd

    IFS='|'                                 #Now, set delimiter as '|'

    tmpname3=${fileArr[0]}_tmp3.gdf         #Create name of the 3rd temporary file

    count=0

    ###Copy the subjects from the sorted data in 2nd temporary file into the 3rd temporary file
    ###Since data in 2nd tmp file is delimited by '|', we can split using this delimiter and store the result in array
    ###The 0th entity in array is the subject

    while IFS= read -r line
    do
        IFS='|'
        segment=()
        read -ra segment <<< "$line"

        if [[ $count -eq 0 ]]                   #For the 1st iteration create the file
        then
            echo "${segment[1]}" > $tmpname3
        else                                    #For other iterations, append to the file
            echo "${segment[1]}" >> $tmpname3
        fi
        let count=$count+1
    done < "$tmpname2"

    aboutFile=${fileArr[0]}_about.gdf       #Create the final output file with name inputName_output.gdf
    uniq "$tmpname3" > "$aboutFile"         #Copy only the unique data of 3rd tmp file into the output file
    rm $tmpname1 $tmpname2 $tmpname3        #Remove all the temporary files
    IFS=' '                                 #Set the delimiter to its default value
}

about $@            #Call the functions with all the arguments
