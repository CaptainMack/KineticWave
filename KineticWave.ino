#include <SPI.h>
#include <AutoDriver.h>


// Create our AutoDriver instances. The parameters are pin numbers in
//BoardX(CS pin, reset pin, busy pin)
AutoDriver board1(53, 22, 23);
AutoDriver board2(31, 22, 23);
AutoDriver board3(32, 22, 23);
AutoDriver board4(33, 22, 23);
AutoDriver board5(34, 22, 23);
AutoDriver board6(35, 22, 23);
AutoDriver board7(36, 22, 23);
AutoDriver board8(37, 22, 23);
AutoDriver board9(38, 22, 23);
AutoDriver board10(39, 22, 23);
AutoDriver board11(40, 22, 23);
AutoDriver board12(41, 22, 23);

//Variables
int a = 0;
int amplitude = 3000;
int startPosition = 6000;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing Board #1");
  board1.resetDev();
  board1.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board1.configStepMode(STEP_FS);   // 0 microsteps per step
  board1.setMaxSpeed(300);        // 10000 steps/s max
  board1.setFullSpeed(300);       // microstep below 10000 steps/s
  board1.setAcc(30);             // accelerate at 10000 steps/s/s
  board1.setDec(30);
  board1.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board1.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board1.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board1.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board1.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board1.setSwitchMode(SW_USER);    // Switch is not hard stop
  board1.setOscMode(INT_16MHZ_OSCOUT_16MHZ); // for board1, we want 16MHz.
  Serial.println("Initializing Board #2");
  board2.resetDev();
  board2.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board2.configStepMode(STEP_FS);   // 0 microsteps per step
  board2.setMaxSpeed(300);        // 10000 steps/s max
  board2.setFullSpeed(300);       // microstep below 10000 steps/s
  board2.setAcc(30);             // accelerate at 10000 steps/s/s
  board2.setDec(30);
  board2.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board2.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board2.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board2.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board2.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board2.setSwitchMode(SW_USER);    // Switch is not hard stop
  board2.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board2, we want 16MHz (inverted).
  Serial.println("Initializing Board #3");
  board3.resetDev();
  board3.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board3.configStepMode(STEP_FS);   // 0 microsteps per step
  board3.setMaxSpeed(300);        // 10000 steps/s max
  board3.setFullSpeed(300);       // microstep below 10000 steps/s
  board3.setAcc(30);             // accelerate at 10000 steps/s/s
  board3.setDec(30);
  board3.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board3.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board3.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board3.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board3.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board3.setSwitchMode(SW_USER);    // Switch is not hard stop
  board3.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board3, we want 16MHz (inverted).
  Serial.println("Initializing Board #4");
  board4.resetDev();
  board4.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board4.configStepMode(STEP_FS);   // 0 microsteps per step
  board4.setMaxSpeed(300);        // 10000 steps/s max
  board4.setFullSpeed(300);       // microstep below 10000 steps/s
  board4.setAcc(30);             // accelerate at 10000 steps/s/s
  board4.setDec(30);
  board4.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board4.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board4.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board4.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board4.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board4.setSwitchMode(SW_USER);    // Switch is not hard stop
  board4.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board4, we want 16MHz (inverted).
  Serial.println("Initializing Board #5");
  board5.resetDev();
  board5.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board5.configStepMode(STEP_FS);   // 0 microsteps per step
  board5.setMaxSpeed(300);        // 10000 steps/s max
  board5.setFullSpeed(300);       // microstep below 10000 steps/s
  board5.setAcc(30);             // accelerate at 10000 steps/s/s
  board5.setDec(30);
  board5.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board5.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board5.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board5.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board5.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board5.setSwitchMode(SW_USER);    // Switch is not hard stop
  board5.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board5, we want 16MHz (inverted).
  Serial.println("Initializing Board #6");
  board6.resetDev();
  board6.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board6.configStepMode(STEP_FS);   // 0 microsteps per step
  board6.setMaxSpeed(300);        // 10000 steps/s max
  board6.setFullSpeed(300);       // microstep below 10000 steps/s
  board6.setAcc(30);             // accelerate at 10000 steps/s/s
  board6.setDec(30);
  board6.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board6.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board6.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board6.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board6.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board6.setSwitchMode(SW_USER);    // Switch is not hard stop
  board6.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board6, we want 16MHz (inverted).
    Serial.println("Initializing Board #7");
  board7.resetDev();
  board7.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board7.configStepMode(STEP_FS);   // 0 microsteps per step
  board7.setMaxSpeed(300);        // 10000 steps/s max
  board7.setFullSpeed(300);       // microstep below 10000 steps/s
  board7.setAcc(30);             // accelerate at 10000 steps/s/s
  board7.setDec(30);
  board7.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board7.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board7.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board7.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board7.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board7.setSwitchMode(SW_USER);    // Switch is not hard stop
  board7.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).
      Serial.println("Initializing Board #8");
  board8.resetDev();
  board8.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board8.configStepMode(STEP_FS);   // 0 microsteps per step
  board8.setMaxSpeed(300);        // 10000 steps/s max
  board8.setFullSpeed(300);       // microstep below 10000 steps/s
  board8.setAcc(30);             // accelerate at 10000 steps/s/s
  board8.setDec(30);
  board8.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board8.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board8.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board8.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board8.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board8.setSwitchMode(SW_USER);    // Switch is not hard stop
  board8.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).
      Serial.println("Initializing Board #9");
  board9.resetDev();
  board9.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board9.configStepMode(STEP_FS);   // 0 microsteps per step
  board9.setMaxSpeed(300);        // 10000 steps/s max
  board9.setFullSpeed(300);       // microstep below 10000 steps/s
  board9.setAcc(30);             // accelerate at 10000 steps/s/s
  board9.setDec(30);
  board9.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board9.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board9.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board9.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board9.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board9.setSwitchMode(SW_USER);    // Switch is not hard stop
  board9.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).
        Serial.println("Initializing Board #10");
  board10.resetDev();
  board10.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board10.configStepMode(STEP_FS);   // 0 microsteps per step
  board10.setMaxSpeed(300);        // 10000 steps/s max
  board10.setFullSpeed(300);       // microstep below 10000 steps/s
  board10.setAcc(30);             // accelerate at 10000 steps/s/s
  board10.setDec(30);
  board10.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board10.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board10.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board10.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board10.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board10.setSwitchMode(SW_USER);    // Switch is not hard stop
  board10.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).
        Serial.println("Initializing Board #11");
  board11.resetDev();
  board11.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board11.configStepMode(STEP_FS);   // 0 microsteps per step
  board11.setMaxSpeed(300);        // 10000 steps/s max
  board11.setFullSpeed(300);       // microstep below 10000 steps/s
  board11.setAcc(30);             // accelerate at 10000 steps/s/s
  board11.setDec(30);
  board11.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board11.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board11.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board11.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board11.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board11.setSwitchMode(SW_USER);    // Switch is not hard stop
  board11.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).
        Serial.println("Initializing Board #12");
  board12.resetDev();
  board12.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board12.configStepMode(STEP_FS);   // 0 microsteps per step
  board12.setMaxSpeed(300);        // 10000 steps/s max
  board12.setFullSpeed(300);       // microstep below 10000 steps/s
  board12.setAcc(30);             // accelerate at 10000 steps/s/s
  board12.setDec(30);
  board12.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board12.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board12.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board12.setOCShutdown(OC_SD_ENABLE); //  shutdown on OC
  board12.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board12.setSwitchMode(SW_USER);    // Switch is not hard stop
  board12.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).*/
      Serial.println("All Boards Initialized!");
}


