
#include <Servo.h>

#define right_unpressed 60
#define right_pressed 0
#define left_unpressed 0
#define left_pressed 60


String command;
Servo servo_right;
Servo servo_left;

void setup() {
    // Starting the serial console
    Serial.begin(9600); 
    
    // Attaching both servos
    servo_right.attach(7);
    servo_left.attach(8);
    
    // Setting them un unpressed position
    servo_right.write(right_unpressed);
    servo_left.write(left_unpressed);
    Serial.println("Ready for commands, press my buttons!");
}
 
void loop() {
    if(Serial.available()){
        command = Serial.readStringUntil('\n');
        
        // Press trezor's right button
        if(command.equals("right press")){
          Serial.println("Pressing right button.");
          servo_right.write(right_pressed);
        }
        // Unpress trezor's right button
        else if(command.equals("right unpress")){
          Serial.println("Unpressing right button.");
          servo_right.write(right_unpressed);
        }
        // Press trezor's left button
        else if(command.equals("left press")){
        Serial.println("Pressing the left button.");
        servo_left.write(left_pressed);
        }
        // Unpress trezor's left button
        else if(command.equals("left unpress")){
          Serial.println("Unpressing the left button.");
          servo_left.write(left_unpressed);
        }
        // click trezor's left button
        else if(command.equals("left click")){
          Serial.println("Clicking the left button.");
          servo_left.write(left_pressed);
          delay(500);
          servo_left.write(left_unpressed);
        }
        // click trezor's right button
        else if(command.equals("right click")){
          Serial.println("Clicking the right button.");
          servo_right.write(right_pressed);
          delay(500);
          servo_right.write(right_unpressed);

        }
    }
}
