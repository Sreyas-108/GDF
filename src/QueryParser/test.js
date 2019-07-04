var testStringShort="8bf8c5cdafb0358dd95ec96c2479ebce|Suyash||likesToEat||FriedRice|\na6c8c98b4f7aab7319051b69b1905690|Suyash||likesToEat||Biryani|\ncf75a207ff5e923744dc60cecfb0da04|Suyash||likesToEat||ShahiPaneer|\n3812c1c860901961bc9c948becd02564|Suyash||likesToEat||BhelPuri|\nce79a1aaa1e719367c06ca85a75ac9a7|Suyash||likesToEat||BreadJam|\n45337653b66dcf1ea112abb1357b0843|Suyash||likesToEat||BreadButter|\n597b8df3225cc86431a43de45899085e|Suyash||likesToEat||Pavbhaji|\n60da9e10eba5b307d75911a4abb6ea83|Suyash||registeredIn||PnS|\n6347be60e73317f8bde57591e0805215|Suyash||registeredIn||M1|\n0ccdb8b41ba387b7ab0764306b5240d8|Suyash||registeredIn||MeOW|\n5f9c20fd875402fabe72e3eebf85ed68|Suyash||registeredIn||ES|\nd7397576477c56096d5024b6ae4ac119|Suyash||registeredIn||CP|\n855a42763a1b80ae6ada12d910aecc9f|Suyash||registeredIn||PAVA|\nc836b60cff014e1069825818e004ca64|Suyash||registeredIn||OOP|\n25be3e0181b447303522d8af97479263|Suyash||registeredIn||POM|\n7f4a503a86d4037fc2643fd2db9de80a|Suyash||registeredIn||POE|\na97ac9831cb5ef47f1ab072bc6824b1a|Suyash||registeredIn||MuP|\n2ae5022cf9a7a8712e4567d435e34705|Suyash||registeredIn||DBS|"
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
	dotArray.push('bgcolor="#64F0F0"')
	/*const fs = require('fs') 
	fs.readFile(filename, 'ascii', (err, data) => { 
	    if (err) throw err; 
	    var lines=data.toString().split("\n") 
	    console.log(lines)
	})*/
$string/
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
          var QUERY_URL='?type=Search&Subject=?&Predicate='+label+'&ObjecT=?&shapes=on'
          edge_description.push(getLabel(words[1])+' -> '+getLabel(words[5])+'['+'label="'+getLabel(words[3])+'", color="'+randomColorString(getLabel(words[1]))+'", URL="'+QUERY_URL+'"];')
          n_edges++;
       }
    new Set(nodes).forEach(function(value1,value2,set){
    	var label=getLabel(value1)
    	n_nodes++;
    	var QUERY_URL='?type=Search&Subject='+label+'&Predicate=?&ObjecT=?&shapes=on'
    	dotArray.push(label+' [ '+'label="'+label+'", fillcolor="'+randomColor()+'", URL="'+QUERY_URL+'" ];')
    })
    dotArray=dotArray.concat(edge_description);
	dotArray.push('}')
	console.log(n_nodes) 
	console.log(n_edges)
	var dot = dotArray.join('');
	return dot
}
