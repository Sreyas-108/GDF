var testStringShort="9aaaf10b0ccdd7db51af3d45dfdb8dc4|Vipin||likesToEat||Sandwich|\n6a3d1bf8f74b4d9a8a11ecb49cf0f3b9|Vipin||likesToEat||Burger|\n99f278c120019dce576d4df6713b5289|Vipin||likesToEat||Kadhi|\n2b5387593d4caf0934fb99ec545c819b|Vipin||likesToEat||BreadJam|\n9ccc2530ab4fb3d67b68e5d1db648cf5|Vipin||likesToEat||AlooParatha|\n2a3464b47194a57e456d462a296dfa58|Vipin||likesToEat||VadaPav|\nd06dd3879ef78682ea8d24372032d2ca|Vipin||likesToEat||Pavbhaji|\nc019275a2007d802d3ea0ad999abbee9|Vipin||likesToEat||Dosa|\n6d8cd44b133e8db3da6a996ba36269ef|Vipin||registeredIn||PPL|\nfc589234685992a4c0c93b7d03a403fe|Vipin||registeredIn||PnS|\ne2001b30b9d3e5ca86a23fd1c76524be|Vipin||registeredIn||M3|\n9280b721ede20e212d198b0e076d442c|Vipin||registeredIn||M2|\n772efd7e4996dcf42aea2c85470ab48b|Vipin||registeredIn||M1|\ne61c3c4d5f87e0b7cf690d7cf12a6435|Vipin||registeredIn||Thermo|\nd32cf984bce04def1cf9153c19560da4|Vipin||registeredIn||MeOW|\nfcd7e6646041973f09986d7dc57890a0|Vipin||registeredIn||DISCO|\n405a6ce030e2fbe65bf3b793ac25295b|Vipin||registeredIn||POE|\n62adf672df59a2758afc19ba7f1f41f4|Vipin||registeredIn||DD|\n211be11bfe8bc916d7b8b44b8c5e8c2d|Vipin||registeredIn||DBS|\na49f1c5b9a106fecf416f8cb758cd743|Vipin||registeredIn||DSA|"
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
