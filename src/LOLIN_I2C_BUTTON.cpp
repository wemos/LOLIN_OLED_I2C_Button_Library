#include "LOLIN_I2C_BUTTON.h"

/* 

*/
I2C_BUTTON::I2C_BUTTON(uint8_t address)
{
	Wire.begin();
	_address = address;
}

unsigned char I2C_BUTTON::get()
{
	send_data[0] = GET_KEY_VALUE;
	unsigned char result = sendData(send_data, 1);

	BUTTON_A= (get_data[0]>>4);

	BUTTON_B= (get_data[0]&0x0f);
	return result;
}

unsigned char I2C_BUTTON::reset()
{
	send_data[0] = RESET_SLAVE;
	unsigned char result = sendData(send_data, 1);

	return result;
}

unsigned char I2C_BUTTON::changeAddress(unsigned char address)
{
	send_data[0] = CHANGE_I2C_ADDRESS;
	send_data[1] = address;
	unsigned char result = sendData(send_data, 2);

	return result;
}

unsigned char I2C_BUTTON::sendData(unsigned char *data, unsigned char len)
{
	unsigned char i;


	Wire.beginTransmission(_address);
	for (i = 0; i < len; i++)
		Wire.write(data[i]);
	Wire.endTransmission();
	delay(50);

	if (data[0] == GET_SLAVE_STATUS)
		Wire.requestFrom(_address, 2);
	else
		Wire.requestFrom(_address, 1);

	i=0;

	while (Wire.available())
	{
		get_data[i] = Wire.read();
		i++;

	}

	return 0;
}
