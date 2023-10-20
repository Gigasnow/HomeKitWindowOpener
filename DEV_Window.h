
////////////////////////////////////
//   DEVICE-SPECIFIC LED SERVICES //
////////////////////////////////////

// DEFINE WINDOW OPENER SERVICE

struct DEV_Window : Service::Window {               // create a derived class

  int openPin;                                       // variables which store the pin number defined for this LED
  int closePin;  
  SpanCharacteristic *current;
  SpanCharacteristic *target;

  // define the constructor for DEV_Window
  
  DEV_Window(int openPin, int closePin) : Service::Window(){
    current=new Characteristic::CurrentPosition(0,true);    // Windows Shades have positions that range from 0 (fully lowered) to 100 (fully raised)    
    target=new Characteristic::TargetPosition(0,true);      // Windows Shades have positions that range from 0 (fully lowered) to 100 (fully raised)
    this->openPin=openPin;                            // don't forget to store ledPin...
    this->closePin=closePin;                            // don't forget to store ledPin...
    pinMode(openPin,OUTPUT);                         // ...and set the mode for ledPin to be an OUTPUT (standard Arduino function)
    pinMode(closePin,OUTPUT);
    

  } // end constructor

  //override the default update() method

  boolean update(){            

if(target->getNewVal() > 0.5){
    digitalWrite(openPin, HIGH);
    delay(200);
    digitalWrite(openPin, LOW);
    current->setVal(true);
    }
    else{
    digitalWrite(closePin, HIGH);
    delay(200);
    digitalWrite(closePin, LOW);
    current->setVal(false);     
    }
    return(true);   
  
  } // update

};
      
//////////////////////////////////

