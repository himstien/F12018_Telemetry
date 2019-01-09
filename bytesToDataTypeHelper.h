// convert bytes to datatypes

uint16 bytes_to_u16(MSB,LSB)
{
return (((unsigned int) ((unsigned char) MSB)) & 255)<<8 | (((unsigned char) LSB)&255);

}
