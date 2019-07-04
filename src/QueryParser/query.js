/********************************************************************************/
/* Function to be executed as : query(<type>, <subject>, <predicate>, <object>) */
/********************************************************************************/
var exec = require('child_process').exec, child;
function query(type, sub, pred, obj){
    if(type==='Search')
        str = './search "<'+sub+','+pred+','+obj+'>" > temp';
    if(type==='Create')
        str = './create "<'+sub+','+pred+','+obj+'>" > temp';
    if(type==='Delete')
        str = './delete "<'+sub+','+pred+','+obj+'>" > temp';
    exec(str,
    function(error, stdout, stderr){
        console.log('stdout:'+stdout);
        console.log('stderr:'+stderr);
        if(error!=null){
            console.log('exec error: '+error);
        }
    });
    exec('bash create_q_out_list.sh',
    function(error, stdout, stderr){
        console.log('stdout:'+stdout);
        console.log('stderr:'+stderr);
        if(error!=null){
            console.log('exec error: '+error);
        }
    });
}

module.exports.query=query;
