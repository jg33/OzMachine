
var prompt = require('prompt');
var fs = require('fs');
var WebSocketServer = require('ws').Server;
var socketServer = new WebSocketServer({port:14949});

var currentScene = 0;
var masterTime;

var connectionCounter =0;
var clients = [];
var ofHost;

socketServer.on('connection', function(client) {
	clients[connectionCounter] = client;
	
    client.on('message', function(message) {
        console.log('received: %s', message);
        console.log('from: %s', clients.indexOf(client));
		
		var msgArray = message.split(' ');

		// on the first connection, every client will ask for a unique id from
		// the server and send it back
		// Server will write these ids into a file called 'message.txt'
		if(msgArray[0]=="/myID"){
    		var towrite = 'got client id: '+ msgArray[1]+'\n';
			fs.appendFile('message.txt', towrite, function (err) {
			  if (err) throw err;
			});

			// when the clients receive a message from server, they will send 
			// back a message.
			// server will write these message into the file.
    	}else if(msgArray[0]=="/got"){
	    		var towrite = 'client '+ msgArray[1]+' got message ~~~\n';
				fs.appendFile('message.txt', towrite, function (err) {
				  if (err) throw err;
				});
	    }
		else if(msgArray[0]=="/setScene"){
			setScene(message.split(' ')[1] );
		} else if(msgArray[0] =="/getScene"){
			client.send("/scene "+currentScene);
		} else if(msgArray[0] =="/ping"){
			client.send("/ping a-ok! Scene: "+currentScene+" Time: "+ masterTime );
		} else if (msgArray[0] =="/imHost"){
			ozHost = client;
			ozHost.send("ok- you're hosting");
		} else if (msgArray[0] =="/tap"){
			ozHost.send("/trigger "+ clients.indexOf(client));
		} else if (msgArray[0] =="/home"){
			ozHost.send("/home "+ msgArray[1]);
		} else if(msgArray[0] == "/broadcast"){
			socketServer.broadcast(msgArray[1]);
		} else {
			var splitAddress = msgArray[0].split('/');
			
			if(splitAddress[0] == "clientInfo"){
				if(splitAddress[1] == "firstName"){
					//clients[clients.indexOf(client))].firstName = msgArray[1];
				} else if(splitAddress[1] == "lastName"){
					//clients[clients.indexOf(client))].lastName = msgArray[1];
					
				} else if(splitAddress[1] == "row"){
					//clients[clients.indexOf(client))].row = msgArray[1];
					
				} else if(splitAddress[1] == "number"){
					//clients[clients.indexOf(client))].number = msgArray[1];
					
				} else if(splitAddress[1] == "deviceID"){

				}
				
			}
						
		}
		
    });

	client.send('/yourID '+connectionCounter);
	connectionCounter++;
    client.send('/welcome '+ currentScene);
    client.send('/time '+masterTime);
});

var date = new Date();
var startTime = date.getTime();
masterTime = startTime;
var towrite = 'Here the server begins!\n';
fs.writeFile('message.txt', towrite, function (err) {
	if (err) throw err;
});
var update = function(){
	date = new Date();
	masterTime = date.getTime() - startTime;
	socketServer.broadcast("/update "+ masterTime +" "+currentScene);
	//console.log('sent: '+ date.getTime())
	
}
function writeTextFile(filepath, output) {
	var txtFile = new File(filepath);
	txtFile.open("w"); //
	txtFile.writeln(output);
	txtFile.close();
}
var setScene = function(newScene){
	if(newScene=='send'){
		console.log("Server sent message");
		socketServer.broadcast("/sendMyMsg Meng");

	}else if(currentScene != newScene){
		currentScene = newScene;
		socketServer.broadcast("/sceneChange "+ currentScene);
		console.log("Scene changed to: "+currentScene);
		
	}else{
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

function saveClientInfo(){


}

function loadClientInfo(){
	
}


socketServer.broadcast = function broadcast(data) {

  for(var i in this.clients) {
    this.clients[i].send(data);
  }
};

