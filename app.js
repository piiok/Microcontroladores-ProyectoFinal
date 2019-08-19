var express = require('express');
var exphbs  = require('express-handlebars');
const colors = require('colors');
var app = express();

app.use(express.static('public')); //Declara la ruta como publica ~/public
app.engine('.hbs', exphbs({extname: '.hbs'}));
app.set('view engine', '.hbs');

/*
.########...#######..##.....##.########.########..######.
.##.....##.##.....##.##.....##....##....##.......##....##
.##.....##.##.....##.##.....##....##....##.......##......
.########..##.....##.##.....##....##....######....######.
.##...##...##.....##.##.....##....##....##.............##
.##....##..##.....##.##.....##....##....##.......##....##
.##.....##..#######...#######.....##....########..######.
*/

app.get("/", function (req, res) {
    res.render('home',{
        helpers: {
            title: function () { return 'Home'; }
        }
    });
    console.log("Una coneccion establecida. ".gray);
});



app.listen(8080, function () { console.log("Servidor en el puerto 8080".green); })
