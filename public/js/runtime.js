
var firebaseConfig = {
  apiKey: "********************",
  authDomain: "smart-trahs.firebaseapp.com",
  databaseURL: "https://smart-trahs.firebaseio.com",
  projectId: "smart-trahs",
  storageBucket: "smart-trahs.appspot.com",
  messagingSenderId: "**********",
  appId: "*******"
};
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
var dbRef = firebase.database().ref('nivelestrash');

var niveles;

var trashTemplate = $("#trash-conteiner").html();
var compiledCharacterTemplate = Handlebars.compile(trashTemplate);

dbRef.on('value',(snapshot) => {
  niveles = snapshot.val();
  var trash =$("#trash-content");  
  // trash.html(compiledCharacterTemplate(niveles));
  console.log(niveles);
  //Metal nivel
  $("#nivelMetal").attr('porcentaje' ,niveles['metal']+'%');
  if ( niveles['metal'] <= 0 ) {
    $("#nivelMetal").animate({height: '1px'});
  }else if ( niveles['metal'] >= 100) {
    $("#nivelMetal").animate({height: '100%'});
  } else {
    $("#nivelMetal").animate({height: niveles['metal']+'%'});
  }

  //Plastico nivel
  $("#nivelPlastico").attr('porcentaje' ,niveles['plastico']+'%');
  if ( niveles['plastico'] <= 0 ) {
    $("#nivelPlastico").animate({height: '1px'});
  }else if ( niveles['plastico'] >= 100) {
    $("#nivelPlastico").animate({height: '100%'});
  } else {
    $("#nivelPlastico").animate({height: niveles['plastico']+'%'});
  }
  

  //Vidrio nivel
  $("#nivelVidrio").attr('porcentaje' ,niveles['vidrio']+'%');
  if ( niveles['vidrio'] <= 0 ) {
    $("#nivelVidrio").animate({height: '1px'});
  }else if ( niveles['vidrio'] >= 100) {
    $("#nivelVidrio").animate({height: '100%'});
  } else {
    $("#nivelVidrio").animate({height: niveles['vidrio']+'%'});
  }

  //Indefinido nivel
  $("#nivelIndefinido").attr('porcentaje' ,niveles['indefinido']+'%');
  if ( niveles['indefinido'] <= 0 ) {
    $("#nivelIndefinido").animate({height: '1px'});
  }else if ( niveles['indefinido'] >= 100) {
    $("#nivelIndefinido").animate({height: '100%'});
  } else {
    $("#nivelIndefinido").animate({height: niveles['indefinido']+'%'});
  }
});
