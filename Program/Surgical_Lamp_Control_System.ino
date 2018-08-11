//按鈕
const int  buttonPinU = 30;
const int  buttonPinD = 32;
const int  buttonPin4 = 34;
const int  buttonPin3 = 36;
const int  buttonPin2 = 38;
const int  buttonPin1 = 40;

//指示燈
const int ledPin4 = 22;
const int ledPin3 = 24;
const int ledPin2 = 26;
const int ledPin1 = 28;

// 手術燈
const int ledPinWL1 = 5;
const int ledPinWL2 = 6;
const int ledPinWL3 = 9;
const int ledPinG = 10;
const int ledPinB = 11;

// 記錄切換狀態(累計狀態)
int buttonPushCounter = 0; 

// 讀取按鈕資料
int buttonStateU = 0;
int buttonStateD = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

// 对Arduino电路板或相关状态进行初始化方法
int lastButtonStateU = 0;
int lastButtonStateD = 0;
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int lastButtonState4 = 0;
int lastbuttonPushCounter = 0;

// 用brightness變數來保存目前LED燈的PWM值
int brightnessWL1 = 0;
int brightnessWL2 = 0;
int brightnessWL3 = 0;
int brightnessG = 0;
int brightnessB = 0;

// 設定每個模組的PWM值
// 3500K model
int Amodel1 = 255;   // WL1
int Amodel2 = 0;     // WL2
int Amodel3 = 0;     // WL3
int Amodel4 = 0;     // G
int Amodel5 = 0;     // B

// 4000K model
int Bmodel1 = 0;
int Bmodel2 = 255;
int Bmodel3 = 0;
int Bmodel4 = 0;
int Bmodel5 = 0;

// 4500K model
int Cmodel1 = 0;
int Cmodel2 = 0;
int Cmodel3 = 0;
int Cmodel4 = 255;
int Cmodel5 = 0;

// 5000K model
int Dmodel1 = 0;
int Dmodel2 = 0;
int Dmodel3 = 0;
int Dmodel4 = 0;
int Dmodel5 = 255;


void setup() {
  pinMode(ledPinWL1, OUTPUT);
  pinMode(ledPinWL2, OUTPUT);
  pinMode(ledPinWL3, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  pinMode(buttonPinU, INPUT);
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // 讀取按鈕的狀態並保存到buttonState變數裡:
  buttonStateU = digitalRead(buttonPinU);
  buttonStateD = digitalRead(buttonPinD);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

//--------------------------按鍵判斷與狀態顯示------------------------------

// 判断当前的按键状态是否和之前有所变化
  if (buttonStateU != lastButtonStateU) {
    if (buttonStateU == HIGH) {
      buttonPushCounter++;
    }
    delay(50);
  }


  if (buttonStateD != lastButtonStateD) {
    if (buttonStateD == HIGH) {
      buttonPushCounter--;
    }
    delay(50);
  }


   if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      buttonPushCounter = 1;
    }
    delay(50);
  }


   if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      buttonPushCounter = 2;
    }
    delay(50);
  }


   if (buttonState3 != lastButtonState3) {
    if (buttonState3 == HIGH) {
      buttonPushCounter = 3;
    }
    delay(50);
  }


   if (buttonState4 != lastButtonState4) {
    if (buttonState4 == HIGH) {
      buttonPushCounter = 4;
    }
    delay(50);
  }

// -------------------------------------------------------------------------

//---------------------------狀態判斷執行輸出-------------------------------

// 將每次loop結束時最新的按鈕狀態進行更新
  lastButtonStateU = buttonStateU;
  lastButtonStateD = buttonStateD;
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;

//設定狀態計數器範圍
  if (buttonPushCounter  >= 5) {
    buttonPushCounter = 0;
  }
  if (buttonPushCounter <= -1) {
    buttonPushCounter = 4;
    }

