#include <LiquidCrystal_I2C.h>
#include <Adafruit_Fingerprint.h>
#include <SPI.h>
#include <SD.h>
#define SS 10
File archivo;
String Estudiante1 = "Gustavo";
String Estudiante2 = "Andres";
String Estudiante3 = "Javier";
String Estudiante4 = "Antonio";
String Estudiante5 = "Esteban";

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
LiquidCrystal_I2C dis(0x27, 16, 2);

int lectura = 0;
const int lcd_on_off = 7;
const int huella_on_off = 8;

void setup() {
  Serial.begin(9600);
  pinMode(4,INPUT);
  pinMode(lcd_on_off, OUTPUT); 
  pinMode(huella_on_off, OUTPUT); 
  digitalWrite(huella_on_off, HIGH);    
  digitalWrite(lcd_on_off,HIGH);
  setup_lcd();
}

void loop() {
    lectura = digitalRead(4);
    if (lectura == 0){
      dis.clear();
      dis.print("Hasta pronto");
      delay(1500);
      dis.clear();
      digitalWrite(huella_on_off, LOW);
      dis.noBacklight();
      
    }
    else{
      dis.backlight();
      digitalWrite(huella_on_off, HIGH); 
      dis.clear();
      getFingerprintIDez();
      delay(500);
    }
}

