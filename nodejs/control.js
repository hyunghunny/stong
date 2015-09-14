var dbmgr = require('./data/dbmanager.js'),
    arduino = require('./arduino-serial.js');
    config = require('./config.js');

var sensorchart = require('./sensorchart.js');
var transmitter = null;

var port = config.serial.port;
var baud = config.serial.baud;
var sensorType = config.sensor.type;

var dbType = config.db.type;
var tableName = config.db.tableName;

var dbManager = dbmgr.construct(dbType, tableName, sensorType);

if (config.export.mode == 'on') {
    sensorchart.login(config.export.id, config.export.password, function (obj) {
        transmitter = obj;
    });
}


exports.record = function () {
    var asr = arduino.construct(port, baud);
    var observations = [];
    asr.listen(function (timestamp, data) {

        if (sensorType == 'thermo-hygrometer') {
            var dataArr = data.split(':');
            
            if (dataArr.length == 2) {
                var temperature = parseFloat(dataArr[0]);
                var humidity = parseFloat(dataArr[1]);
                
                // handle NaN as invalid serial input
                if (isNaN(temperature) || isNaN(humidity)) {
                    console.log('invalid serial input: ' + data);
                } else {
                    var observation = {
                        'temperature': temperature,
                        'humidity' : humidity
                    }
                    dbManager.save(timestamp, observation);
                    
                    observations.push({
                        "datePublished" : timestamp,
                        "value" : temperature // save temperature only.
                    });
                }
            }
        } else if (sensorType == 'stong') {
            //console.log(data);
            var dataArr = data.split(':');
            
            if (dataArr.length == 3) {
                var temperature = parseInt(dataArr[0]);
                var humidity = parseInt(dataArr[1]);
                var gas = parseInt(dataArr[2])
                // handle NaN as invalid serial input
                if (isNaN(temperature) || isNaN(humidity)) {
                    console.log('invalid serial input: ' + data);
                } else {
                    var observation = {
                        'temperature': temperature,
                        'humidity' : humidity,
                        'gas' : gas
                    }
                    //dbManager.save(timestamp, observation);
                    
                    observations.push({
                        "datePublished" : timestamp,
                        "temperature" : temperature,
                        "humidity" : humidity,
                        "gas" : gas
                    });
                }
            } else {
                console.log('invalid serial input: ' + data);
            }
        } else {
            var value = new String(data).trim();
            dbManager.save(timestamp, value);
            observations.push({
                "datePublished" : timestamp,
                "value" : value
            });
        }
        console.log(observations.length);
        if (transmitter && observations.length == 10) {
            
            var tempTotal = 0;
            var humTotal = 0;
            var gasTotal = 0;
            for (var i = 0; i < observations.length; i++) {
                tempTotal = tempTotal + observations[i].temperature;
                humTotal = humTotal + observations[i].humidity;
                gasTotal = gasTotal + observations[i].gas; 
            }
            var tempAvg = parseInt(tempTotal / 10.0);
            var humAvg = parseInt(humTotal / 10.0);
            var gasAvg = parseInt(gasTotal / 10.0);
            
            var tempObs = [{
                "datePublished" : timestamp,
                "value" : tempAvg
            }];
            var humidityObs = [{
                    "datePublished" : timestamp,
                    "value" : humAvg
                }];
            var gasObs = [{
                    "datePublished" : timestamp,
                    "value" : gasAvg
                }];
            transmitter.emit(config.sensor.id[0], tempObs, function (result) {
                if (result == false) {
                    console.log('failed to transmit temperature observations.');
                } 
            });
            // humidity
            transmitter.emit(config.sensor.id[1], humidityObs, function (result) {
                if (result == false) {
                    console.log('failed to transmit humidity observations.');
                } 
            });
            // gas
            transmitter.emit(config.sensor.id[2], gasObs, function (result) {
                if (result == false) {
                    console.log('failed to transmit humidity observations.');
                } 
            });
            observations = [];

        }
        
    });

}
