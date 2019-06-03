import numpy as np
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

teaches=createCrossData(teachers,students)
eats=createCrossData(people,fooditems)
registeredIn=createCrossData(students,courses)

tripTeaches=createTripletStrings(teaches,'teaches')
tripEats=createTripletStrings(eats,'likesToEat')
tripReg=createTripletStrings(registeredIn,'registeredIn')

tripAll=tripTeaches+tripReg+tripEats

printStringListToFile(tripAll,filename='sampleData.txt')

