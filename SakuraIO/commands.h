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

// Common
#define CMD_GET_CONNECTION_STATUS 0x01
#define CMD_GET_SIGNAL_QUALITY    0x02
#define CMD_GET_DATETIME          0x03
#define CMD_ECHO_BACK             0x0f

// IO
#define CMD_READ_ADC  0x10

// Transmit
#define CMD_TX_ENQUEUE      0x20
#define CMD_TX_SENDIMMED    0x21
#define CMD_TX_LENGTH       0x22
#define CMD_TX_CLEAR        0x23
#define CMD_TX_SEND         0x24
#define CMD_TX_STAT         0x25

// Receive
#define CMD_RX_DEQUEUE      0x30
#define CMD_RX_PEEK         0x31
#define CMD_RX_LENGTH       0x32
#define CMD_RX_CLEAR        0x33

// File Download
#define CMD_START_FILE_DOWNLOAD       0x40
#define CMD_GET_FILE_METADATA         0x41
#define CMD_GET_FILE_DOWNLOAD_STATUS  0x42
#define CMD_CANCEL_FILE_DOWNLOAD      0x43
#define CMD_GET_FILE_DATA             0x44

// Operation
#define CMD_GET_PRODUCT_ID              0xA0
#define CMD_GET_UNIQUE_ID               0xA1
#define CMD_GET_FIRMWARE_VERSION        0xA2
#define CMD_UNLOCK                      0xA8
#define CMD_UPDATE_FIRMWARE             0xA9
#define CMD_GET_UPDATE_FIRMWARE_STATUS  0xAA
#define CMD_SOFTWARE_RESET              0xAF


// Response
#define CMD_ERROR_NONE             0x01
#define CMD_ERROR_PARITY           0x02
#define CMD_ERROR_MISSING          0x03
#define CMD_ERROR_INVALID_SYNTAX   0x04
#define CMD_ERROR_RUNTIME          0x05
#define CMD_ERROR_LOCKED           0x06
#define CMD_ERROR_BUSY             0x07


// FileStatus
#define FILE_STATUS_ERROR           0x01
#define FILE_STATUS_INVALID_REQUEST 0x02
#define FILE_STATUS_NOTFOUND        0x81
#define FILE_STATUS_SERVER_ERROR    0x82
#define FILE_STATUS_INVALID_DATA    0x83
