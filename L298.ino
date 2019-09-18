/*
 * Code Modified By: Mohamad Hafiz Bin Ahmad
 * Email: hafiz_apik99@yahoo.com
 * Youtube: https://www.youtube.com/channel/UC15t8HwKsRL2lTeP8uZlUjQ
*/
#include <SoftwareSerial.h>

//MOTOR KANAN
int enB = 5;
int in4 = 6;
int in3 = 7;

//MOTOR KIRI
int in2 = 8;
int in1 = 9;
int enA = 10;

char t;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
 
void loop() 
{
    if(Serial.available())
    {
      t = Serial.read();
      Serial.println(t);
    }
      
         if(t == 'F') //gerak kehadapan    
         {                
          Serial.println("Forward");

          //MOTOR KIRI 
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          analogWrite(enA, 200);
          //MOTOR KANAN
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          analogWrite(enB, 200);
          
        }
         
        else if(t == 'G') //gerak ke belakang  
        {             
          Serial.println("backward");
          //MOTOR KIRI 
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          analogWrite(enA, 200);
          //MOTOR KANAN
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
          analogWrite(enB, 200);
        }
         
        else if(t == 'L') //pusing ke kiri 
        {                 
          Serial.println("left");
          //MOTOR KIRI 
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          //MOTOR KANAN
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          analogWrite(enB, 200);
        }
         
        else if(t == 'R') //pusing ke kanan
        {                 
          Serial.println("right");
          //MOTOR KIRI 
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          analogWrite(enA, 200);
          //MOTOR KANAN
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }

          else if(t== 'S')//berhenti  
          {
          Serial.println("stop");       
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW); 
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW); 
          }
        delay(50);
        
     
}
