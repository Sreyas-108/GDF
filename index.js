const http = require('http');
const hostname = '127.0.0.1'; // Local host ip.
const port = 3000; // A temporary port.
const homebase=fs.readFile('./src/WebApp/with_radio_final.htm', function (err, html) {
    if (err) {
        throw err; 
    }
});
const server = http.createServer(function(req, res) {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  response.write(homebase);
  res.end();
});
server.listen(port, hostname, function() {
  console.log('Server running at http://'+ hostname + ':' + port + '/');
});
