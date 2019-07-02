const exec=require('child_process').exec;
var methods = {
	runScr: function(type,sub,pred,obj)
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
	}
};

module.exports=methods;
