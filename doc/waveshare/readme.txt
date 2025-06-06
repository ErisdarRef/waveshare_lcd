@brief      Waveshare ESP32-S3 Touch-LCD
@details    prev
@auth       Justin Reina
@date       3/14/25


@section    Hardware

    16MB Flash + 8MB PSRAM

@section    Setup Instructions
    
    1. Get ESP-IDF [1]

        Standard Setup of Toolchain for Windows [3]
        
        @pre Python, Git, cross-compilers, CMake and Ninja build tools.
    
        Espressif-IDE v3.1.0 with ESP-IDF v5.3.1 - Offline Installer
        
    2. Get going! [2]
    
        To get started, please click on the ESP-IDF Manager below to configure ESP-IDF and its tools. 
        ESP-IDF Manager 
        
        Import hello_world to IDF & compile
        
        Install MicroSD & power-on USB-C to laptop
        
        //Configure Your Project
        idf.py set-target esp32
        idf.py menuconfig
        idf.py build
    
        //Setup WiFi
        ap: MCC Corp
        pswd: Metro2016
    
    3. Espressif IDE

@section    Reference

    1. https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started

    2. https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-4.3B#Demos_2

    3. https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/windows-setup.html
    
    4. https://github.com/espressif/esp-idf/tree/v5.2.4/examples/get-started/hello_world

@section    Opens Right Now

    Setup Espressif IDE
    
    Hello World Example [4]
    
        esp-idf-v5.3.1\examples\get-started\hello_world
        
        