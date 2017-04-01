QT += core
QT -= gui

CONFIG += c++11

TARGET = JfzOpenCV_Mat
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH+= D:/Library/OpenCV2/build/include\
              D:/Library/OpenCV2/build/include/opencv\
              D:/Library/OpenCV2/build/include/opencv2

LIBS += D:\Library\OpenCV2\MinGW_build\lib\libopencv_core2413.dll.a\
        D:\Library\OpenCV2\MinGW_build\lib\libopencv_highgui2413.dll.a\
        D:\Library\OpenCV2\MinGW_build\lib\libopencv_imgproc2413.dll.a

