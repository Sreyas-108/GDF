#!/bin/bash

#This function parses the input file into 7-comlumn format to generate GDF file
#The function also generates the meta data file

function xtoGDF {
    filename=$1
    outname=''
    udi=''

    #code to extract the primary name of the file
    IFS='.'                             #Set the delimiter as '.'
    
    #fileArr=()
   #read -ra fileArr <<< "$filename"    #Get the name of the file without the extension
   # outname="${fileArr[0]}.gdf"         #Create name of the output file. It will have same name as input file with .gdf extension
    
   outname='dist.gdf';
    IFS='|'                             #Set the delimiter as '|'
    
    count=0

    ##This loop reads the input file line by line and generates the GDF tuples in 7-column format
    while IFS= read -r line
    do
        array=()
        uidArr=()

        ############ Code to create 7 column format ##############
        read -ra array <<< "$line"      #Read the line and split it using delimiter '|'

        ###After splitting#####
        ##  array[0]    is the  subject
        ##  array[1]    is the  subject qualifier
        ##  array[2]    is the  predicate
        ##  array[3]    is the  predicate qualifier
        ##  array[4]    is the  object
        ##  array[5]    is the  object qualifier

        cum="${array[0]} ${array[1]} ${array[2]}"
        uid=$(echo "$cum" | md5sum)         #uid is the md5sum of Subject' 'Predicate' 'Object

        ###The output of md5sum is hash value and some other information, both separated by space.
        ###Hence we will delimit the uid by ' '
        IFS=' '
	read -ra uidArr <<< "$uid"
        IFS='|'

        uid=${uidArr[0]}


        #toWrite contains the tuple in 7-column format
        toWrite="$uid|${array[0]}|${array[3]}|${array[1]}|${array[4]}|${array[2]}|${array[5]}"

        if [[ $count -eq 0 ]]           #For the 1st iteration, create the GDF file
        then
            echo "$toWrite" > "$outname"
        else                            #For other iterations, append to the GDF file
            echo "$toWrite" >> "$outname"
        
        fi

        let count=$count+1
    done < "$1"


    ###### Below code is to generate the metadata.GDF file

    IFS='|'         #Set the delimiter to '|'
    let count=0
    while IFS= read -r line     #Read the metadata.txt file line by line
    do
        read -ra array <<< "$line"          #Split the line by '|'
        
        ### array[0]    is the  Subject/Object/Predicate
        ### array[1]    is the  memberOf
        ### array[2]    is the  Node Type or Attribute Type
        cum="${array[0]} ${array[1]} ${array[2]}"       
        uid=$(echo "$cum" | md5sum)             #Again generated UID as the md5 sum of array[0]' 'array[1]' 'array[2]
        id=$(echo "${array[0]}" | md5sum)       #A unique ID is also generated for Subject/Object/Predicate

        ###Again, since md5sum gives hash and some other info delimited by ' ', we split by ' ' delimiter

        IFS=' '             
        read -ra uidArr <<< "$uid"
        read -ra idArr <<< "$id"
        IFS='|'


        uid=${uidArr[0]}
        id=${idArr[0]}

        #toWrite contains the tuple (7-column format) to be written in GDF
        #NOTE: qualifier for the subject/object/predicate in this file will be a unique id already generated

        toWrite="$uid|${array[0]}|$id|${array[1]}||${array[2]}"

        if [[ $count -eq 0 ]]                   #For the 1st iteration create the file
        then
            echo "$toWrite" > "metadata.gdf"
        else                                    #For other iterations append to the file
            echo "$toWrite" >> "metadata.gdf"
        fi
        let count=$count+1
    done < "$2"

    #set the IFS back to default
    IFS=' '
}

xtoGDF $@           #Call the function xtoGDF with all the arguments
