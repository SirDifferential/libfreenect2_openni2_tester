WORKDIR=`pwd`

rm *.o
if [ -f ./a.out ]; then
    rm ./a.out
fi

clang++ -g -L$WORKDIR/OpenNI2_lib/ -lOpenNI2 main.cpp
install_name_tool -change libOpenNI2.dylib @executable_path/OpenNI2_lib/libOpenNI2.dylib a.out

install_name_tool -id @executable_path/OpenNI2_lib/OpenNI2/libfreenect2-openni2.0.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2-openni2.0.dylib
install_name_tool -id @executable_path/OpenNI2_lib/OpenNI2/libfreenect2-openni2.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2-openni2.dylib

install_name_tool -change /Users/Delicode1/libfreenect2/build/lib/libfreenect2.0.2.dylib @executable_path/OpenNI2_lib/OpenNI2/Drivers/libfreenect2.0.2.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2-openni2.dylib
install_name_tool -change /Users/Delicode1/libfreenect2/build/lib/libfreenect2.0.2.dylib @executable_path/OpenNI2_lib/OpenNI2/Drivers/libfreenect2.0.2.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2-openni2.0.dylib

install_name_tool -id @executable_path/OpenNI2_lib/OpenNI2/libfreenect2.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2.dylib
install_name_tool -id @executable_path/OpenNI2_lib/OpenNI2/libfreenect2.0.2.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2.0.2.dylib
install_name_tool -id @executable_path/OpenNI2_lib/OpenNI2/libfreenect2.0.2.0.dylib OpenNI2_lib/OpenNI2/Drivers/libfreenect2.0.2.0.dylib
