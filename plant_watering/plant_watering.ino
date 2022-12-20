int waterpump = 3; //pump relay pin

void setup() {
pinMode(waterpump, OUTPUT);
Serial.begin(9600);
pinMode(13, INPUT_PULLUP);

}

void loop() {
int humidityRaw = analogRead(A0); //1023 to 0 ===> 0 to 100%
int humidityReal = map(humidityRaw, 1023, 0, 0, 100);
Serial.println("\n humidityReal=");
Serial.println(humidityRaw);

//if (humidityRaw > 35)
if (humidityRaw > 970)
{
Serial.println("\n humidityReal=");
Serial.println(humidityRaw);
digitalWrite(waterpump, LOW);
Serial.write("Pump On\n");
delay(1000);
digitalWrite(waterpump, HIGH);
Serial.write("Pump Off 1\n");
delay(900000);
}
else{
digitalWrite(waterpump, HIGH);
Serial.write("Pump Off 2\n");
delay(1000);
}

}
