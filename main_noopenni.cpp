#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/logger.h>
#include <iostream>

int main(int argc, char** argv)
{

    libfreenect2::Freenect2 freenect2;
    int devices = freenect2.enumerateDevices();
    bool opened = false;
    for (int i = 0; i < devices; i++)
    {
        libfreenect2::Freenect2Device* dev = freenect2.openDevice(i);
        if (dev)
        {
            dev->stop();
            dev->close();
            std::cout << "opened and closed device" << std::endl;
            opened = true;
        }
        else
        {
            std::cout << "Could not open device" << std::endl;
        }
    }

    while (opened)
    {
        usleep(1000 * 1000);
    }


    return 0;
}

