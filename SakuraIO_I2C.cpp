#include "mbed.h"
#include "SakuraIO.h"
#include "SakuraIO/debug.h"

#define SAKURAIO_SLAVE_ADDR 0x4F

#define MODE_IDLE  0x00
#define MODE_WRITE 0x01
#define MODE_READ  0x02

void SakuraIO_I2C::begin(){
  mode = MODE_IDLE;
}

void SakuraIO_I2C::end(){
  switch(mode){
    case MODE_WRITE:
      i2c.stop();
      break;
    case MODE_READ:
      i2c.read(true);
      break;
  }

  mode = MODE_IDLE;
}

void SakuraIO_I2C::sendByte(uint8_t data){
  if(mode != MODE_WRITE){
    dbgln("beginTr");
    i2c.start();
    i2c.write(SAKURAIO_SLAVE_ADDR<<1);
    mode = MODE_WRITE;
  }
  dbg("Write=");
  dbgln(data);
  i2c.write(data);
}


uint8_t SakuraIO_I2C::startReceive(uint8_t length){
  dbgln("endTransmission");
  i2c.stop();
  dbg("requestForm=");
  dbgln(length);
  i2c.start();
  i2c.write(SAKURAIO_SLAVE_ADDR<<1 | 1);
  mode = MODE_READ;
}

uint8_t SakuraIO_I2C::receiveByte(){
  return i2c.read(true);
}

uint8_t SakuraIO_I2C::receiveByte(bool stop){
  uint8_t ret = 0;
  ret = i2c.read(!stop);
  dbg("Read=");
  dbgln(ret);
  return ret;
}

SakuraIO_I2C::SakuraIO_I2C(I2C &_i2c): i2c(_i2c){
  mode = MODE_IDLE;
}
