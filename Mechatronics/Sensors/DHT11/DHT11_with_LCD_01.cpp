#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);    // Ganti 0x3F ke 0x27 kalau LCD ga muncul

#include <DHT.h>
DHT dht(2, DHT11);                      // Pin, Jenis DHT

int powerPin = 3;                       // Untuk pengganti VCC 5V

void setup()
{
    lcd.init();                         // Print a message to LCD
    lcd.backlight();                    // Jadikan pin power sebagai output
    pinMode(powerPin, OUTPUT);          // Default bernilai LOW
    digitalWrite(powerPin, LOW);
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
    digitalWrite(powerPin, HIGH);

    float kelembaban = dht.readHumidity();
    float suhu = dht.readTemperature();

    Serial.print("Kelembaban: ");
    Serial.pirnt(kelembaban);
    Serial.print(" ");
    Serial.print("Suhu: ");
    Serial.println(suhu);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kelembaban: ");
    lcd.setCursor(11, 0);
    lcd.print(kelembaban);

    lcd.setCursor(0, 1);
    lcd.print("Suhu: ");
    lcd.setCursor(5, 1);
    lcd.print(suhu);
    delay(1000);
}