var prompt = require('prompt');
var WebSocketServer = require('ws').Server;
var socketServer = new WebSocketServer({port:14949});

var currentScene = 0;
var masterTime;

var connectionCounter =0;
var clients = [];


var ofHost;

socketServer.on('connection', function(client) {
	clients[connectionCounter] = client;
	connectionCounter++;
    client.on('message', function(message) {
        console.log('received: %s', message);
        console.log('from: %s', clients.indexOf(client));
		if(message.split(' ')[0]=="/setScene"){
			setScene(message.split(' ')[1] );
		} else if(message.split(' ')[0] =="/getScene"){
			client.send("/scene "+currentScene);
		} else if(message.split(' ')[0] =="/ping"){
			client.send("/ping a-ok! Scene: "+currentScene+" Time: "+ masterTime );
		} else if (message.split(' ')[0] =="/imHost"){
			ozHost = client;
			ozHost.send("ok- you're hosting");
		} else if (message.split(' ')[0] =="/tap"){
			ozHost.send("/trigger "+ clients.indexOf(client));
		} else if (message.split(' ')[0] =="/home"){
			ozHost.send("/home "+ message.split(' ')[1]);
		}
		
    });
    client.send('/welcome '+ currentScene);
    client.send('/time '+masterTime);
});

var date = new Date();
var startTime = date.getTime();
masterTime = startTime;

var update = function(){
	date = new Date();
	masterTime = date.getTime() - startTime;
	socketServer.broadcast("/time "+ masterTime );
	//console.log('sent: '+ date.getTime())
}

var setScene = function(newScene){
	if(currentScene != newScene){
		currentScene = newScene;
		socketServer.broadcast("/sceneChange "+ currentScene);
		console.log("Scene changed to: "+currentScene);
		
	} else{
		console.log("Already in scene "+ newScene);
	}
	
	prompt.start();
	prompt.get('scene',function(err,result){
		setScene(result.scene);
	})
}

setInterval(update,6000);

prompt.start();
prompt.get('scene',function(err,result){
	setScene(result.scene);
})


socketServer.broadcast = function broadcast(data) {
  for(var i in this.clients) {
    this.clients[i].send(data);
  }
};