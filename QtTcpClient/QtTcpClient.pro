QT       += core gui network
# 添加一个文件注释0804
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += 'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/include/opencv2'
INCLUDEPATH += 'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/include'
INCLUDEPATH += 'C:/Program Files (x86)/Intel/openvino_2021.2.185/deployment_tools/inference_engine/include'
DEPENDPATH += 'C:/Program Files (x86)/Intel/openvino_2021.2.185/deployment_tools/inference_engine/include'
DEPENDPATH += 'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/include/opencv2'
DEPENDPATH += 'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/include'

win32:CONFIG(release, debug|release): LIBS += -L'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/lib/' \
    -lopencv_calib3d451 -lopencv_core451 -lopencv_dnn451 -lopencv_features2d451 -lopencv_flann451 -lopencv_gapi451 -lopencv_highgui451\
    -lopencv_imgcodecs451 -lopencv_imgproc451 -lopencv_ml451 -lopencv_objdetect451 -lopencv_photo451 -lopencv_stitching451\
    -lopencv_video451 -lopencv_videoio451
else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/lib/'\
    -lopencv_calib3d451d -lopencv_core451d -lopencv_dnn451d -lopencv_features2d451d -lopencv_flann451d -lopencv_gapi451d -lopencv_highgui451d\
    -lopencv_imgcodecs451d -lopencv_imgproc451d -lopencv_ml451d -lopencv_objdetect451d -lopencv_photo451d -lopencv_stitching451d\
    -lopencv_video451d -lopencv_videoio451d
else:unix: LIBS += -L'C:/Program Files (x86)/Intel/openvino_2021.2.185/opencv/lib/'\
    -lopencv_calib3d451 -lopencv_core451 -lopencv_dnn451 -lopencv_features2d451 -lopencv_flann451 -lopencv_gapi451 -lopencv_highgui451\
    -lopencv_imgcodecs451 -lopencv_imgproc451 -lopencv_ml451 -lopencv_objdetect451 -lopencv_photo451 -lopencv_stitching451\
    -lopencv_video451 -lopencv_videoio451


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
