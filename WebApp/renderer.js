function render(filename) {
    var dot=getDOTfromGDF(filename);
    graphviz.renderDot(dot);
}

function getDOTfromGDF(filename) {
	//read file
	var dotString='digraph G {\n'
	const fs = require('fs') 
	fs.readFile(filename, 'ascii', (err, data) => { 
	    if (err) throw err; 
	    var lines=data.toString() 
	    console.log(lines)
	})
	dotString=dotString+'}'
	return dotString
}