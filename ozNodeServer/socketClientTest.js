
var WebSocket = require('ws');

var socket = new WebSocket('ws://localhost:3000');


socket.on('open',function(){
	socket.send('hello');
})

var ping = function(){
	console.log("running");
	socket.send('ping');
}

setInterval(ping,6000);