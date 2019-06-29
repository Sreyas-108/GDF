const http = require('http');
const hostname = '127.0.0.1'; // Local host ip.
const port = 3000; // A temporary port.
const server = http.createServer(function(req, res) {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Home page will come here.\n');
});
server.listen(port, hostname, function() {
  console.log('Server running at http://'+ hostname + ':' + port + '/');
});