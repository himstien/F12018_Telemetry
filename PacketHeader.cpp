#include "PacketHeader.h"
#include "bytesToDataTypeHelper.h"

#include <iostream>


void PacketHeader::convertBytesToObject(char* input, int index)
{
    std::cout << " Size of bytes received: ";
    std::cout << sizeof(input)/sizeof(char) << std::endl;

    m_packetFormat = bytesToUInt16(input[index+1], input[index+0]);
    m_packetVersion = int(input[index+2]);
    m_packetId = int(input[index+3]);
    m_sessionUID = bytesToUInt64(input[index+11], input[index+10], input[index+9], input[index+8], input[index+7], input[index+6], input[index+5], input[index+4]);
    m_sessionTime = bytesToFloat(input[index+15], input[index+14], input[index+13], input[index+12]);
    m_frameIdentifier = int(input[index+16]);
    m_playerCarIndex = int(input[index+17]);
    indexInput = index+17;
}

PacketHeader::PacketHeader(char input[], int index)
{
  std::cout << " Size of bytes received: ";
  std::cout << sizeof(input)/sizeof(char) << std::endl;

  m_packetFormat = bytesToUInt16(input[index+1], input[index+0]);
  m_packetVersion = int(input[index+2]);
  m_packetId = int(input[index+3]);
  m_sessionUID = bytesToUInt64(input[index+11], input[index+10], input[index+9], input[index+8], input[index+7], input[index+6], input[index+5], input[index+4]);
  m_sessionTime = bytesToFloat(input[index+15], input[index+14], input[index+13], input[index+12]);
  m_frameIdentifier = int(input[index+16]);
  m_playerCarIndex = int(input[index+17]);

  indexInput = index+17;
}
