#include <LOLIN_I2C_BUTTON.h>

I2C_BUTTON button;

String keyString[] = {"None", "Press", "Long Press", "Double Press", "Hold"};

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (button.get() == 0)
  {
    if (button.BUTTON_A)
    {
      Serial.print("BUTTON A: ");
      Serial.println(keyString[button.BUTTON_A]);
    }

    if (button.BUTTON_B)
    {
      Serial.print("BUTTON B: ");
      Serial.println(keyString[button.BUTTON_B]);
    }
  }

  delay(100);
}