
#ifndef __LOLIN_I2C_BUTTON_H
#define __LOLIN_I2C_BUTTON_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"

#define DEFAULT_I2C_ADDRESS 0x31

enum I2C_CMD
{
  GET_SLAVE_STATUS = 0x01,
  RESET_SLAVE,
  CHANGE_I2C_ADDRESS,
  GET_KEY_VALUE,
  CHANGE_KEY_A_LONG_PRESS_TIME,
  CHANGE_KEY_B_LONG_PRESS_TIME,
  CHANGE_KEY_A_DOUBLE_PRESS_INTERVAL,
  CHANGE_KEY_B_DOUBLE_PRESS_INTERVAL
};

class I2C_BUTTON
{
  public:
	I2C_BUTTON(unsigned char address = DEFAULT_I2C_ADDRESS);
	unsigned char get(void);
	unsigned char reset(void);
	unsigned char changeAddress(unsigned char address);

	unsigned char BUTTON_A;
	unsigned char BUTTON_B;

  private:
	unsigned char _address;
	unsigned char send_data[2] = {0};
	unsigned char get_data[2]={0};
	unsigned char sendData(unsigned char *data, unsigned char len);
};

#endif
