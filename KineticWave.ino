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
int amplitude = 2000;
int changingWave = 0;
int lastSentMillis = 501;
int startPosition = 300; //Start position have to be AT LEAST twice the number of steps of the amplitude.
int serialData = 0;
int startTime = 0;
char incomingByte;
int waveType = 0;
int waveInclination = 0;
int small = 1500;
int medium = 3000;
int large = 4500;
int runOnce = 0;
void setup()
{
  // Initialize Serial Communication
  Serial.begin(9600);
  Serial3.begin(9600);
  //Initialize boards
  
  initializeBoards();
  //Change settings on all boards
  setMaxSpeed(150);
  setAcc(50);
  setDec(50);
  //goToStartPosition();
  //delay(5000);
  //startTime = millis();
}


void loop()  {
  //board1.run(REV,150);
  //board2.run(REV,150);
  //board3.run(REV,150);
  //board4.run(REV,150);
  //board5.run(REV,150);
  //board6.run(REV,150);
  //board7.run(REV,150);
  //board8.run(REV,150);
  //board9.run(REV,150);
  //board10.run(REV,150);
  //board11.run(REV,150); 
  //board12.run(REV,150);
  //sendPositionJSON();
  if (changingWave == 0)  {
    createWave(2500, 2000); 
  }
  /*
  if (changingWave = 0)  {
    createWave(amplitude, waveType); 
  }
  */
  
  if ((millis()-startTime) > 90000 && runOnce == 0) {
    changingWave = 1;
    stopWave();
    runOnce = 1;
  }
 
}

//Functions


void createWave(int ampl, int incl)  {
    if (board1.getPos() == 0 && (millis()-startTime) > (incl*1))  { 
        board1.move(FWD, ampl);
    } else if (board1.getPos() == ampl)  {
          board1.goHome();  
    }
    if (board2.getPos() == 0 && (millis()-startTime) > (incl*2))  {
        board2.move(FWD, ampl);
    }  else if (board2.getPos() == ampl)  {
          board2.goHome();
    }
    if (board3.getPos() == 0 && (millis()-startTime) > (incl*3))  {
        board3.move(FWD, ampl);
    }  else if (board3.getPos() == ampl)  {
          board3.goHome();
    }
    if (board4.getPos() == 0 && (millis()-startTime) > (incl*4))  {
        board4.move(FWD, ampl);
    }  else if (board4.getPos() == ampl)  {
          board4.goHome();
    }
    if (board5.getPos() == 0 && (millis()-startTime) > (incl*5))  {
        board5.move(FWD, ampl);
    }  else if (board5.getPos() == ampl)  {
          board5.goHome();
    }
    if (board6.getPos() == 0 && (millis()-startTime) > (incl*6))  {
        board6.move(FWD, ampl);
   }   else if (board6.getPos() == ampl)  {
          board6.goHome();
    }
    if (board7.getPos() == 0 && (millis()-startTime) > (incl*7))  {
        board7.move(FWD, ampl);
     } else if (board7.getPos() == ampl)  {
        board7.goHome();
    }
    
    if (board8.getPos() == 0 && (millis()-startTime) > (incl*8))  {
        board8.move(FWD, ampl);
     } else if (board8.getPos() == ampl)  {
      board8.goHome();
    }
    if (board9.getPos() == 0 && (millis()-startTime) > (incl*9))  {
        board9.move(FWD, ampl);
     } else if (board9.getPos() == ampl)  {
        board9.goHome();
    }
    if (board10.getPos() == 0 && (millis()-startTime) > (incl*10))  {
        board10.move(FWD, ampl);
     } else if (board10.getPos() == ampl)  {
        board10.goHome();
    }
    if (board11.getPos() == 0 && (millis()-startTime) > (incl*11))  {
        board11.move(FWD, ampl);
     } else if (board11.getPos() == ampl)  {
        board11.goHome();
    }
   
    if (board12.getPos() == 0 && (millis()-startTime) > (incl*12))  {
        board12.move(FWD, ampl);
     } else if (board12.getPos() == ampl)  {
          board12.goHome();
    }  
}

//Invoked before start.
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
  board1.resetPos();
  board2.resetPos();
  board3.resetPos();
  board4.resetPos();
  board5.resetPos();
  board6.resetPos();
  board7.resetPos();
  board8.resetPos();
  board9.resetPos();
  board10.resetPos();
  board11.resetPos();
  board12.resetPos();
}

