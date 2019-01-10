#ifndef BYTESTODATA_H
#define BYTESTODATA_H

#include <cstdint>

uint16_t bytesToUInt16(char byte1, char byte0);

uint32_t bytesToUInt32(char byte3, char byte2, char byte1, char byte0);

uint64_t bytesToUInt64(char byte7, char byte6, char byte5, char byte4, char byte3, char byte2, char byte1, char byte0);

float bytesToFloat(char byte3, char byte2, char byte1, char byte0);

#endif
