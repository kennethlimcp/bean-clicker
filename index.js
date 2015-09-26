var com = require('serialport');
var robot = require("robotjs");
var date = Date();

var serialport = new com.SerialPort("/dev/tty.LightBlue-Bean", {
    baudrate: 9600
	//	parser: com.parsers.readline('\r\n')
	  });
serialport.on('open', function(){
  console.log('Serial Port Opened');
});

serialport.on('data', function(data){
		var command = data.toString();
		if(command == "l"){
			serialport.write("l");
			robot.keyTap("left");
			console.log(date.toString() + "    left");
		}
		else if(command == "r"){
			robot.keyTap("right");
			serialport.write("l");
			console.log(date.toString() + "    right");
		}
});

serialport.on('close', function(data){
		console.log("close");
});
