#include <Wire.h>  // Library untuk komunikasi I2C
#include <LiquidCrystal_I2C.h>  // Library untuk LCD I2C
#include <Adafruit_Sensor.h>  // Library untuk sensor DHT
#include <DHT.h>  // Library untuk sensor DHT22

#define DHT_PIN 2     // Pin digital yang terhubung dengan sensor DHT22
#define DHT_TYPE DHT22   // Jenis sensor DHT (DHT22)

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inisialisasi objek LCD I2C

void setup() {
  Wire.begin();
  lcd.begin(16, 2);  // Inisialisasi LCD I2C dengan ukuran 16 kolom dan 2 baris
  lcd.backlight();  // Mengaktifkan backlight LCD
  lcd.setCursor(0, 0);
  lcd.print("Monitoring DHT22");
  delay(2000);
  lcd.clear();
  
  Serial.begin(9600);  // Inisialisasi komunikasi serial
}

void loop() {
  float temperature = dht.readTemperature();  // Membaca data suhu
  float humidity = dht.readHumidity();  // Membaca data kelembaban

  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Kelembaban: ");
  lcd.print(humidity);
  lcd.print("%");
  
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print("C, Kelembaban: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}
