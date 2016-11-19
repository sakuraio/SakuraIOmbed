#include "mbed.h"
#include "SakuraIO.h"
#include "SakuraIO/debug.h"


void SakuraIO_SPI::begin(){
  dbgln("CS=0");
  cs = 0;
}

void SakuraIO_SPI::end(){
  dbgln("CS=1");
  cs = 1;
  wait_us(20);
}

void SakuraIO_SPI::sendByte(uint8_t data){
  wait_us(20);
  dbg("Send=");
  dbgln(data);
  wait_us(10);
  spi.write(data);
}


uint8_t SakuraIO_SPI::receiveByte(bool stop){
  return receiveByte();
}

uint8_t SakuraIO_SPI::receiveByte(){
  uint8_t ret;
  wait_us(10);
  ret = spi.write(0x00);
  dbg("Recv=");
  dbgln(ret);
  return ret;
}

SakuraIO_SPI::SakuraIO_SPI(SPI &_spi, DigitalOut &_cs): spi(_spi), cs(_cs){
    cs = 1;
}
