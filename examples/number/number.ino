#include <Wire.h>
#include <LOLIN_I2C_BUTTON.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2C_BUTTON_ADDRESS DEFAULT_I2C_ADDRESS //0x31
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

I2C_BUTTON button(I2C_BUTTON_ADDRESS);

byte number = 0;

void setup()
{
    Serial.begin(115200);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{

    if (button.get() == 0)
    {
        display.clearDisplay();
        display.setTextSize(2);
        display.setCursor(0, 0);
        display.setTextColor(WHITE);

        switch (button.BUTTON_B)
        {
        case KEY_VALUE_NONE:
            break;

        case KEY_VALUE_SHORT_PRESS:
            number++;
            break;

        case KEY_VALUE_DOUBLE_PRESS:
            number += 2;
            break;

        case KEY_VALUE_HOLD:
            number += 10;
            break;

        case KEY_VALUE_LONG_PRESS:

            break;
        }

        switch (button.BUTTON_A)
        {
        case KEY_VALUE_NONE:
            break;

        case KEY_VALUE_SHORT_PRESS:
            number--;
            break;

        case KEY_VALUE_DOUBLE_PRESS:
            number -= 2;
            break;

        case KEY_VALUE_HOLD:
            number -= 10;
            break;

        case KEY_VALUE_LONG_PRESS:

            break;
        }

        display.println(number);

        display.display();
    }

    delay(100);
}