void loop()
{
  
    if (board1.getPos() == 0)  { 
        board1.move(FWD, amplitude);
         if (a < 1) {
           delay(1000);
           a = 1;
         }
    } else if (board1.getPos() == amplitude)  {
        board1.goHome();
         if (a < 2) {
           delay(1000);
           a = 2;
         }
    }
    if (board2.getPos() == 0)  {
        board2.move(FWD, amplitude);
         if (a < 3) {
           delay(1000);
           a = 3;
         }
    }  else if (board2.getPos() == amplitude)  {
        board2.goHome();
    }
        if (board3.getPos() == 0)  {
        board3.move(FWD, amplitude);
         if (a < 4) {
           delay(1000);
           a = 4;
         }
    }  else if (board3.getPos() == amplitude)  {
        board3.goHome();
    }
        if (board4.getPos() == 0)  {
        board4.move(FWD, amplitude);
         if (a < 5) {
           delay(1000);
           a = 5;
         }
    }  else if (board4.getPos() == amplitude)  {
        board4.goHome();
    }
        if (board5.getPos() == 0)  {
        board5.move(FWD, amplitude);
         if (a < 6) {
           delay(1000);
           a = 6;
         }
    }  else if (board5.getPos() == amplitude)  {
        board5.goHome();
    }
        if (board6.getPos() == 0)  {
        board6.move(FWD, amplitude);
         if (a < 7) {
           delay(1000);
           a = 7;
         }
   }   else if (board6.getPos() == amplitude)  {
        board6.goHome();
    }
        if (board7.getPos() == 0)  {
        board7.move(FWD, amplitude);
         if (a < 8) {
           delay(1000);
           a = 8;
         }
     } else if (board7.getPos() == amplitude)  {
        board7.goHome();
    }
            if (board8.getPos() == 0)  {
        board8.move(FWD, amplitude);
         if (a < 9) {
           delay(1000);
           a = 9;
         }
     } else if (board8.getPos() == amplitude)  {
        board8.goHome();
    }
            if (board9.getPos() == 0)  {
        board9.move(FWD, amplitude);
         if (a < 10) {
           delay(1000);
           a = 10;
         }
     } else if (board9.getPos() == amplitude)  {
        board9.goHome();
    }
            if (board10.getPos() == 0)  {
        board10.move(FWD, amplitude);
         if (a < 11) {
           delay(1000);
           a = 11;
         }
     } else if (board10.getPos() == amplitude)  {
        board10.goHome();
    }
            if (board11.getPos() == 0)  {
        board11.move(FWD, amplitude);
         if (a < 12) {
           delay(1000);
           a = 12;
         }
     } else if (board11.getPos() == amplitude)  {
        board11.goHome();
    }
            if (board12.getPos() == 0)  {
        board12.move(FWD, amplitude);
         if (a < 13) {
           delay(1000);
           a = 13;
         }
     } else if (board12.getPos() == amplitude)  {
        board12.goHome();
    }
}