//設定每個狀態的輸出
// 3500K model
   if (buttonPushCounter == 1) {
    digitalWrite(ledPin1, HIGH);

     analogWrite(ledPinWL1, Amodel1);
     analogWrite(ledPinWL2, Amodel2);
     analogWrite(ledPinWL3, Amodel3);
     analogWrite(ledPinG, Amodel4);
     analogWrite(ledPinB, Amodel5);

    Serial.print(" Color Temperature:  ");
    Serial.println(" 3500K ");
    Serial.print(" Colors PWM value:  ");
    Serial.print(Amodel1);
    Serial.print(" , ");
    Serial.print(Amodel2);
    Serial.print(" , ");
    Serial.print(Amodel3);
    Serial.print(" , ");
    Serial.print(Amodel4);
    Serial.print(" , ");
    Serial.println(Amodel5);
    Serial.print("------------------");
    Serial.println("----------");
    }
    else {
    digitalWrite(ledPin1, LOW);
  }


// 4000k model
   if (buttonPushCounter == 2) {
    digitalWrite(ledPin2, HIGH);
    analogWrite(ledPinWL1, Bmodel1);
    analogWrite(ledPinWL2, Bmodel2);
    analogWrite(ledPinWL3, Bmodel3);
    analogWrite(ledPinG, Bmodel4);
    analogWrite(ledPinB, Bmodel5);

    Serial.print(" Color Temperature:  ");
    Serial.println(" 4000K ");
    Serial.print(" Colors PWM value:  ");
    Serial.print(Bmodel1);
    Serial.print(" , ");
    Serial.print(Bmodel2);
    Serial.print(" , ");
    Serial.print(Bmodel3);
    Serial.print(" , ");
    Serial.print(Bmodel4);
    Serial.print(" , ");
    Serial.println(Bmodel5);
    Serial.print("------------------");
    Serial.println("----------");
    }
    else {
    digitalWrite(ledPin2, LOW);
  }

// 4500k model
   if (buttonPushCounter == 3) {
    digitalWrite(ledPin3, HIGH);
    analogWrite(ledPinWL1, Cmodel1);
    analogWrite(ledPinWL2, Cmodel2);
    analogWrite(ledPinWL3, Cmodel3);
    analogWrite(ledPinG, Cmodel4);
    analogWrite(ledPinB, Cmodel5);

    Serial.print(" Color Temperature:  ");
    Serial.println(" 4500K ");
    Serial.print(" Colors PWM value:  ");
    Serial.print(Cmodel1);
    Serial.print(" , ");
    Serial.print(Cmodel2);
    Serial.print(" , ");
    Serial.print(Cmodel3);
    Serial.print(" , ");
    Serial.print(Cmodel4);
    Serial.print(" , ");
    Serial.println(Cmodel5);
    Serial.print("------------------");
    Serial.println("----------");
    }
    else {
    digitalWrite(ledPin3, LOW);
  }

// 5000k model
   if (buttonPushCounter == 4) {
    digitalWrite(ledPin4, HIGH);
    analogWrite(ledPinWL1, Dmodel1);
    analogWrite(ledPinWL2, Dmodel2);
    analogWrite(ledPinWL3, Dmodel3);
    analogWrite(ledPinG, Dmodel4);
    analogWrite(ledPinB, Dmodel5);

    Serial.print(" Color Temperature:  ");
    Serial.println(" 5000K ");
    Serial.print(" Colors PWM value:  ");
    Serial.print(Dmodel1);
    Serial.print(" , ");
    Serial.print(Dmodel2);
    Serial.print(" , ");
    Serial.print(Dmodel3);
    Serial.print(" , ");
    Serial.print(Dmodel4);
    Serial.print(" , ");
    Serial.println(Dmodel5);
    Serial.print("------------------");
    Serial.println("----------");
}
else {
    digitalWrite(ledPin4, LOW);
  }

// -------------------------------------------------------------------------
  
    delay(50);       // 每一次調整亮度的時間延遲 
}
