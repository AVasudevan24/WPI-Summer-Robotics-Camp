#include "MeMCore.h"

MeUltrasonicSensor ultra(PORT_3);
MeLineFollower lineFinder(PORT2);

MeDCMotor left(M1);
MeDCMotor right(M2);

void setup() { 
    
}



void loop() {

  
    // Drive straight following the line
    while(lineFinder.readSensor1()==0||lineFinder.readSensor2()==0){
        if(lineFinder.readSensor1()==1){
            left.run(-110);
            right.run(50);
        }
        else if(lineFinder.readSensor2()==1){
            left.run(-50);
            right.run(110);
        }
        else{
            left.run(-70);
            right.run(70);
        }
    }

    // Stop the robot at the end of the line
    left.stop();
    right.stop();

    delay(1000);

    

   
    while (lineFinder.readSensor1()==1){
        // Rotates to the right
        left.run(-80);
        right.run(-80);
    }

    // Stop the robot
    left.stop();
    right.stop();

    delay(1000);

    

    // Drive straight following the line
    while(lineFinder.readSensor1()==0||lineFinder.readSensor2()==0){
        if(lineFinder.readSensor1()==1){
            left.run(-110);
            right.run(50);
        }
        else if(lineFinder.readSensor2()==1){
            left.run(-50);
            right.run(110);
        }
        else{
            left.run(-70);
            right.run(70);
        }
    }

    // Stop the robot at the end of the line
    left.stop();
    right.stop();

    delay(1000);

   
    while (lineFinder.readSensor1()==1){
        // Rotates to the right
        left.run(-80);
        right.run(-80);
    }

    // Stop the robot
    left.stop();
    right.stop();

    delay(1000);

 

    if (ultra.distanceCm() > 20.0) {
        // If the space is EMPTY, the mBot parks in the space
        left.run(-100);
        right.run(100);

        delay(500);

        // Park here forever!
        while(true){
            left.stop();
            right.stop();
        }
    }

    else {
        // If the space is NOT EMPTY, the mBot rotates left until it picks up the vertical line
        // on the other side and stops

        // First, rotate to the left to get over the middle line
        left.run(80);
        right.run(80);

        delay(1000);

        while (lineFinder.readSensor2()==1){
            // Rotates to the left
            left.run(80);
            right.run(80);
        }
    }

    // Stop the robot
    left.stop();
    right.stop();

    delay(1000);

  

    if (ultra.distanceCm() > 20.0) {
        // If the space is EMPTY, the mBot parks in the space
        left.run(-100);
        right.run(100);

        delay(500);

        // Park here forever!
        while(true){
            left.stop();
            right.stop();
        }
    }

    else {
        // If the space is NOT EMPTY, the mBot rotate to the right to get over the middle line
        // and stops

        // First, rotate to the right to get realigned with the middle line
        left.run(-80);
        right.run(-80);

        delay(900); // you can try a more appropriate delay time to get the robot better aligned

    }

    // Stop the robot
    left.stop();
    right.stop();

    

    // Park here forever!
    while(true){
        left.stop();
        right.stop();
    }

  
}
