#include "Parser.h"
#define MAX 512

char ** solveSimpleSelectQueryCase1(char* subject,char* predicate,char* object)
{
	//Case 1
		//If Subject is a resource and predicate and object can be anything resource or a query

		char ** triples;

		int j=0;
		
		if(subject!=NULL)
		{
				int len=strlen(subject);
				subject=(char *)realloc(subject, sizeof(char)*(len+4));	//reallocate memory for subject to be able to append .gdf

				subject[len]='.';
				subject[len+1]='g';
				subject[len+2]='d';
				subject[len+3]='f';
				subject[len+4]='\0';					
				
				FILE *fp=fopen(subject,"r");				//Open the file in read mode

				if(fp==NULL)							//If file opening fails, return
						return;

				int n1,n2,n3;

				fscanf(fp,"#%d,%d,%d",&n1,&n2,&n3);		//Get the first line


				triples=(char **)malloc(sizeof(char *)*n1);		

				char arr[10];
				fscanf(fp,"%s",arr);	//eat up the metadata URI line

				fscanf(fp,"%s",arr);	//eat up the line @subject

				/*if(predicate==NULL && object==NULL)
				{
						while(n1--)
						{
							triples[j]=(char *)malloc(sizeof(char)*10);
							size2=10;
							char ch;
							bool stop=false;
							while(!stop)
							{
									k=0;
									fscanf(fp,"%c",&ch);
									if(ch!='\n')
									{
											if(reallCount2>size2)
											{
													size2*=2;
													triples[j]=(char *)realloc(triples[j],size2);			
											}
											triples[j][k]=ch;
											k++;
									}
									else
											stop=true;
							}
							triples[j][k]='\0';
							j++;
						}
						triples[j]=NULL;
				}*/

				//The 3 subcases : (NULL,NULL) (Not NULL, NULL) (NULL, Not NULL)
				if((predicate!=NULL && object==NULL) || (predicate==NULL && object!=NULL) || (predicate==NULL && object==NULL))
				{
						char uid[MAX];
						char subQ[MAX];
						char objQ[MAX];
						char predQ[MAX];
						char obj[MAX];
						char sub[MAX];
						char pred[MAX];

						j=0;

						//Read all the tuples present in the subject.gdf file
						while(n1--)
						{
								fscanf(fp,"%s|%s|%s|%s|%s|%s|%s",uid,sub,subQ,pred,predQ,obj,objQ);
								
								if((object!=NULL && strcmp(obj,object)==0) || (predicate!=NULL && strcmp(pred,predicate)==0) || (predicate==NULL && object==NULL)) 
								{

									int tmp=strlen(uid)+strlen(sub)+strlen(subQ)+strlen(pred)+strlen(predQ)+strlen(obj)+strlen(objQ)+7;

									triples[j]=(char *)malloc(sizeof(char)*tmp);

									strcat(triples[j],uid);
									strcat(triples[j],"|\0");
									strcat(triples[j],sub);
									strcat(triples[j],"|\0");
									strcat(triples[j],subQ);
									strcat(triples[j],"|\0");
									strcat(triples[j],pred);
									strcat(triples[j],"|\0");
									strcat(triples[j],predQ);
									strcat(triples[j],"|\0");
									strcat(triples[j],obj);
									strcat(triples[j],"|\0");
									strcat(triples[j],objQ);
									j++;
								}
						}
						triples[j]=NULL;
				}

				//The final subcase (Not NULL, Not NULL)
				if(predicate!=NULL && object!=NULL)
				{
						bool found=false;
						while(n1--)			//Read all the tuples
						{

								//If found: triples will contain the input
								//else : it will return NULL pointer

								char uid[MAX];
								char subQ[MAX];
								char objQ[MAX];
								char predQ[MAX];
								char obj[MAX];
								char sub[MAX];
								char pred[MAX];

								fscanf(fp,"%s|%s|%s|%s|%s|%s|%s",uid,sub,subQ,pred,predQ,obj,objQ);
								

								if(strcmp(subject,sub)==0 && strcmp(obj,object)==0 && strcmp(pred,predicate)==0)
								{
									found=true;
									int tmp=strlen(uid)+strlen(sub)+strlen(subQ)+strlen(pred)+strlen(predQ)+strlen(obj)+strlen(objQ)+7;

									triples[0]=(char *)malloc(sizeof(char)*tmp);

									strcat(triples[j],uid);
									strcat(triples[j],"|\0");
									strcat(triples[j],sub);
									strcat(triples[j],"|\0");
									strcat(triples[j],subQ);
									strcat(triples[j],"|\0");
									strcat(triples[j],pred);
									strcat(triples[j],"|\0");
									strcat(triples[j],predQ);
									strcat(triples[j],"|\0");
									strcat(triples[j],obj);
									strcat(triples[j],"|\0");
									strcat(triples[j],objQ);
									break;
								}
						}
						if(found==false)
								triples[0]=NULL;
				}
		}
		else
				return;
		return triples;
}
