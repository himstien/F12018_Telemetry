#include "PacketHeader.h"
#include "bytesToDataTypeHelper.h"

#include <iostream>


void PacketHeader::convertBytesToObject(char input[])
{
    std::cout << " Size of bytes received: ";
    std::cout << sizeof(input)/sizeof(char) << std::endl;

    m_packetFormat = bytesToUInt16(input[1], input[0]);
    m_packetVersion = int(input[2]);
    m_packetId = int(input[3]);
    m_sessionUID = bytesToUInt64(input[11], input[10], input[9], input[8], input[7], input[6], input[5], input[4]);
    m_sessionTime = bytesToFloat(input[15], input[14], input[13], input[12]);
    m_frameIdentifier = int(input[16]);
    m_playerCarIndex = int(input[17]);
}

PacketHeader::PacketHeader(char input[])
{
  std::cout << " Size of bytes received: ";
  std::cout << sizeof(input)/sizeof(char) << std::endl;

  m_packetFormat = bytesToUInt16(input[1], input[0]);
  m_packetVersion = int(input[2]);
  m_packetId = int(input[3]);
  m_sessionUID = bytesToUInt64(input[11], input[10], input[9], input[8], input[7], input[6], input[5], input[4]);
  m_sessionTime = bytesToFloat(input[15], input[14], input[13], input[12]);
  m_frameIdentifier = int(input[16]);
  m_playerCarIndex = int(input[17]);
}
