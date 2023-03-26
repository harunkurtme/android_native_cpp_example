# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.10.2)

project("myapplication").

add_library( # Sets the name of the library.
        myapplication
        SHARED
        native-lib.cpp
        )
add_library( # Sets the name of the library.
        serial_port
        SHARED
        SerialPortJNI.cpp
        ser.cpp
        )

find_library( # Sets the name of the path variable.
        log-lib

        log)

target_link_libraries( # Specifies the target library.
        myapplication
        ${log-lib})