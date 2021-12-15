/*-----------------------------------------------------------------
DHT Tester bagian 1
-----------------
AT-MO PRODUCTION
EDIT OGI SINATRA
------------------
TOLONG JIKA MENGGUNAKAN CODE INI MASUKAN TULISAN YANG DI ATAS
-----------------------------------------------------------------*/

#include "DHT.h"

#define DHTPIN 2 // definisikan pin yang digunakan utk sensor DHT11

// Tentukan jenis DHT yang digunakan (pilih salah satu)
// Saat ini yang dipilih adalah DHT11
#define DHTTYPE DHT11 // DHT 11 
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
  dht.begin();

}

void loop() {
  // Baca humidity dan temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Cek hasil pembacaan, dan tampilkan bila ok
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: ");//kelembaban
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
}

