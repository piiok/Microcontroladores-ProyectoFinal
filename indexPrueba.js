const http = require('http');

const colors = require('colors');

const handleServer = function (req, res){
    res.writeHead(200,{'Content-type': "text/html"});
    res.write("<h1>Hola Mundo desde un servidor http de node js :O</h1>");
    console.log("Conected to index.js".gray);
    res.end();    
}

const server = http.createServer(handleServer);

server.listen(8080, function () {
    console.log("Server on port 8080".green);
})