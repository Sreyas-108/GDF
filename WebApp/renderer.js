var testString='e7afc19d587c0f150fc8a17f53a435ea|/GDF/res/Ashish||GDF/pred/teaches||GDF/res/Swadesh|\n24f9de24d1167fd7183125b4e2a0df14|/GDF/res/Ashish||GDF/pred/teaches||GDF/res/Anshuman|\ne7d31f842e4add67b11ce861da6bd2ec|/GDF/res/Ashish||GDF/pred/teaches||GDF/res/Samir|\nf1d4d47f8bc39de40923ccb8c06e6025|/GDF/res/Shan||GDF/pred/teaches||GDF/res/Ayush|\n7a37f2c6d56a6189c675953027bf343e|/GDF/res/Shan||GDF/pred/teaches||GDF/res/Arvind|\nb5a33f6ea8d681ac90cb45eca011af13|/GDF/res/Shan||GDF/pred/teaches||GDF/res/Kavi|\n6b90c4cd77e5a136139549f38dd67a49|/GDF/res/Shan||GDF/pred/teaches||GDF/res/Ritu|\na37b48e083d6abb0dfebd61d5a2d9f9d|/GDF/res/Shan||GDF/pred/teaches||GDF/res/Jaya|'

function render(filename) {
    var dot=getDOTfromGDF(filename);
    graphviz.renderDot(dot);
}

function getDOTfromGDF(filename) {
	//read file
	var dotString='digraph G {\n'
	/*const fs = require('fs') 
	fs.readFile(filename, 'ascii', (err, data) => { 
	    if (err) throw err; 
	    var lines=data.toString().split("\n") 
	    console.log(lines)
	})*/
	var lines=testString.toString().split("\n");
	console.log(lines)
	var nodes=[]
	var node_description=''
	var edge_description=''
	for (var i = 0; i < names.length; ++i) {
          lines[i] = lines[i].trim()
          var words=lines[i].split('|')
          //Add node to nodes if not already added along with label
          //Add edge_description
       }
	dotString=dotString+'}'
	return dotString
}