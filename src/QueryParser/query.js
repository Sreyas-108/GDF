/***********************************************************************/
/*Function to execute:"query(<type>, <subject>, <predicate>, <object>)"*/
/***********************************************************************/
var exec = require('child_process').exec, child;
function query(type, sub, pred, obj){
    if(type==='search')
        str = '../QueryParser/search "<'+sub+','+pred+','+obj+'>"';
    if(type==='create')
        str = 'cd ../QueryParser | ./create "<'+sub+','+pred+','+obj+'>"';
    if(type==='delete')
        str = 'cd ../QueryParser | ./delete "<'+sub+','+pred+','+obj+'>"';
    exec(str,
    function(error, stdout, stderr){
        console.log('stdout:'+stdout);
        console.log('stderr:'+stderr);
        if(error!=null){
            console.log('exec error: '+error);
        }
    });
}

module.exports.query=query;