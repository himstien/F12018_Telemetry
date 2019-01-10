#ifndef PACKETHEADER_H
#define PACKETHEADER_H

#include <cstdint>

class PacketHeader
{
public:
    uint16_t    m_packetFormat;         // 2018
    uint8_t     m_packetVersion;        // Version of this packet type, all start from 1
    uint8_t     m_packetId;             // Identifier for the packet type, see below
    uint64_t    m_sessionUID;           // Unique identifier for the session
    float     m_sessionTime;          // Session timestamp
    uint8_t      m_frameIdentifier;      // Identifier for the frame the data was retrieved on
    uint8_t     m_playerCarIndex;       // Index of player's car in the array

    int indexInput;

    void convertBytesToObject(char*, int);
    PacketHeader(char*, int);
    PacketHeader(){};
};

#endif