//Invoked before shutdown
void goToShutdownPosition()  {
  board1.goTo(-500);
  board2.goTo(-500);
  board3.goTo(-500);
  board4.goTo(-500);
  board5.goTo(-500);
  board6.goTo(-500);
  board7.goTo(-500);
  board8.goTo(-500);
  board9.goTo(-500);
  board10.goTo(-500);
  board11.goTo(-500);
  board12.goTo(-500);
}

void goToHome()  {
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
//On-the-fly acceleration change
void setAcc(int accValue)  {
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
//On-the-fly decceleration change
void setDec(int decValue)  {
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
  if ((millis()-lastSentMillis) > 1) {
      Serial3.print("{");
      Serial3.print("'b1':");
      Serial3.print(board1.getPos());
      Serial3.print(",");
      Serial3.print("'b2':");
      Serial3.print(board2.getPos());
      Serial3.print(",");
      Serial3.print("'b3':");
      Serial3.print(board3.getPos());
      Serial3.print(",");
      Serial3.print("'b4':");
      Serial3.print(board4.getPos());
      Serial3.print(",");
      Serial3.print("'b5':");
      Serial3.print(board5.getPos());
      Serial3.print(",");
      Serial3.print("'b6':");
      Serial3.print(board6.getPos());
      Serial3.print(",");
      Serial3.print("'b7':");
      Serial3.print(board7.getPos());
      Serial3.print(",");
      Serial3.print("'b8':");
      Serial3.print(board8.getPos());
      Serial3.print(",");
      Serial3.print("'b9':");
      Serial3.print(board9.getPos());
      Serial3.print(",");
      Serial3.print("'b10':");
      Serial3.print(board10.getPos());
      Serial3.print(",");
      Serial3.print("'b11':");
      Serial3.print(board11.getPos());
      Serial3.print(",");
      Serial3.print("'b12':");
      Serial3.print(board12.getPos());
      Serial3.println("}");
      lastSentMillis = millis();
  }
}

void sendStatusJSON()  {
      Serial3.print("{");
      Serial3.print("'b1':");
      Serial3.print(board1.getStatus());
      Serial3.print(",");
      Serial3.print("'b2':");
      Serial3.print(board2.getStatus());
      Serial3.print(",");
      Serial3.print("'b3':");
      Serial3.print(board3.getStatus());
      Serial3.print(",");
      Serial3.print("'b4':");
      Serial3.print(board4.getStatus());
      Serial3.print(",");
      Serial3.print("'b5':");
      Serial3.print(board5.getStatus());
      Serial3.print(",");
      Serial3.print("'b6':");
      Serial3.print(board6.getStatus());
      Serial3.print(",");
      Serial3.print("'b7':");
      Serial3.print(board7.getStatus());
      Serial3.print(",");
      Serial3.print("'b8':");
      Serial3.print(board8.getStatus());
      Serial3.print(",");
      Serial3.print("'b9':");
      Serial3.print(board9.getStatus());
      Serial3.print(",");
      Serial3.print("'b10':");
      Serial3.print(board10.getStatus());
      Serial3.print(",");
      Serial3.print("'b11':");
      Serial3.print(board11.getStatus());
      Serial3.print(",");
      Serial3.print("'b12':");
      Serial3.print(board12.getStatus());
      Serial3.println("}");
}

void goToSpecificPosition(int pos)  {
 board1.goTo(pos);
 board2.goTo(pos);
 board3.goTo(pos);
 board4.goTo(pos);
 board5.goTo(pos);
 board6.goTo(pos);
 board7.goTo(pos);
 board8.goTo(pos);
 board9.goTo(pos);
 board10.goTo(pos);
 board11.goTo(pos);
 board12.goTo(pos);
}

void setMaxSpeed(int speed)  {
  board1.setMaxSpeed(speed);
  board1.setFullSpeed(speed);
  board2.setMaxSpeed(speed);
  board2.setFullSpeed(speed);
  board3.setMaxSpeed(speed);
  board3.setFullSpeed(speed);
  board4.setMaxSpeed(speed);
  board4.setFullSpeed(speed);
  board5.setMaxSpeed(speed);
  board5.setFullSpeed(speed);
  board6.setMaxSpeed(speed);
  board6.setFullSpeed(speed);
  board7.setMaxSpeed(speed);
  board7.setFullSpeed(speed);
  board8.setMaxSpeed(speed);
  board8.setFullSpeed(speed);
  board9.setMaxSpeed(speed);
  board9.setFullSpeed(speed);
  board10.setMaxSpeed(speed);
  board10.setFullSpeed(speed);
  board11.setMaxSpeed(speed);
  board11.setFullSpeed(speed);
  board12.setMaxSpeed(speed);
  board12.setFullSpeed(speed);
}

void setAmplitude(int amp)  {
  amplitude = amp;
}

void initializeBoards()  {
  //Start initializing each board
  Serial.println("Initializing Board #1");
  board1.resetDev();
  board1.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board1.configStepMode(STEP_FS);   // 0 microsteps per step
  board1.setMaxSpeed(300);        // max step/s
  board1.setFullSpeed(300);       // microstep below 10000 steps/s
  board1.setAcc(30);             // accelerate at 10000 steps/s/s
  board1.setDec(30);
  board1.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board1.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board1.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board1.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board1.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board1.setSwitchMode(SW_USER);    // Switch is not hard stop
  board1.setOscMode(INT_16MHZ_OSCOUT_16MHZ); // for board1, we want 16MHz.
  Serial.println("Initializing Board #2");
  board2.resetDev();
  board2.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board2.configStepMode(STEP_FS);   // 0 microsteps per step
  board2.setMaxSpeed(300);        // max step/s
  board2.setFullSpeed(300);       // microstep below 10000 steps/s
  board2.setAcc(30);             // accelerate at 10000 steps/s/s
  board2.setDec(30);
  board2.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board2.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board2.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board2.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board2.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board2.setSwitchMode(SW_USER);    // Switch is not hard stop
  board2.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board2, we want 16MHz (inverted).
  Serial.println("Initializing Board #3");
  board3.resetDev();
  board3.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board3.configStepMode(STEP_FS);   // 0 microsteps per step
  board3.setMaxSpeed(300);        // max step/s
  board3.setFullSpeed(300);       // microstep below 10000 steps/s
  board3.setAcc(30);             // accelerate at 10000 steps/s/s
  board3.setDec(30);
  board3.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board3.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board3.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board3.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board3.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board3.setSwitchMode(SW_USER);    // Switch is not hard stop
  board3.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board3, we want 16MHz (inverted).
  Serial.println("Initializing Board #4");
  board4.resetDev();
  board4.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board4.configStepMode(STEP_FS);   // 0 microsteps per step
  board4.setMaxSpeed(300);        // max step/s
  board4.setFullSpeed(300);       // microstep below 10000 steps/s
  board4.setAcc(30);             // accelerate at 10000 steps/s/s
  board4.setDec(30);
  board4.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board4.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board4.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board4.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board4.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board4.setSwitchMode(SW_USER);    // Switch is not hard stop
  board4.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board4, we want 16MHz (inverted).
  Serial.println("Initializing Board #5");
  board5.resetDev();
  board5.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board5.configStepMode(STEP_FS);   // 0 microsteps per step
  board5.setMaxSpeed(300);        // max step/s
  board5.setFullSpeed(300);       // microstep below 10000 steps/s
  board5.setAcc(30);             // accelerate at 10000 steps/s/s
  board5.setDec(30);
  board5.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board5.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board5.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board5.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board5.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board5.setSwitchMode(SW_USER);    // Switch is not hard stop
  board5.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board5, we want 16MHz (inverted).
  Serial.println("Initializing Board #6");
  board6.resetDev();
  board6.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board6.configStepMode(STEP_FS);   // 0 microsteps per step
  board6.setMaxSpeed(300);        // max step/s
  board6.setFullSpeed(300);       // microstep below 10000 steps/s
  board6.setAcc(30);             // accelerate at 10000 steps/s/s
  board6.setDec(30);
  board6.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board6.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board6.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board6.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board6.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board6.setSwitchMode(SW_USER);    // Switch is not hard stop
  board6.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board6, we want 16MHz (inverted).
  Serial.println("Initializing Board #7");
  board7.resetDev();
  board7.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board7.configStepMode(STEP_FS);   // 0 microsteps per step
  board7.setMaxSpeed(300);        // max step/s
  board7.setFullSpeed(300);       // microstep below 10000 steps/s
  board7.setAcc(30);             // accelerate at 10000 steps/s/s
  board7.setDec(30);
  board7.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board7.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board7.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board7.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board7.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board7.setSwitchMode(SW_USER);    // Switch is not hard stop
  board7.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board7, we want 16MHz (inverted).
  Serial.println("Initializing Board #8");
  board8.resetDev();
  board8.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board8.configStepMode(STEP_FS);   // 0 microsteps per step
  board8.setMaxSpeed(300);        // max step/s
  board8.setFullSpeed(300);       // microstep below 10000 steps/s
  board8.setAcc(30);             // accelerate at 10000 steps/s/s
  board8.setDec(30);
  board8.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board8.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board8.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board8.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board8.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board8.setSwitchMode(SW_USER);    // Switch is not hard stop
  board8.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board8, we want 16MHz (inverted).
  Serial.println("Initializing Board #9");
  board9.resetDev();
  board9.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board9.configStepMode(STEP_FS);   // 0 microsteps per step
  board9.setMaxSpeed(300);        // max step/s
  board9.setFullSpeed(300);       // microstep below 10000 steps/s
  board9.setAcc(30);             // accelerate at 10000 steps/s/s
  board9.setDec(30);
  board9.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board9.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board9.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board9.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board9.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board9.setSwitchMode(SW_USER);    // Switch is not hard stop
  board9.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board9, we want 16MHz (inverted).
  Serial.println("Initializing Board #10");
  board10.resetDev();
  board10.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board10.configStepMode(STEP_FS);   // 0 microsteps per step
  board10.setMaxSpeed(300);        // max step/s
  board10.setFullSpeed(300);       // microstep below 10000 steps/s
  board10.setAcc(30);             // accelerate at 10000 steps/s/s
  board10.setDec(30);
  board10.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board10.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board10.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board10.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board10.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board10.setSwitchMode(SW_USER);    // Switch is not hard stop
  board10.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board10, we want 16MHz (inverted).
  Serial.println("Initializing Board #11");
  board11.resetDev();
  board11.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board11.configStepMode(STEP_FS);   // 0 microsteps per step
  board11.setMaxSpeed(300);        // max step/s
  board11.setFullSpeed(300);       // microstep below 10000 steps/s
  board11.setAcc(30);             // accelerate at 10000 steps/s/s
  board11.setDec(30);
  board11.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board11.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board11.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board11.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board11.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board11.setSwitchMode(SW_USER);    // Switch is not hard stop
  board11.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board11, we want 16MHz (inverted).
  Serial.println("Initializing Board #12");
  board12.resetDev();
  board12.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations; second paramter ignored.
  board12.configStepMode(STEP_FS);   // 0 microsteps per step
  board12.setMaxSpeed(300);        // max step/s
  board12.setFullSpeed(300);       // microstep below 10000 steps/s
  board12.setAcc(30);             // accelerate at 10000 steps/s/s
  board12.setDec(30);
  board12.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  board12.setOCThreshold(OC_1875mA);  // OC threshold 1875mA
  board12.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  board12.setOCShutdown(OC_SD_ENABLE); //  shutdown on over-current
  board12.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  board12.setSwitchMode(SW_USER);    // Switch is not hard stop
  board12.setOscMode(EXT_16MHZ_OSCOUT_INVERT); // for board12, we want 16MHz (inverted).*/
  Serial.println("All Boards Initialized - going to start-position!");
}

int receiveSerial()  {
  if (Serial3.available() > 0) {
          // read the incoming byte:
     incomingByte = Serial3.read();
     if (incomingByte > 0)  {
         return incomingByte;
     } else {
        return 0; 
     }
  } 
}

void changeWave(int type)  {
  if (type != waveType)  {
    changingWave = 1;
    stopWave();
    startNewWave(type);
    waveType = type;
  }
}

void stopWave()  {
  board1.softStop();
  board2.softStop();
  board3.softStop();
  board4.softStop();
  board5.softStop();
  board6.softStop();
  board7.softStop();
  board8.softStop();
  board9.softStop();
  board10.softStop();
  board11.softStop();
  board12.softStop();
  while (board12.busyCheck() == 1)  {
   Serial.print("BOARD BUSY: ");
   Serial.println(board12.busyCheck());
  }
  goToHome();
  //wait for them to go home
  while (board12.getPos() != 0 && board11.getPos() != 0 && board10.getPos() != 0 && board9.getPos() != 0 && board8.getPos() != 0 && board7.getPos() != 0 && board6.getPos() != 0 && board5.getPos() != 0 && board4.getPos() != 0 && board3.getPos() != 0 && board2.getPos() != 0 && board1.getPos() != 0)  {}
  
  Serial.println("stopWave finished");
}

void startNewWave(int type)  {
  if (type == 1 || type == 2)  {
    waveInclination = small;
    amplitude = 1000;
  } else if (type == 1 || type == 2)  {
    
  
  }
}

int allBusyCheck()  {
  if (board1.busyCheck() == 1 && board2.busyCheck() == 1 && board3.busyCheck() == 1 && board4.busyCheck() == 1 && board5.busyCheck() == 1 && board6.busyCheck() == 1 && board7.busyCheck() == 1 && board8.busyCheck() == 1 && board9.busyCheck() == 1 && board10.busyCheck() == 1 && board11.busyCheck() == 1 && board12.busyCheck() == 1)  {
    return 1;
  } else  {
    return 0;
  }
}
/*


*/
