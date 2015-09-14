var config ={
    'serial' : {
        'port': 'COM3',
        'baud': 9600
    },
    'sensor' : {
        'supported' : ['lux_meter', 'thermo-hygrometer', 'distance', 'stong'],
        'type': 'stong',
        'id' : [23, 24, 25],
    },
    'db' : {
        'type' : 'sqlite',
        'tableName': 'stong'
    },
    'export' : {
        'href' : './sensorchart.js',
        'mode' : 'on',
        'id' : 'webofthink',
        'password' : '' 
    }
};

module.exports = config;