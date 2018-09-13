#include <Wire.h> // Include Wire if you're using I2C
#include <LOLIN_I2C_BUTTON.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2C_BUTTON_ADDRESS 0x28
#define OLED_RESET -1 // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

I2C_BUTTON button(I2C_BUTTON_ADDRESS);

String keyString[] = {"None", "Press", "Long", "Double", "Hold"};

void setup()
{
    Serial.begin(115200);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.setTextColor(WHITE);
    

    button.get();

    if (button.BUTTON_A)
    {
        display.println("A: ");
        display.println(keyString[button.BUTTON_A]);
    }

    if (button.BUTTON_B)
    {
        display.println("B: ");
        display.println(keyString[button.BUTTON_B]);
    }
    display.display();
    delay(500);
}