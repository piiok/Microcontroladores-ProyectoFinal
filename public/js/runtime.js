
  // Your web app's Firebase configuration
  
$(document).ready(function(){
    var trashTemplate = $("#trash-conteiner").html();
    var compiledCharacterTemplate = Handlebars.compile(trashTemplate);
    // var firebaseConfig = {
    //     apiKey: "AIzaSyBZdqfw25tj6h76eS6qvphzoxgRE30nabA",
    //     authDomain: "smart-trahs.firebaseapp.com",
    //     databaseURL: "https://smart-trahs.firebaseio.com",
    //     projectId: "smart-trahs",
    //     storageBucket: "smart-trahs.appspot.com",
    //     messagingSenderId: "1087005906697",
    //     appId: "1:1087005906697:web:41c8ca0e3e8b9d8a"
    //   };
    //   // Initialize Firebase
    //   firebase.initializeApp(firebaseConfig);
    //   var dbRef = firebase.database().ref('nivelestrash');
      
    const contenido ={
        "metal":0,
        "indefinido":0,
        "plastico":0,
        "vidrio":0
    };
    $("#trash").html(compiledCharacterTemplate(contenido));
    
    // dbRef.on('value',(snapshot) => {
       
    //     // trash = snapshot.val();

        
    //     console.log(trash);
    // });
    
});