const firebaseConfig = {
  apiKey: "AIzaSyCN4mDVRYfxEmyvDcmj8suDxtvtgq_GrgA",
  authDomain: "smart-factory-control.firebaseapp.com",
  databaseURL: "https://smart-factory-control.firebaseio.com",
  projectId: "smart-factory-control",
  storageBucket: "smart-factory-control.appspot.com",
  messagingSenderId: "984241458402",
  appId: "1:984241458402:web:a8b2f17a60a9267c"
};
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);

$(document).ready(function(){
  var database = firebase.database();
  var ledStatus;
  var MotorStatus;

  database.ref().on("value", function(snap){
    ledStatus = snap.val().ledStatus;
    MotorStatus = snap.val().MotorStatus;
   
  });

  $(".button1").click(function(){
    var firebaseRef = firebase.database().ref().child("ledStatus");

    if(ledStatus == 1){
      firebaseRef.set(0);
      ledStatus = 0;
      logger.textContent="\nLed Turned OFF\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
    } 
    else
    {
      firebaseRef.set(1);
      ledStatus = 1;
      logger.textContent="\nLed Turned ON\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
    }
  });

  $(".button3").click(function(){
    var firebaseRef = firebase.database().ref().child("MotorStatus");

    if(MotorStatus == 1){
      firebaseRef.set(0);
      MotorStatus = 0;
      logger.textContent="\nMotor Turned OFF\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
    }
    else
    {
      firebaseRef.set(1);
      MotorStatus = 1;
      logger.textContent="\nMotor Turned ON\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
    }
  });
});