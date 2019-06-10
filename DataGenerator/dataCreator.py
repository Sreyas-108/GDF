#import numpy as np
import random
students=['Yashdeep','Vipin','Suyash','Sreyas','Abhinava','Ayush','Sid','Anirudh','Arvind','Ravi','Kavi','Isha','Ritu','Jaya','Kapil','Divya','Pankaj','Sashan','Sushakt','Pratik','Saksham','Rachit','Shivam','Shalvi','Akriti','Bhoomi','Kavya','Sahil','Sargun','Swadesh','Kshitij','Anshuman','Samir']
teachers=['Ashish','Shan','Geeta','Ashu','Nago','Pogo','Sanjay','Sunita','Kalpana','GN','Mukesh','Suresh','Rohil','Ramesh','Manoj','Raman','Kannan','Sundar','Vishal','Amit','Kamlesh','Jenny']
fooditems=['Dosa','Pavbhaji','VadaPav','AlooParatha','BreadButter','BreadJam','BhelPuri','PaneerTikka','ShahiPaneer','Kadhi','Biryani','FriedRice','Pizza','Burger','Sandwich']
people=students+teachers
courses=['DSA','DBS','MuP','DD','POE','POM','DISCO','OOP','PAVA','CP','ES','TRW','MeOW','Thermo','M1','M2','M3','PnS','Bio','PPL','CompArch','DAA']


def createCrossData(list1,list2):
	cross=[]
	for l1 in list1:
		for l2 in list2:
			if random.randint(0,1)==1:
				cross.append((l1,l2))
	return cross

def createTripletStrings(crossTable,predName):
	tripletList=[]
	for l1,l2 in crossTable:
		tripletList.append(l1+'|'+predName+'|'+l2)
	return tripletList

def printStringListToFile(stringList,filename):
	file = open(filename,'w')
	for string in stringList:
		file.write(string)
		file.write('\n')


def isDataThere(text):
    fhandle=open('metadata.txt','r')
    
    lines=fhandle.readlines()

    for line in lines:
        line=line.rstrip()
        items=line.split('|')

        compare=items[0]
        if compare==text:
            fhandle.close()
            return True
    fhandle.close()
    return False
    

def printStudentMetadata(crossTable1,crossTable2,crossTable3):
    f=open('metadata.txt','a+')
    string='|memberOf|student'
    
    for t,s in crossTable1:
        if f.closed==False:
            f.close()
        if isDataThere(s)==False:
            f=open('metadata.txt','a+')
            f.write(s+string+'\n')

    for s,fo in crossTable2:
        if f.closed==False:
            f.close()
        if students.count(s)!=0 and isDataThere(s)==False:
            f=open('metadata.txt','a+')
            f.write(s+string+'\n')

    for s,co in crossTable3:
        if f.closed==False:
            f.close()
        if isDataThere(s)==False:
            f=open('metadata.txt','a+')
            f.write(s+string+'\n')

def printTeacherMetadata(crossTable1,crossTable2):
    f=open('metadata.txt','a+')
    string='|memberOf|teacher'
    
    for t,s in crossTable1:
        if f.closed==False:
            f.close()
        if isDataThere(t)==False:
            f=open('metadata.txt','a+')
            f.write(t+string+'\n')

    for s,fo in crossTable2:
        if f.closed==False:
            f.close()
        if teachers.count(s)!=0 and isDataThere(s)==False:
            f=open('metadata.txt','a+')
            f.write(s+string+'\n')

def printFoodMetadata(crossTable1):
    f=open('metadata.txt','a+')
    string='|memberOf|foodItem'
    
    for s,fo in crossTable1:
        if f.closed==False:
            f.close()
        if isDataThere(fo)==False:
            f=open('metadata.txt','a+')
            f.write(fo+string+'\n')

def printCourseMetadata(crossTable1):
    f=open('metadata.txt','a+')
    string='|memberOf|course'

    for s,co in crossTable1:
        if f.closed==False:
            f.close()
        if isDataThere(co)==False:
            f=open('metadata.txt','a+')
            f.write(co+string+'\n')

teaches=createCrossData(teachers,students)
eats=createCrossData(people,fooditems)
registeredIn=createCrossData(students,courses)

tripTeaches=createTripletStrings(teaches,'teaches')
tripEats=createTripletStrings(eats,'likesToEat')
tripReg=createTripletStrings(registeredIn,'registeredIn')

tripAll=tripTeaches+tripReg+tripEats
printStringListToFile(tripAll,filename='sampleData.txt')

printStudentMetadata(teaches,eats,registeredIn)
printTeacherMetadata(teaches,eats)
printFoodMetadata(eats)
printCourseMetadata(registeredIn)
