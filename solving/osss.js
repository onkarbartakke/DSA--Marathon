const os = require('os');

var totalMemory = os.totalmem();
var freeMemory = os.freemem();

console.log("Total Mem : ", totalMemory);

console.log("Free Mem : ", freeMemory);