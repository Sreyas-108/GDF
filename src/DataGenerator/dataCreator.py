import random
#Create some lists with dummy data
students=['Yashdeep','Vipin','Suyash','Sreyas','Abhinava','Ayush','Sid','Anirudh','Arvind','Ravi','Kavi','Isha','Ritu','Jaya','Kapil','Divya','Pankaj','Sashan','Sushakt','Pratik','Saksham','Rachit','Shivam','Shalvi','Akriti','Bhoomi','Kavya','Sahil','Sargun','Swadesh','Kshitij','Anshuman','Samir']
teachers=['Ashish','Shan','Geeta','Ashu','Nago','Pogo','Sanjay','Sunita','Kalpana','GN','Mukesh','Suresh','Rohil','Ramesh','Manoj','Raman','Kannan','Sundar','Vishal','Amit','Kamlesh','Jenny']
fooditems=['Dosa','Pavbhaji','VadaPav','AlooParatha','BreadButter','BreadJam','BhelPuri','PaneerTikka','ShahiPaneer','Kadhi','Biryani','FriedRice','Pizza','Burger','Sandwich']
people=students+teachers
courses=['DSA','DBS','MuP','DD','POE','POM','DISCO','OOP','PAVA','CP','ES','TRW','MeOW','Thermo','M1','M2','M3','PnS','Bio','PPL','CompArch','DAA']

METADATA_FILENAME='metadata.txt'

#This takes the cross product of two lists and then selects a subset of them essentially creating a relation
def createCrossData(list1,list2):
	cross=[]
	for l1 in list1:
		for l2 in list2:
			#Randomly choose whether or not to keep this tuple in the final relation
			if random.randint(0,1)==1:
				cross.append((l1,l2))
	return cross

#Converts the contents of the crosstable (l1,l2) from tuple format to String format 
def createTripletStrings(crossTable,predName):
	tripletList=[]
	for l1,l2 in crossTable:
		tripletList.append(l1+'|'+predName+'|'+l2)
	return tripletList

#Takes a list of strings as input and outputs each on a new line in the specified file
def printStringListToFile(stringList,filename):
	file = open(filename,'w')
	for string in stringList:
		file.write(string)
		file.write('\n')

#Checks if the given key is already present as a subject in the MetaData file
def isSubjectPresent(key):
    fhandle=open(METADATA_FILENAME,'r')
    #Reads all lines of the metadata file
    lines=fhandle.readlines()

    for line in lines:
        line=line.rstrip()
        items=line.split('|')
        #Split the triplet into 3 and choose the first one(subject)
        subject=items[0]
        if subject==key:
            fhandle.close()
            return True
    fhandle.close()
    return False

#Prints the student metadata
def printStudentMetadata(crossTable1,crossTable2,crossTable3):
    f=open(METADATA_FILENAME,'a+')
    string='|memberOf|student'
    
    #Adds all students whose names appear in any relation to the metadata file
    for t,s in crossTable1:
    	#Make sure the file is closed before opening in another mode
        if f.closed==False:
            f.close()
        #If the name is not already present in the metadata file,add it.
        if isSubjectPresent(s)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(s+string+'\n')

    for s,fo in crossTable2:
        if f.closed==False:
            f.close()
        if students.count(s)!=0 and isSubjectPresent(s)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(s+string+'\n')

    for s,co in crossTable3:
        if f.closed==False:
            f.close()
        if isSubjectPresent(s)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(s+string+'\n')
#Prints the teacher metadata
def printTeacherMetadata(crossTable1,crossTable2):
    f=open(METADATA_FILENAME,'a+')
    string='|memberOf|teacher'
    #Adds all teachers whose names appear in any relation to the metadata file
    for t,s in crossTable1:
    	#Make sure the file is closed before opening in another mode
        if f.closed==False:
            f.close()
        #If the name is not already present in the metadata file,add it.
        if isSubjectPresent(t)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(t+string+'\n')

    for s,fo in crossTable2:
        if f.closed==False:
            f.close()
        if teachers.count(s)!=0 and isSubjectPresent(s)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(s+string+'\n')
#Prints the fooditems metadata
def printFoodMetadata(crossTable1):
    f=open(METADATA_FILENAME,'a+')
    string='|memberOf|foodItem'
    #Adds all fooditems whose names appear in any relation to the metadata file
    for s,fo in crossTable1:
    	#Make sure the file is closed before opening in another mode
        if f.closed==False:
            f.close()
        #If the name is not already present in the metadata file,add it.
        if isSubjectPresent(fo)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(fo+string+'\n')
#Prints the courses metadata
def printCourseMetadata(crossTable1):
    f=open(METADATA_FILENAME,'a+')
    string='|memberOf|course'
    #Adds all courses whose names appear in any relation to the metadata file
    for s,co in crossTable1:
    	#Make sure the file is closed before opening in another mode
        if f.closed==False:
            f.close()
        #If the name is not already present in the metadata file,add it.
        if isSubjectPresent(co)==False:
            f=open(METADATA_FILENAME,'a+')
            f.write(co+string+'\n')

#Create some dummy relations
teaches=createCrossData(teachers,students)
eats=createCrossData(people,fooditems)
registeredIn=createCrossData(students,courses)

#Generate triplets from the relations
tripTeaches=createTripletStrings(teaches,'teaches')
tripEats=createTripletStrings(eats,'likesToEat')
tripReg=createTripletStrings(registeredIn,'registeredIn')

#Take all triplet strings into a single list and output them to a file
tripAll=tripTeaches+tripReg+tripEats
printStringListToFile(tripAll,filename='sampleData.txt')

#print Metadata to a file METADATA_FILENAME
printStudentMetadata(teaches,eats,registeredIn)
printTeacherMetadata(teaches,eats)
printFoodMetadata(eats)
printCourseMetadata(registeredIn)
