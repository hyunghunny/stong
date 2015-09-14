var express = require('express');
var router = express.Router();
var stong = require('../stong.js');
var config = require('../config.js');

/* GET home page. */
router.get('/', function (req, res) {
    res.render('index', {
        'title': 'Stong - 음쓰, 냄새 걱정없는 음쓰통 해킹',
        'sensor': config.sensor.type,
        'status': stong.getStatus()
    });
});

/*
router.get('/temperature', function (req, res) {
    res.writeHead(200, { "Content-Type": "application/json" });
    res.end(JSON.stringify(stong.getTemp()));
});

router.get('/humidity', function (req, res) {
    res.writeHead(200, { "Content-Type": "application/json" });
    res.end(JSON.stringify(stong.getHum()));
});
*/
router.get('/status', function (req, res) {
    res.writeHead(200, { "Content-Type": "application/json" });
    res.end(JSON.stringify(stong.getStatus()));
});


module.exports = router;