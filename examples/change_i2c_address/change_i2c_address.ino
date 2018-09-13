#include <LOLIN_I2C_BUTTON.h>

byte new_address = 1;

void setup()
{
    Wire.begin();

    Serial.begin(115200);
}

void loop()
{
    byte error, address;

    Serial.println("Scanning...");
    for (address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {

            I2C_BUTTON button(address);
            button.getInfo();
            if (button.PRODUCT_ID == PRODUCT_ID_I2C_BUTTON)
            {
                Serial.print("I2C BUTTON found at address 0x");
                if (address < 16)
                    Serial.print("0");
                Serial.println(address, HEX);

                Serial.print("Firmware Version: ");
                Serial.println(button.VERSION);

                Serial.print("Try to change Address to 0x");
                if (new_address < 16)
                    Serial.print("0");
                Serial.println(new_address, HEX);
                Serial.println("");

                button.changeAddress(new_address);
                new_address++;
            }
        }
    }

    delay(2000);
}
