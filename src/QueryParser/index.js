const fs= require('fs');
const express = require('express');
const app = express();
const hostname = '127.0.0.1'; // Local host ip.
const homebase = fs.readFileSync('./with_radio_final.html');
//const q_out=fs.readFileSync('./q_out_list.html');

var execSync = require('child_process').execSync, child;
express.static('.');
var sub="";
var obj="";
var pred="";
var type="";
app.use(express.static('.'));


app.get('/',(req, res) => {
   sub=req.query['Subject'];
   pred=req.query['Predicate'];
   obj=req.query['ObjecT'];
   type=req.query['type'];
  
   if(sub != undefined){
    console.log("SUBJECT= "+sub);
    console.log("PREDICATE= "+pred);
    console.log("OBJECT= "+obj);
    console.log("TYPE= "+type);
    //query(type, sub, pred, obj);
    }
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.write(homebase);
  res.end();
});

app.get('/q_out_list.html', (req, res) =>{
  console.log("In q_out");
  if(sub!=undefined)
  {
  	if(type==='Search')
        	str = './search "<'+sub+','+pred+','+obj+'>" > temp';
  	if(type==='Create')
        	str = './create "<'+sub+','+pred+','+obj+'>" > temp';
  	if(type==='Delete')
        	str = './delete "<'+sub+','+pred+','+obj+'>" > temp';
  	//console.log(str);
 	const stdout1 = execSync(str);
     	const stdout2 = execSync('bash create_q_out_list.sh');
     	const q_out = fs.readFileSync('./q_out_list.html');
 	res.statusCode = 200;
  	res.setHeader('Content-Type', 'text/html');
  	res.write(q_out);
	const stdout3= execSync('rm temp');
	const stdout4= execSync('rm ./q_out_list.html');
	res.end();
  }	
});

app.get('/render.html', (req, res) =>{
 if(sub!=undefined)
  {
  	if(type==='Search')
        	str = './search "<'+sub+','+pred+','+obj+'>" > temp';
  	if(type==='Create')
        	str = './create "<'+sub+','+pred+','+obj+'>" > temp';
  	if(type==='Delete')
        	str = './delete "<'+sub+','+pred+','+obj+'>" > temp';
  	//console.log(str);
 	const stdout1 = execSync(str);
	const stdout5= execSync('mv ren render.html');
     	const stdout2 = execSync('bash replaceString.sh');
	const rend = fs.readFileSync('./render.html');
	res.statusCode = 200;
  	res.setHeader('Content-Type', 'text/html');
  	res.write(rend);
	const stdout3= execSync('rm temp');
	const stdout4=execSync('mv render.html ren');
	res.end();
  }	 
});

/*app.get('/renderer.js', (req, res) =>{
  let renderer = fs.readFileSync('./renderer.js');
 
  res.statusCode = 200;
  res.setHeader = ('Content-Type', 'text/javascript');
  res.write(renderer);
  res.end();
});*/


//PORT
const port = process.env.PORT || 3000

app.listen(port, hostname, function() {
  console.log('Server running at http://'+ hostname + ':' + port + '/');
});
