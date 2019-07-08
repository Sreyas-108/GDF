var testStringShort=""
var NODE_COLOR='#fd153c'
var graphviz = d3.select("#graph")
	.graphviz()
    .logEvents(true)
    .on("initEnd", render);

var n_nodes=0,n_edges=0;

function render(filename) {
	graphviz
    var dot=getDOTfromGDF(filename);
    console.log('DOT OBTAINED')
    graphviz
    	.renderDot(dot);
}
function getLabel(string)
{
	if(string.indexOf('/')==-1)return string;
	return string.split('/').pop()
}
function randomColor()
{
	return '#'+(Math.random()*0xFFFFFF<<0).toString(16);
}
function randomColorString(string)
{
	var hash = 0, i, chr;
	if (string.length === 0) return hash;
	for (i = 0; i < string.length; i++) {
		chr   = string.charCodeAt(i);
		hash  = ((hash << 5) - hash) + chr;
		hash |= 0; // Convert to 32bit integer
	}
	hash = hash & 0xFFFFFF;
	return '#'+hash.toString(16);
}
//DOT documentation: https://www.graphviz.org/doc/info/attrs.html#d:center
function getDOTfromGDF(filename) {
	//read file
	var dotArray=[]
	dotArray.push('digraph G {')
	dotArray.push('node [style="filled"];')
	dotArray.push('size = "16.66,8.33!";') // 1200x600 at 72px/in, "!" to force
	dotArray.push('ratio = "fill";')
	dotArray.push('center = "true";')
	dotArray.push('bgcolor="#64F0F0";')
	/*const fs = require('fs') 
	fs.readFile(filename, 'ascii', (err, data) => { 
	    if (err) throw err; 
	    var lines=data.toString().split("\n") 
	    console.log(lines)
	})*/
	var lines=testStringShort.toString().split("\n")
	var nodes=[]
	var edge_description=[]
	for (var i = 0; i < lines.length; ++i) {
          lines[i] = lines[i].trim()
          var words=lines[i].split('|')
          //Add node to nodes if not already added along with label
          nodes.push(getLabel(words[1]));
          //nodes.push(getLabel(words[3]));
          nodes.push(getLabel(words[5]));
          //Add edge_description
          var label=getLabel(words[3])
          var QUERY_URL='/../?type=Search&Subject=?&Predicate='+label+'&ObjecT=?&shapes=svg'
          edge_description.push(getLabel(words[1])+' -> '+getLabel(words[5])+'['+'label="'+getLabel(words[3])+'", color="'+randomColorString(getLabel(words[1]))+'", URL="'+QUERY_URL+'", target= "_parent"];')
          n_edges++;
       }
    new Set(nodes).forEach(function(value1,value2,set){
    	var label=getLabel(value1)
    	n_nodes++;
    	var QUERY_URL='/../?type=Search&Subject='+label+'&Predicate=?&ObjecT=?&shapes=svg'
    	dotArray.push(label+' [ '+'label="'+label+'", fillcolor="'+randomColor()+'", URL="'+QUERY_URL+'", target= "_parent"];')
    })
    dotArray=dotArray.concat(edge_description);
	dotArray.push('}')
	console.log(n_nodes) 
	console.log(n_edges)
	var dot = dotArray.join('');
	return dot
}
