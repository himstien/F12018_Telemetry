// convert bytes to datatypes
#include <cstdint>
#include <string.h>

uint16_t bytesToUInt16(char byte1, char byte0)
{
    uint16_t uint16Value;
    uint16Value = (((unsigned char) byte0)&255);
    uint16Value = (((unsigned char) byte1)&255) << 8 | uint16Value;

    return uint16Value;
}


uint64_t bytesToUInt64(char byte7, char byte6, char byte5, char byte4, char byte3, char byte2, char byte1, char byte0)
{
    uint64_t uint64Value;
    uint64Value = (((unsigned char) byte0)&255);
    uint64Value = (((unsigned char) byte1)&255)<<8 | uint64Value;
    uint64Value = (((unsigned char) byte2)&255)<<16 | uint64Value;
    uint64Value = (((unsigned char) byte3)&255)<<24 | uint64Value;
    uint64Value = (((unsigned char) byte4)&255)<<32 | uint64Value;
    uint64Value = (((unsigned char) byte5)&255)<<40 | uint64Value;
    uint64Value = (((unsigned char) byte6)&255)<<48 | uint64Value;
    uint64Value = (((unsigned char) byte7)&255)<<56 | uint64Value;


    return uint64Value;
}


float bytesToFloat(char byte3, char byte2, char byte1, char byte0)
{
    unsigned long int intValue;
    intValue = (((unsigned char) byte0)&255);
    intValue = (((unsigned char) byte1)&255)<<8 | intValue;
    intValue = (((unsigned char) byte2)&255)<<16 | intValue;
    intValue = (((unsigned char) byte3)&255)<<24 | intValue;


    float val;

    memcpy(&val,&intValue,4);

    return val;
}
