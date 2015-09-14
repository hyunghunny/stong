var currentTemp = 0;
var currentHum = 0;
var currentGas = 0;

exports.setObs = function (temp, hum, gas) {
    currentTemp = temp;
    currentHum = hum;
    currentGas = gas;
}

exports.getTemperature = function () {
    return { 'temperature' : currentTemp }
}

exports.getHumidity = function () {
    return { 'humidity' : currentHum }
}

exports.getStatus = function () {
    return {
        'temperature' : currentTemp,
        'humidity' : currentHum,
        'gas' : currentGas
    }
}
  