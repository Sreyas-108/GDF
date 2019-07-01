SUBJECT: Text to GDF Convertor
-------------------------------------------------------------------------------------------------------------------------------------------
RELATED FUNCTIONS: 
                    xtoGDF()    :  Requires filename of the text file as the only command line argument
-------------------------------------------------------------------------------------------------------------------------------------------
OUTPUT:
                    The command is a silent command. A new file with the same name as the input file (but with .gdf extension) will be generated containing the GDF format
-------------------------------------------------------------------------------------------------------------------------------------------
SYNOPSIS:

Section 1: TEXT FILE FORMAT

    The text file must be formtted by the following rules:

    a) Each line must have only one entry
    b) Multiple enteries (i.e. lines) must be seperated by a newline (\n) character
    c) Each line should have the following format:
    
        Subject_Name|Predicate_Name|Object_Name|Subject_Qualifier|Predicate_Qualifier|Object_Qualifier
    
        NOTE:
        c.1) All or any enteries can be omitted
    
        c.2) If an entry from the middle of the format is omitted, even then the delimiters (i.e. |) must be kept
             Eg: Yash|likes|IceCream|Intelligent||Chocolate

            But if the entry omitted is not in the middle of the format, then successive enteries can be omitted too
            Eg: Yash|likes|IceCream

        c.3) If a line doesn't contain any entry, GDF format will be : UID||||||
------------------------------------------------------------------------------------------------------------------------------------------
Section 2: THE GDF FORMAT

    The output file has the following format:

    a) Corresponding to each entry(i.e. line) of the text file, an entry is written in .gdf file
    b) Multiple enteries are separated by newline character
    c) Each line has the following format:
    
        UID|Subject_Name|Subject_Qualifier|Predicate_Name|Predicate_Qualifier|Object_Name|Object_Qualifier

        NOTE:
        c.1) UID is generated as the md5sum hash of (SubjectName' 'Predicate_Name' 'ObjectName). Here ' ' indicates a space

        c.2) Based on the input, each entry can have any or all enteries omitted. But delimiter '|' would still be present
------------------------------------------------------------------------------------------------------------------------------------------
