#include "OpenNI2_headers/OpenNI.h"
#include "OpenNI2_headers/OniCEnums.h"
#include <iostream>

#define CHECK_STATUS_RETURN(func, desc) if((rc = func) != openni::STATUS_OK) { std::cout << "Error with " << desc << ": " << openni::OpenNI::getExtendedError() << "." << std::endl; return false;}

int main(int argc, char** argv)
{
    openni::Status rc;

    CHECK_STATUS_RETURN(openni::OpenNI::initialize(), "Error initializing OpenNI, quitting input!");
    openni::Array<openni::DeviceInfo> deviceList;
    openni::OpenNI::enumerateDevices(&deviceList);
    std::cout << "enumerate found " << deviceList.getSize() << " devices" << std::endl;

    openni::Device sensorDevice;
    bool device_open = false;

    for (int i = 0; i < deviceList.getSize(); i++)
    {
        openni::DeviceInfo info = deviceList[i];

        std::string uri = info.getUri();

        if (sensorDevice.open(info.getUri()) != openni::STATUS_OK)
        {
            std::cout << "Could not open device " << info.getUri() << std::endl;
            continue;
        }
	else
	{
            std::cout << "A device was opened successfully" << std::endl;
	}

        device_open = true;

        sensorDevice.close();
    }

    while (device_open)
    {
        usleep(1000 * 1000);
    }

    return 0;
}

