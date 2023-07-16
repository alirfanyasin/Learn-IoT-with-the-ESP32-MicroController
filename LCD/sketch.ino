#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(115200);
  lcd.init(); // Inisialisasi LCD dengan ukuran 16 kolom dan 2 baris
  lcd.backlight();
  
}

void loop() {
  // Kode lain yang ingin Anda tambahkan ke dalam loop
  lcd.setCursor(0, 0); // Mengatur posisi kursor di baris pertama, kolom pertama
  lcd.print("Hello World"); // Menampilkan teks pada LCD
}
