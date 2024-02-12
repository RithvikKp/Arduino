
#define spk1  5
#define spk2  6

String Incoming_value =" ";//variable created to store the incoming value
bool speak = false;

void setup() {
  Serial.begin(9600);
  pinMode(spk1,OUTPUT);
  pinMode(spk2,OUTPUT);
}
void loop() {
  if(speak == false){ //turning off the speaker
    digitalWrite(spk1, HIGH);
    digitalWrite(spk2, HIGH);
  }

  if(Serial.available()>0){//checking if the input is coming or not if inpu zero the program stops
    Incoming_value = Serial.read();// readString();, for reading a string 
    Serial.print(Incoming_value);
    Serial.print("\n"); 

    if(Incoming_value == "SPEAK1"){
      digitalWrite(spk1, LOW);
      delay(100); // is according to the time duration we are saving the audio here its 1min 
      speak = false;
    }

    else if(Incoming_value == "SPEAK2"){
      digitalWrite(spk2, LOW);
      delay(100); // is according to the time duration we are saving the audio here its 1min 
      speak = false;
    }
  }
}
