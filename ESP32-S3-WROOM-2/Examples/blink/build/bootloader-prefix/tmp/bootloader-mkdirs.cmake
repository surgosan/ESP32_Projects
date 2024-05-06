# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v5.2.1/components/bootloader/subproject"
  "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader"
  "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix"
  "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix/tmp"
  "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix/src"
  "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/sergy/OneDrive/Documents/Arduino/ESP32/ESP32-S3-WROOM-2/Examples/blink/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
