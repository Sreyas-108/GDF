const fs= require('fs');
const express = require('express');
const app = express();
const hostname = '127.0.0.1'; // Local host ip.
const homebase=fs.readFileSync('./with_radio_final.html');
const q_out = fs.readFileSync('./q_out_list.html');
const query=require('./query').query;
express.static('.');

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
    query(type, sub, pred, obj);
  }
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.write(homebase);
  res.end();
});

app.get('/q_out_list.html', (req, res) =>{
  console.log("IN");
  const q_out = fs.readFileSync('./q_out_list.html');
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.write(q_out);
  res.end();
});

app.get('/render.html', (req, res) =>{
  const rend = fs.readFileSync('./render.html');
  res.statusCode = 200;
  res.setHeader = ('Content-Type', 'text/html');
  res.write(rend);
  res.end();
});

app.get('/renderer.js', (req, res) =>{
  const renderer = fs.readFileSync('./renderer.js');
  res.statusCode = 200;
  res.setHeader = ('Content-Type', 'text/javascript');
  res.write(renderer);
  res.end();
});


//PORT
const port = process.env.PORT || 3000

app.listen(port, hostname, function() {
  console.log('Server running at http://'+ hostname + ':' + port + '/');
});
