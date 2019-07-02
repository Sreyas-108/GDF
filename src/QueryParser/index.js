const fs= require('fs');
const express = require('express');
const app = express();
const hostname = '127.0.0.1'; // Local host ip.
const homebase=fs.readFileSync('../WebApp/with_radio_final.html');
const query=require('./query').query;
//var server = http.createServer(function(req, res) {
//  res.statusCode = 200;
//  res.setHeader('Content-Type', 'text/html');
//  res.write(homebase);
//  res.end();
//});

app.get('/',(req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.write(homebase);
  res.end();
});

app.get('./index.html',(req, res) => {
  sub=req.query['Subject'];
  pred=req.query['Predicate'];
  obj=req.query['Object'];
  type=req.query['Query'];
  query(type, sub, pred, obj);
});

//PORT
const port = process.env.PORT || 3000

app.listen(port, hostname, function() {
  console.log('Server running at http://'+ hostname + ':' + port + '/');
});
