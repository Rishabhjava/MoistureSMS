char phone_no[] = "0561162683";
int moistPin = 0;
int moistVal = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop()
{
  moistVal = analogRead(moistPin);
  Serial.println(moistVal);
  int percent = 2.718282 * 2.718282 * (.008985 * moistVal + 0.207762); //calculate percent for probes about 1 - 1.5 inches apart
  Serial.print(percent);
  Serial.println("% Moisture ");
  if (percent < 15)
  {
    digitalWrite(13, HIGH); // if the sensor value is below 50% led on your nano will glow else it is off
    delay(500);
    digitalWrite(13, LOW); 
    delay(500);
    digitalWrite(13, HIGH); 
    Serial.println("AT+CMGF=1");
    delay(2000);
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.write(0x22);
    Serial.write(0x0D);  // hex equivalent of Carraige return
    Serial.write(0x0A);  // hex equivalent of newline
    delay(1000);
    Serial.print(percent);
    delay(500);
    Serial.println (char(26));//the ASCII code of the ctrl+z is 26
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH); 
    digitalWrite(13, HIGH); // if the sensor value is below 50% led on your nano will glow else it is off
    delay(500);
    digitalWrite(13, LOW); 
    delay(500);
    digitalWrite(13, HIGH); 
    Serial.println("AT+CMGF=1");
    delay(2000);
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.write(0x22);
    Serial.write(0x0D);  // hex equivalent of Carraige return
    Serial.write(0x0A);  // hex equivalent of newline
    delay(1000);
    Serial.print(percent);
    delay(500);
    Serial.println (char(26));//the ASCII code of the ctrl+z is 26
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);  
    delay (3600000);
  }
    else
    
  {
    digitalWrite(13, LOW);
  }

  delay(250); // for stability
}
