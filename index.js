const http = require('http');

const colors = require('./node_modules/colors');

const handleServer = function (req, res){
    res.writeHead(200,{'Content-type': "text/html"});
    res.write("<h1>Hola Mundo desde un servidor http de node js :O</h1>");
    res.end();    
}

const server = http.createServer(handleServer);

server.listen(1406, function () {
    console.log("Server on port 1406".green);
})