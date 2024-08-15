
#define LED D1 // LED
int ValueRead=2;
int myflag=0;

void setup()
{
 Serial.begin(9600);
 pinMode(LED, OUTPUT);
 digitalWrite(LED, LOW); //LED comienza apagado
}

void loop()
{
 if (Serial.available()){
   ValueRead=Serial.parseInt();
 }
   if (((ValueRead==1 && myflag==0)|| myflag==1)&!(ValueRead==2 && myflag==1)){
     digitalWrite(LED, HIGH);  // Se prende el LED
     Serial.println("Prendido");
     myflag=1;
   }
   else{
     digitalWrite(LED, LOW);   // Se apaga el LED
     Serial.println("Apagado");
     myflag=0;
   }
}