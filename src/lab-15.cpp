/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/ianp/Documents/iot2021/labs/lab-15/src/lab-15.ino"
void setup();
void loop();
void T1(void *args);
void T2(void *args);
void T3(void *args);
#line 1 "/home/ianp/Documents/iot2021/labs/lab-15/src/lab-15.ino"
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

os_thread_t t1;
os_thread_t t2;
os_thread_t t3;

int inc = 0;

void setup()
{
  Serial.begin(9600);

  os_thread_create(&t1, "t1", OS_THREAD_PRIORITY_DEFAULT, T1, NULL, 1024);
  os_thread_create(&t2, "t2", OS_THREAD_PRIORITY_DEFAULT, T2, NULL, 1024);
  os_thread_create(&t3, "t3", OS_THREAD_PRIORITY_DEFAULT, T3, NULL, 1024);

  pinMode(D7, OUTPUT);
}

void loop()
{
}

void T1(void *args)
{
  while (1)
  {
    WITH_LOCK(Serial)
    {
      Serial.println("random value: " + String(random(100)));
    }
    delay(1000);
  }
}

void T2(void *args)
{

  while (1)
  {
    WITH_LOCK(Serial)
    {
      Serial.println("incremented value: " + String(inc));
    }
    delay(500);
    inc += 1;
  }
}

void T3(void *args)
{
  while (1)
  {
    digitalWrite(D7, HIGH);
    delay(250);
    digitalWrite(D7, LOW);
    delay(250);
  }
}