//Functions

void goToStartPosition()  {
  board1.move(FWD, startPosition);
  board2.move(FWD, startPosition);
  board3.move(FWD, startPosition);
  board4.move(FWD, startPosition);
  board5.move(FWD, startPosition);
  board6.move(FWD, startPosition);
  board7.move(FWD, startPosition);
  board8.move(FWD, startPosition);
  board9.move(FWD, startPosition);
  board10.move(FWD, startPosition);
  board11.move(FWD, startPosition);
  board12.move(FWD, startPosition);
}

void goToShutdownPosition()  {
  board1.goHome();
  board2.goHome();
  board3.goHome();
  board4.goHome();
  board5.goHome();
  board6.goHome();
  board7.goHome();
  board8.goHome();
  board9.goHome();
  board10.goHome();
  board11.goHome();
  board12.goHome();
}

void setAcceleration(int accValue)  {
  board1.setAcc(accValue);
  board2.setAcc(accValue);
  board3.setAcc(accValue);
  board4.setAcc(accValue);
  board5.setAcc(accValue);
  board6.setAcc(accValue);
  board7.setAcc(accValue);
  board8.setAcc(accValue);
  board9.setAcc(accValue);
  board10.setAcc(accValue);
  board11.setAcc(accValue);
  board12.setAcc(accValue);
}

void setDecceleration(int decValue)  {
  board1.setDec(decValue);
  board2.setDec(decValue);
  board3.setDec(decValue);
  board4.setDec(decValue);
  board5.setDec(decValue);
  board6.setDec(decValue);
  board7.setDec(decValue);
  board8.setDec(decValue);
  board9.setDec(decValue);
  board10.setDec(decValue);
  board11.setDec(decValue);
  board12.setDec(decValue);
}

void sendPositionJSON()  {
      Serial.print("{");
      Serial.print("'board1':");
      Serial.print(board1.getPos());
      Serial.print(",");
      Serial.print("'board2':");
      Serial.print(board2.getPos());
      Serial.print(",");
      Serial.print("'board3':");
      Serial.print(board3.getPos());
      Serial.print(",");
      Serial.print("'board4':");
      Serial.print(board4.getPos());
      Serial.print(",");
      Serial.print("'board5':");
      Serial.print(board5.getPos());
      Serial.print(",");
      Serial.print("'board6':");
      Serial.print(board6.getPos());
      Serial.print(",");
      Serial.print("'board7':");
      Serial.print(board7.getPos());
      Serial.print(",");
      Serial.print("'board8':");
      Serial.print(board8.getPos());
      Serial.print(",");
      Serial.print("'board9':");
      Serial.print(board9.getPos());
      Serial.print(",");
      Serial.print("'board10':");
      Serial.print(board10.getPos());
      Serial.print(",");
      Serial.print("'board11':");
      Serial.print(board11.getPos());
      Serial.print(",");
      Serial.print("'board12':");
      Serial.print(board12.getPos());
      Serial.print("}");
}