void buen_registro(){
  dis.clear();
  dis.setCursor(0, 0);
  dis.print("Huella nro:");
  dis.setCursor(0, 1);
  dis.print(finger.fingerID);
  delay(1500);
  dis.clear();
  bienvenida();
}
void bienvenida(){
switch(finger.fingerID){
  case 1:
    registrasd1();
    Fun_estudiante1();
    break;   
  case 2:
    registrasd2();
    Fun_estudiante2();
    break;   
  case 3:
    registrasd3();
    Fun_estudiante3();
    break;   
  case 4:
    registrasd4();
    Fun_estudiante4();
    break;  
  case 5:
    registrasd5();
    Fun_estudiante5();
    break; 
}
}
void Mal_registro(){
  dis.clear();
  dis.setCursor(0, 0);
  dis.print("huella invalida");
  delay(1000);
  dis.clear();
  dis.print("Esperando");
  dis.setCursor(0, 1);
  dis.print("Huella...");  
    
  
}
int getFingerprintIDez(){
  dis.print("Esperando");
  dis.setCursor(0, 1);
  dis.print("Huella..."); 
  uint8_t p = finger.getImage();
  if(p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if(p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if(p != FINGERPRINT_OK){
    Mal_registro();
    return -1;
  }
  buen_registro();
}
void  iniciasd(){
  archivo = SD.open("prueba_1.txt", FILE_WRITE);
  if(archivo){
     archivo.print(Estudiante1);
     archivo.print(",");
     archivo.print(Estudiante2);
     archivo.print(",");
     archivo.print(Estudiante3);
     archivo.print(",");
     archivo.print(Estudiante4);
     archivo.print(",");
     archivo.println(Estudiante5);
     delay(500);
     archivo.close();
     delay(500);
  }
  else{
    Serial.println("Error en apertura de archivo");
    delay(2000);
  }
}

void  registrasd1(){
  archivo = SD.open("prueba_1.txt", FILE_WRITE);
  if(archivo){
     archivo.seek(archivo.size());
     archivo.print(1);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.println(0);
     delay(500);
     archivo.close();
     delay(500);
  }
  else{
    delay(2000);
  }
}
void  registrasd2(){
  archivo = SD.open("prueba_1.txt", FILE_WRITE);
  if(archivo){
     archivo.seek(archivo.size());
     archivo.print(0);
     archivo.print(",");  
     archivo.print(1);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.println(0);
     delay(500);
     archivo.close();
     delay(500);
  }
  else{
    delay(2000);
  }
}
void  registrasd3(){
  archivo = SD.open("prueba_1.txt", FILE_WRITE);
  if(archivo){
     archivo.seek(archivo.size());
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(1);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.println(0);
     delay(500);
     archivo.close();
     delay(500);
  }
  else{
    delay(2000);
  }
}
void  registrasd4(){
  archivo = SD.open("prueba_1.txt", FILE_WRITE);
  if(archivo){
     archivo.seek(archivo.size());
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(1);
     archivo.print(",");
     archivo.println(0);
     delay(500);
     archivo.close();
     delay(500);
  }
  else{
    delay(2000);
  }
}
void  registrasd5(){
  archivo = SD.open("prueba_1.txt", FILE_WRITE);
  if(archivo){
     archivo.seek(archivo.size());
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.print(0);
     archivo.print(",");
     archivo.println(1);
     delay(500);
     archivo.close();
     delay(500);
  }
  else{
    delay(2000);
  }
}
void Fun_estudiante1(){
    dis.clear();
    dis.setCursor(0, 0);
    dis.print("Bienvenido");
    dis.setCursor(0, 1);
    dis.print(Estudiante1);
    delay(1500);
    dis.clear();
    if(!SD.begin(SS)){
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Fallo!");
     delay(1500);
     dis.clear();
    }
    else{
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Realizado!");
     delay(1500);
     dis.clear();
    }
    dis.print("Esperando");
    dis.setCursor(0, 1);
    dis.print("Huella..."); 
}
void Fun_estudiante2(){
    dis.clear();
    dis.setCursor(0, 0);
    dis.print("Bienvenido");
    dis.setCursor(0, 1);
    dis.print(Estudiante2);
    delay(1500);
    dis.clear();
    if(!SD.begin(SS)){
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Fallo!");
     delay(1500);
     dis.clear();
    }
    else{
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Realizado!");
     delay(1500);
     dis.clear();
    }
    dis.print("Esperando");
    dis.setCursor(0, 1);
    dis.print("Huella..."); 
}
void Fun_estudiante3(){
    dis.clear();
    dis.setCursor(0, 0);
    dis.print("Bienvenido");
    dis.setCursor(0, 1);
    dis.print(Estudiante3);
    delay(1500);
    dis.clear();
    if(!SD.begin(SS)){
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Fallo!");
     delay(1500);
     dis.clear();
    }
    else{
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Realizado!");
     delay(1500);
     dis.clear();
    }
    dis.print("Esperando");
    dis.setCursor(0, 1);
    dis.print("Huella..."); 
}
void Fun_estudiante4(){
    dis.clear();
    dis.setCursor(0, 0);
    dis.print("Bienvenido");
    dis.setCursor(0, 1);
    dis.print(Estudiante4);
    delay(1500);
    dis.clear();
    if(!SD.begin(SS)){
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Fallo!");
     delay(1500);
     dis.clear();
    }
    else{
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Realizado!");
     delay(1500);
     dis.clear();
    }
    dis.print("Esperando");
    dis.setCursor(0, 1);
    dis.print("Huella..."); 
}
void Fun_estudiante5(){
    dis.clear();
    dis.setCursor(0, 0);
    dis.print("Bienvenido");
    dis.setCursor(0, 1);
    dis.print(Estudiante5);
    delay(1500);
    dis.clear();
    if(!SD.begin(SS)){
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Fallo!");
     delay(1500);
     dis.clear();
    }
    else{
     dis.setCursor(0,0);
     dis.print("Guardado");
     dis.setCursor(0, 1);
     dis.print("Realizado!");
     delay(1500);
     dis.clear();
    }
    dis.print("Esperando");
    dis.setCursor(0, 1);
    dis.print("Huella..."); 
}
void setup_lcd(){
  finger.begin(57600);
  dis.init();
  dis.backlight();
  dis.setCursor(0, 0);
  dis.clear();
  delay(5);
  if(finger.verifyPassword()){
    dis.print("Sensor Activo!");
    delay(1500);
    dis.clear();
  }
  else{
    dis.print("Error 406");
    delay(1500);
    dis.clear();
    dis.print("revise conexion");
    while(1) {delay(1);}
  }
  if(!SD.begin(SS)){
     dis.print("Sd Fallo!");
     delay(1500);
     dis.clear();
  }
   else{
     dis.print("Sd Inicio!");
     delay(1500);
     dis.clear();
  }
  finger.getTemplateCount();
  dis.print("Total de Huellas:");
  dis.setCursor(0, 1);
  dis.print(finger.templateCount);
  delay(2000);
  dis.clear();
  dis.setCursor(0, 0); 
  dis.print("Esperando");
  dis.setCursor(0, 1);
  dis.print("huella...");
}
