const http=require('http');
var exec=require('child_process').exec;
function runScr(sub,pred,obj)
{
	var str='./search "<'+sub+','+pred+','+obj+'>"';

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
}
