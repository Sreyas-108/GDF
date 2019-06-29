var http = require("http");
var fs = require("fs");
var cp= require("child_process"); 
http.createServer(function (req, res) {
	var out=cp.spawn('./exe',['"<Jenny,?,?>"']);
	res.write(out);
}).listen(8080);


