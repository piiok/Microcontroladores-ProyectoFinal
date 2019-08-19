var express = require('express');
var exphbs  = require('express-handlebars');
const colors = require('colors');
var app = express();

app.use(express.static('public')); //Declara la ruta como publica ~/public
app.engine('.hbs', exphbs({extname: '.hbs'}));
app.set('view engine', '.hbs');


// BASE DE DATOS
// var admin = require("firebase-admin");
// var serviceAccount = require("./smart-trahs-firebase-adminsdk-otmhv-346b8a927d.json");
// admin.initializeApp({
//   credential: admin.credential.cert(serviceAccount),
//   databaseURL: "https://smart-trahs.firebaseio.com/"
// });

// var db = admin.database();


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
    res.redirect('/home');
    console.log("Redireccionando...  - Ruta raiz".gray);
});


app.get("/home", function (req, res) {
    res.render('home',{title:'Home' });
    console.log("Una coneccion establecida - HOME. ".gray);
});


app.get("/example", async  (req, res) => {
    console.log("Una coneccion establecida - EXAMPLE. ".gray);
    // db.ref("trash-1").once('value', async (snapshot) => {
        
    //     console.log('act');
    // });
    res.render('example',{title: 'Example',asincrono:true});
});


app.listen(8080, function () { console.log("Servidor en el puerto 8080".green); })
