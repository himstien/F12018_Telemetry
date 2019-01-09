#include "PacketHeader.h"
#include "bytesToDataTypeHelper.h"

class PacketHeader
{
public:
    uint16    m_packetFormat;         // 2018
    uint8     m_packetVersion;        // Version of this packet type, all start from 1
    uint8     m_packetId;             // Identifier for the packet type, see below
    uint64    m_sessionUID;           // Unique identifier for the session
    float     m_sessionTime;          // Session timestamp
    uint      m_frameIdentifier;      // Identifier for the frame the data was retrieved on
    uint8     m_playerCarIndex;       // Index of player's car in the array
};

PacketHeader::convertBytesToObject(byte input[])
{
    cout << " Size of bytes received: ";
    cout << sizeof(byte)/sizeof(char);

    m_packetFormat = bytesToUInt16(input[1], input[0]);
    m_packetVersion = int(input[2]);
    m_packetId = int(input[3]);
    m_sessionUID = bytesToUInt64(input[7], input[6], input[5], input[4]);
    m_sessionTime = bytesToFloat(input[11], input[10], input[9], input[8]);
    m_frameIdentifier = uint(input[12]);
    m_playerCarIndex = uint8(input[13]);
};

PacketHeader::PacketHeader(byte input[])
{
  cout << " Size of bytes received: ";
  cout << sizeof(byte)/sizeof(char);

  m_packetFormat = bytesToUInt16(input[1], input[0]);
  m_packetVersion = int(input[2]);
  m_packetId = int(input[3]);
  m_sessionUID = bytesToUInt64(input[7], input[6], input[5], input[4]);
  m_sessionTime = bytesToFloat(input[11], input[10], input[9], input[8]);
  m_frameIdentifier = uint(input[12]);
  m_playerCarIndex = uint8(input[13]);

}
