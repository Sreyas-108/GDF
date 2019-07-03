var http=require('http');
var url=require('url');
var events=require('events');
/*var string = window.location.search.substring(1)
var q=url.parse(url.string,true).query;
var sub=q.Subject;
var obj=q.Object;
var pred=q.Predicate;*/
var eventEmitter= new events.EventEmitter();

var myFunc=function () {
	console.log('I am being called!!!');
}

eventEmitter.on('run',myFunc);
eventEmitter.emit('run');

