var string = window.location.search.substring(1)
var list=string.split('&')
for(var i=0;i<list.length;i++)
{
	var pair=list[i].split('=')
	var key=pair[0]
	var value=pair[1]
	document.getElementById(key+'Box').value=value
}
document.getElementById('queryButton').click()