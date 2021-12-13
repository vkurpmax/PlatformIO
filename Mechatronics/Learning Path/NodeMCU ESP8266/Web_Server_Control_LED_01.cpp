// Protus Tanuhandaru
// www.progresstech.co.id
// www.karyaone.co.id

#include <ESP8266_WiFi.h>   // Library ESP8266
#include <ESP8266WebServer.h>   // Library Web Server ESP8266

const char* ssid = "Nama SSID"; // Variabel nama SSID
const char* password = "Password SSID"; // Variable password SSID

ESP8266WebServer server(80);    // Deklarasi server dengan port 80

uint8_t pinLED = D5;    // D5 atau GPIO 14 sebagai PIN LED
bool statusLED = LOW;   // Nilai awal LED adalah 0

void setup()
{
    Serial.begin(115200);   // Komunikasi serial Baud Rate 115200
    delay(100);
    pinMode(pinLED, OUTPUT);    // Membuat PIN LED sebagai output

    Serial.println("Menghubungi ");
    Serial.println(ssid);
    Wifi.begin(ssid, password); // Otentikasi sambungan Wifi

    // Mengecek apakah Wifi tersambung
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi tersambung..!");
    Serial.print("Nomor IP: ");
    Serial.println(WiFi.localIP()); // Nomor IP Modul

    // Status LED
    server.on("/", tersambung);
    server.on("/ledmenyala", LED_menyala);
    server.on("/ledmati", LED_mati);
    server.onNotFoud(tidak_ditemukan);
    server.begin();
    Serial.println("Memulai HTTP server");
}

// Fungsi untuk semua status LED
void tersambung()
{
    statusLED = LOW;
    server.send(200, "text/html", kirimHTML(statusLED));
}

void LED_menyala()
{
    status LED = HIGH;
    server.send(200, "text/html", kirimHTML(statusLED));
}

void LED_mati()
{
    statusLED = LOW;
    server.send(200, "text/html", kirimHTML(statusLED));
}

void tidak_ditemukan()
{
    server.send(404, "text/plain", "Halaman tidak ditemukan");
}


// Fungsi untuk mengemas kode HTML yang dikembalikan sebagai string
String kirimHTML(uint8_t statusLED)
{
    String konten = "<html>\n";
    konten +="<head>\n";
    konten +="<title>LED Control</title>\n";
    konten +="</head>\n";
    konten +="<body>\n";
    konten +="<h1 style=\"font-size:100px\">Mengendalikan LED</h1>\n";

    if(statusLED)
    {
        konten +="<p style=\"font-size:80px\">Status LED: ON</p>\n";
        konten +="<a href=\"/ledmati\">\n";
        konten +="<button type=\"button\" style=\"font-size:150px\">OFF</button>\n";
        konten +="</a>\n";
    }

    else
    {
        konten +="<p style=\"font-size:80px\">Status LED: OFF</p>\n";
        konten +="<a href=\"/ledmenyala\">/n";
        konten +="<button type=\"button\" style=\"font-size:150px\">ON</button>\n";
        konten +="</a>/n";
    }

    konten +="</body>\n";
    konten +="</html>\n";
    return konten;
}

void loop()
{
    server.handleClient();
    if (statusLED)
    {
        digitalWrite(pinLED, HIGH);
    }
    else
    {
        digitalWrite(pinLED, LOW);
    }
}