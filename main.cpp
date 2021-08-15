#include "MeMCore.h"

MeUltrasonicSensor ultra(PORT_3);
MeLineFollower lineFinder(PORT2);

MeDCMotor left(M1);
MeDCMotor right(M2);

void setup() { 
    // Nothing to setup here!
}

/* NOTE:
  lineFinder sensor returns [0] when over BLACK surface
  lineFinder sensor returns [1] when over WHITE surface
*/

void loop() {

    //////////////////////////////////////////////////////////////////////////////////
    // STEP 1: Follow straight line until the end and stop
    //////////////////////////////////////////////////////////////////////////////////

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

    //////////////////////////////////////////////////////////////////////////////////



    //////////////////////////////////////////////////////////////////////////////////
    // STEP 2: Turn in place until the robot senses the vertical line
    //////////////////////////////////////////////////////////////////////////////////

    // NOTE: The (lineFinder.readSensor1()==1) is used to check that the robot rotates sufficiently
    // to align with the black tape.
    while (lineFinder.readSensor1()==1){
        // Rotates to the right
        left.run(-80);
        right.run(-80);
    }

    // Stop the robot
    left.stop();
    right.stop();

    delay(1000);

    //////////////////////////////////////////////////////////////////////////////////



    //////////////////////////////////////////////////////////////////////////////////
    // STEP 3: Follow the vertical line until it reaches the gap
    //////////////////////////////////////////////////////////////////////////////////

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

    //////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////
    // STEP 4: Rotate to the right parking spot until it picks up the horizontal 
    // parking line
    //////////////////////////////////////////////////////////////////////////////////

    // NOTE: The (lineFinder.readSensor1()==1) is used to check that the robot rotates sufficiently
    // to align with the black tape.
    while (lineFinder.readSensor1()==1){
        // Rotates to the right
        left.run(-80);
        right.run(-80);
    }

    // Stop the robot
    left.stop();
    right.stop();

    delay(1000);

    //////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////
    // STEP 5: Check the RIGHT car park for space, park if its empty, else rotate to
    // left car park
    //////////////////////////////////////////////////////////////////////////////////

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

    //////////////////////////////////////////////////////////////////////////////////



    //////////////////////////////////////////////////////////////////////////////////
    // STEP 6: Check the LEFT car park for space, park if its empty, else rotate to
    // the middle and stop
    //////////////////////////////////////////////////////////////////////////////////

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

    //////////////////////////////////////////////////////////////////////////////////

    // Park here forever!
    while(true){
        left.stop();
        right.stop();
    }

    //////////////////////////////////////////////////////////////////////////////////
    // YOUR TURN!
    //
    // You can add to this code to check the two parking spaces ahead in case the first two
    // are occupied.
    //////////////////////////////////////////////////////////////////////////////////

}