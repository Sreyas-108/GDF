/*const exec=require('child_process').exec;
function runScr(type,sub,pred,obj)
{
	var str="";
	if(tyep=='Query')
		str='./search "<'+sub+','+pred+','+obj+'>"';
	if(type=='Create')
		str='./create "<'+sub+','+pred+','+obj+'>"';
	if(type=='Delete')	
		str='./delete "<'+sub+','+pred+','+obj+'>"';
	console.log(str);
	exec(str, (err,stdout,stderr)=> {
		if(err)
		{
			console.error(err);
			return;
		}
		else
		{
			console.log(stdout);
		}
	});
}*/
function queryFun()
{
	var string=window.location.search.substring(1);
	var list=string.split('&');
	var subject;
	var predicate;
	var object;
	for(var i=0;i<3;i++)
	{
		var pair=list[i].split('=');
		if(i==0)
			subject=pair[1];
		if(i==1)
			predicate=pair[1];
		if(i==2)
			object=pair[1];
	}
	//runScr(type,subject,predicate,object);
	document.getElementById("subjectBox").innerHTML="shdfjkhasdlkfjh";
}
/*document.getElementById("queryButton").addEventListener("click",queryFun("Query"));
document.getElementById("createButton").addEventListener("click",queryFun("Create"));
document.getElementById("deleteButton").addEventListener("click",queryFun("Delete"));*/
