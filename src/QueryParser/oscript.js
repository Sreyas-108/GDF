alert("Oscript running");
var str = window.location.search.substring(1);
if(!str)
{
    document.getElementById('list').style.display='none';
    document.getElementById('graph').style.display='none';
}

else if(document.getElementById('triples').checked)
{
    document.getElementById('list').style.display='block';
    document.getElementById('graph').style.display='none';
}
else(document.getElementById('svg').checked)
{
    document.getElementById('list').style.display='none';
    document.getElementById('graph').style.display='block';
}