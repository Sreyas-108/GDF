var fs= require('fs');
var http = require('http');
var hostname = '127.0.0.1'; // Local host ip.
var port = 3000; // A temporary port.
var homebase=fs.readFileSync('./src/WebApp/with_radio_final.html');
var server = http.createServer(function(req, res) {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.write(homebase);
  res.end();
});
server.listen(port, hostname, function() {
  console.log('Server running at http://'+ hostname + ':' + port + '/');
});
