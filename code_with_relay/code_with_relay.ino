#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define inSensor 8
#define outSensor 9

int inStatus;
int outStatus;

int countin = 0;
int countout = 0;

int in;
int out;
int now;

#define relay 10

void setup() {
    lcd.begin(16, 2);
    lcd.print("Bi-Directional");
    lcd.setCursor(0, 1);
    lcd.print("Visitor Counter");
    delay(2000);
    lcd.clear();
    lcd.print("Made by :-");
    lcd.setCursor(0, 1);
    lcd.print("Pratik & Anshul");
    delay(1500);
    lcd.clear();
    pinMode(inSensor, INPUT);
    pinMode(outSensor, INPUT);
    pinMode(relay, OUTPUT);
}

void loop() {
    inStatus = digitalRead(inSensor);
    outStatus = digitalRead(outSensor);
    if (inStatus == 0) {
        in = countin++;
    }

    if (outStatus == 0) {
        out = countout++;
    }

    now = in - out;

    if (now <= 0) {
        digitalWrite(relay, HIGH);
        lcd.clear();
        lcd.print("No Visitors");
        lcd.setCursor(0, 1);
        lcd.print("Light is Off!");
        delay(500);
    } else {
        digitalWrite(relay, LOW);
        lcd.clear();
        lcd.print("Current Visitors");
        lcd.setCursor(0, 1);
        //    lcd.print("Current Visitors");
        lcd.print(now);
        //    lcd.print(" IN: ");
        //    lcd.print(in);
        //    lcd.print("OUT: ");
        //    lcd.print(out);
        delay(500);
    }
}
