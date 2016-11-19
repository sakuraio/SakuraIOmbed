#include "mbed.h"
#include "SakuraIO.h"
#include "debug.h"
 
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
      while (_length > 0) {
        _length --;
        i2c.read(_length > 0 ? 1 : 0);
      }
      i2c.stop();
      break;
  }
 
  mode = MODE_IDLE;
}
 
void SakuraIO_I2C::sendByte(uint8_t data){
  if(mode != MODE_WRITE){
    dbg("beginTr\r\n");
    i2c.start();
    i2c.write(SAKURAIO_SLAVE_ADDR<<1);
    mode = MODE_WRITE;
  }
  dbg("Write=%02x\r\n", data);
  i2c.write(data);
}
 
 
uint8_t SakuraIO_I2C::startReceive(uint8_t length){
  if(mode != MODE_IDLE){
    dbg("endTransmission\r\n");
    i2c.stop();
  }
  dbg("requestForm=%d\r\n", length);
  _length = length;
  i2c.start();
  i2c.write(SAKURAIO_SLAVE_ADDR<<1 | 1);
  mode = MODE_READ;
  return 0;
}
 
uint8_t SakuraIO_I2C::receiveByte(){
  return receiveByte(false);
}
 
uint8_t SakuraIO_I2C::receiveByte(bool stop){
  uint8_t ret = 0;
  if (_length > 0) {
    _length --;
    ret = i2c.read(_length > 0 ? 1 : 0);
  }
  if(stop){
    end();
  }
  dbg("Read=%d\r\n", ret);
  return ret;
}
 
SakuraIO_I2C::SakuraIO_I2C (I2C &_i2c) : i2c(_i2c) {
  mode = MODE_IDLE;
}
 
SakuraIO_I2C::SakuraIO_I2C (PinName sda, PinName scl) : i2c(sda, scl) {
  mode = MODE_IDLE;
}