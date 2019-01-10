
#include "bytesToDataTypeHelper.h"
#include "PacketHeader.h"
#include "CarTelemetryDataPacket.h"

#include <iostream>

CarTelemetryData::CarTelemetryData(char input[], int index)
{
    std::cout << "Size of car telemetry data: " ;
    std::cout << sizeof(input)/sizeof(char) << std::endl;

    m_speed = bytesToUInt16(input[index+1], input[index]);
    m_throttle = input[index+2];
    m_steer = input[index+3];
    m_brake = input[index+4];
    m_clutch = input[index+5];
    m_gear = input[index+6];

    m_engineRPM = bytesToUInt16(input[index+8], input[index+7]);
    m_drs = input[index+9];

    m_revLightsPercent = input[index+10];

    m_brakesTemperature[0] = bytesToUInt16(input[index+12], input[index+11]);
    m_brakesTemperature[1] = bytesToUInt16(input[index+14], input[index+13]);
    m_brakesTemperature[2] = bytesToUInt16(input[index+16], input[index+15]);
    m_brakesTemperature[3] = bytesToUInt16(input[index+18], input[index+17]);

    m_tyresSurfaceTemperature[0] = bytesToUInt16(input[index+20], input[index+19]);
    m_tyresSurfaceTemperature[1] = bytesToUInt16(input[index+22], input[index+21]);
    m_tyresSurfaceTemperature[2] = bytesToUInt16(input[index+24], input[index+23]);
    m_tyresSurfaceTemperature[3] = bytesToUInt16(input[index+26], input[index+25]);

    m_tyresInnerTemperature[0] = bytesToUInt16(input[index+28], input[index+27]);
    m_tyresInnerTemperature[1] = bytesToUInt16(input[index+30], input[index+29]);
    m_tyresInnerTemperature[2] = bytesToUInt16(input[index+32], input[index+31]);
    m_tyresInnerTemperature[3] = bytesToUInt16(input[index+34], input[index+33]);

    m_engineTemperature = bytesToUInt16(input[index+36], input[index+35]);

    m_tyresPressure[0] = bytesToFloat(input[index+40], input[index+39], input[index+38], input[index+37] );
    m_tyresPressure[1] = bytesToFloat(input[index+44], input[index+43], input[index+42], input[index+41] );
    m_tyresPressure[2] = bytesToFloat(input[index+48], input[index+47], input[index+46], input[index+45] );
    m_tyresPressure[3] = bytesToFloat(input[index+52], input[index+51], input[index+50], input[index+49] );

    indexInput = index+52;
}

CarTelemetryData CarTelemetryData::convertBytesToObject(char input[], int index)
{
    CarTelemetryData data;

    std::cout << "Size of car telemetry data: ";
    std::cout << sizeof(input)/sizeof(char) << std::endl;

    data.m_speed = bytesToUInt16(input[index+1], input[index]);
    data.m_throttle = input[index+2];
    data.m_steer = input[index+3];
    data.m_brake = input[index+4];
    data.m_clutch = input[index+5];
    data.m_gear = input[index+6];

    data.m_engineRPM = bytesToUInt16(input[index+8], input[index+7]);
    data.m_drs = input[index+9];

    data.m_revLightsPercent = input[index+10];

    data.m_brakesTemperature[0] = bytesToUInt16(input[index+12], input[index+11]);
    data.m_brakesTemperature[1] = bytesToUInt16(input[index+14], input[index+13]);
    data.m_brakesTemperature[2] = bytesToUInt16(input[index+16], input[index+15]);
    data.m_brakesTemperature[3] = bytesToUInt16(input[index+18], input[index+17]);

    data.m_tyresSurfaceTemperature[0] = bytesToUInt16(input[index+20], input[index+19]);
    data.m_tyresSurfaceTemperature[1] = bytesToUInt16(input[index+22], input[index+21]);
    data.m_tyresSurfaceTemperature[2] = bytesToUInt16(input[index+24], input[index+23]);
    data.m_tyresSurfaceTemperature[3] = bytesToUInt16(input[index+26], input[index+25]);

    data.m_tyresInnerTemperature[0] = bytesToUInt16(input[index+28], input[index+27]);
    data.m_tyresInnerTemperature[1] = bytesToUInt16(input[index+30], input[index+29]);
    data.m_tyresInnerTemperature[2] = bytesToUInt16(input[index+32], input[index+31]);
    data.m_tyresInnerTemperature[3] = bytesToUInt16(input[index+34], input[index+33]);

    m_engineTemperature = bytesToUInt16(input[index+36], input[index+35]);

    m_tyresPressure[0] = bytesToFloat(input[index+40], input[index+39], input[index+38], input[index+37] );
    m_tyresPressure[1] = bytesToFloat(input[index+44], input[index+43], input[index+42], input[index+41] );
    m_tyresPressure[2] = bytesToFloat(input[index+48], input[index+47], input[index+46], input[index+45] );
    m_tyresPressure[3] = bytesToFloat(input[index+52], input[index+51], input[index+50], input[index+49] );

    indexInput = index+52;
    return data;
}


PacketCarTelemetryData::PacketCarTelemetryData(char* input, int index)
{
    PacketHeader m_header = PacketHeader(input, index);                // Header

    for (int i=0; i < 20; i++)
    {
        m_carTelemetryData[i] = CarTelemetryData(input, indexInput);
    }


    m_buttonStatus = bytesToUInt32(input[indexInput+3], input[indexInput+2], input[indexInput+1], input[indexInput]);         // Bit flags specifying which buttons are being
                                                // pressed currently - see appendices
    indexInput = indexInput+4;

}

PacketCarTelemetryData PacketCarTelemetryData::convertBytesToObject(char input[], int index)
{
    PacketCarTelemetryData data;

    data.m_header = PacketHeader(input, index);                // Header

    for (int i=0; i < 20; i++)
    {
        data.m_carTelemetryData[i] = CarTelemetryData(input, indexInput);
    }


    data.m_buttonStatus = bytesToUInt32(input[indexInput+3], input[indexInput+2], input[indexInput+1], input[indexInput]);         // Bit flags specifying which buttons are being
                                                // pressed currently - see appendices
    data.indexInput = indexInput+4;

}
