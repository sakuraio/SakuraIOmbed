/* SAKURA Internet IoT Communication Module Library for mbed
 *
 * The MIT License (MIT)
 *
 * Copyright (c) SAKURA Internet Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

 #ifndef _SAKURAIO_H_
 #define _SAKURAIO_H_

 #include "mbed.h"
 #include <SakuraIO/commands.h>

 class SakuraIO
 {
 protected:
     virtual void begin() {}
     virtual void end() {}

     virtual void sendByte(uint8_t data) {}
     //virtual void finishSending(){}

     virtual uint8_t startReceive(uint8_t length) {
         return length;
     };
     virtual uint8_t receiveByte() {
         return 0x00;
     }
     virtual uint8_t receiveByte(bool stop) {
         return 0x00;
     }
     //virtual void finishReceiving(){}

     uint8_t executeCommand(uint8_t cmd,uint8_t requestLength, uint8_t *request, uint8_t *responseLength, uint8_t *response);

     uint8_t enqueueTxRaw(uint8_t ch, uint8_t type, uint8_t length, uint8_t *data, uint64_t offset);

 public:
     uint8_t getConnectionStatus();
     uint8_t getSignalQuarity(); // Deprecated
     uint8_t getSignalQuality();
     uint64_t getUnixtime();
     uint8_t echoback(uint8_t length, uint8_t *data, uint8_t *response);
     uint16_t getADC(uint8_t channel); // Deprecated
     uint8_t enqueueTx(uint8_t ch, int32_t value, uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, uint32_t value, uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, int64_t value, uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, uint64_t value, uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, float value, uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, double value, uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, uint8_t value[8], uint64_t offset);
     uint8_t enqueueTx(uint8_t ch, int32_t value);
     uint8_t enqueueTx(uint8_t ch, uint32_t value);
     uint8_t enqueueTx(uint8_t ch, int64_t value);
     uint8_t enqueueTx(uint8_t ch, uint64_t value);
     uint8_t enqueueTx(uint8_t ch, float value);
     uint8_t enqueueTx(uint8_t ch, double value);
     uint8_t enqueueTx(uint8_t ch, uint8_t value[8]);
     uint8_t sendImmediatelyRaw(uint8_t ch, uint8_t type, uint8_t length, uint8_t *data, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, int32_t value, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, uint32_t value, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, int64_t value, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, uint64_t value, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, float value, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, double value, uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, uint8_t value[8], uint64_t offset);
     uint8_t sendImmediately(uint8_t ch, int32_t value);
     uint8_t sendImmediately(uint8_t ch, uint32_t value);
     uint8_t sendImmediately(uint8_t ch, int64_t value);
     uint8_t sendImmediately(uint8_t ch, uint64_t value);
     uint8_t sendImmediately(uint8_t ch, float value);
     uint8_t sendImmediately(uint8_t ch, double value);
     uint8_t sendImmediately(uint8_t ch, uint8_t value[8]);
     uint8_t getTxQueueLength(uint8_t *available, uint8_t *queued);
     uint8_t clearTx();
     uint8_t getTxStatus(uint8_t *queue, uint8_t *immediate);
     uint8_t send();
     uint8_t dequeueRx(uint8_t *ch, uint8_t *type, uint8_t *value, int64_t *offset);
     uint8_t peekRx(uint8_t *ch, uint8_t *type, uint8_t *value, int64_t *offset);
     uint8_t getRxQueueLength(uint8_t *available, uint8_t *queued);
     uint8_t clearRx();
     uint8_t startFileDownload(uint16_t fileId);
     uint8_t cancelFileDownload();
     uint8_t getFileMetaData(uint8_t *status, uint32_t *totalSize, uint64_t *timestamp, uint32_t *crc);
     uint8_t getFileDownloadStatus(uint8_t *status, uint32_t *currentSize);
     uint8_t getFileData(uint8_t *size, uint8_t *data);
     uint16_t getProductID();
     uint8_t getUniqueID(char *data);
     uint8_t getFirmwareVersion(char *data);
     uint8_t unlock();
     uint8_t updateFirmware();
     uint8_t getFirmwareUpdateStatus();
     uint8_t reset();
 };

 class SakuraIO_SPI : public SakuraIO
 {
 protected:
     SPI &spi;
     DigitalOut &cs;
     virtual void begin();
     virtual void end();
     virtual void sendByte(uint8_t data);
     virtual uint8_t receiveByte(bool stop);
     virtual uint8_t receiveByte();
 public:
     SakuraIO_SPI(SPI &_spi, DigitalOut &_cs);
 };

 class SakuraIO_I2C : public SakuraIO
 {
 protected:
     I2C *i2c_p;
     I2C &i2c;
     int _length;

     virtual void begin();
     virtual void end();
     virtual void sendByte(uint8_t data);
     virtual uint8_t startReceive(uint8_t length);
     virtual uint8_t receiveByte(bool stop);
     virtual uint8_t receiveByte();
     uint8_t mode;
 public:
     SakuraIO_I2C (I2C &_i2c);
     SakuraIO_I2C (PinName sda, PinName scl);
 };

 #endif // _SAKURAIO_H_
