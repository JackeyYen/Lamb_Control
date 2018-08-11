
const int  buttonPinU = 30;
const int  buttonPinD = 32;
const int  buttonPin4 = 34;
const int  buttonPin3 = 36;
const int  buttonPin2 = 38;
const int  buttonPin1 = 40;

const int ledPin4 = 22;
const int ledPin3 = 24;
const int ledPin2 = 26;
const int ledPin1 = 28;

int buttonPushCounter = 0;              // 定义用来记录按键次数的整型变量

int buttonStateU = 0;                   // 记录当前按键的状态
int buttonStateD = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

int lastButtonStateU = 0;               // 对Arduino电路板或相关状态进行初始化方法
int lastButtonStateD = 0;
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int lastButtonState4 = 0;

void setup() {
  pinMode(buttonPinU, INPUT);             // 设置按键的针脚为输入状态
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonStateU = digitalRead(buttonPinU);     // 读取按键的输入状态
  buttonStateD = digitalRead(buttonPinD);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  // 判断当前的按键状态是否和之前有所变化
  if (buttonStateU != lastButtonStateU) {
    // 判断当前按键是否为按下状态，
    // 如果为按下状态，则记录按键次数的变量加一。
    if (buttonStateU == HIGH) {
      buttonPushCounter++;                      // 将记录按键次数的变量加一

      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }


  if (buttonStateD != lastButtonStateD) {
    // 判断当前按键是否为按下状态，
    // 如果为按下状态，则记录按键次数的变量加一。
    if (buttonStateD == HIGH) {
      buttonPushCounter--;                  // 将记录按键次数的变量加一
      
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }

   if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      buttonPushCounter = 1;

      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }

   if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      buttonPushCounter = 2;

      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }

   if (buttonState3 != lastButtonState3) {
    if (buttonState3 == HIGH) {
      buttonPushCounter = 3;

      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }

   if (buttonState4 != lastButtonState4) {
    if (buttonState4 == HIGH) {
      buttonPushCounter = 4;

      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }

  
  // 将每次loop结束时最新的按键状态进行更新
  lastButtonStateU = buttonStateU;
  lastButtonStateD = buttonStateD;
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;

  if (buttonPushCounter  >= 5) {
    buttonPushCounter = 0;
  }
  if (buttonPushCounter <= -1) {
    buttonPushCounter = 4;
    }

   if (buttonPushCounter == 1) {
    digitalWrite(ledPin1, HIGH);
    }
    else {
    digitalWrite(ledPin1, LOW);
  }
  
   if (buttonPushCounter == 2) {
    digitalWrite(ledPin2, HIGH);
    }
    else {
    digitalWrite(ledPin2, LOW);
  }
  
   if (buttonPushCounter == 3) {
    digitalWrite(ledPin3, HIGH);
    }
    else {
    digitalWrite(ledPin3, LOW);
  }
  
   if (buttonPushCounter == 4) {
    digitalWrite(ledPin4, HIGH);
}
else {
    digitalWrite(ledPin4, LOW);
  }
  
}
