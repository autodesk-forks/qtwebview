TARGET = QtWebView

QT += quick qml

load(qt_module)

ANDROID_BUNDLED_JAR_DEPENDENCIES = \
    jar/QtAndroidWebView-bundled.jar
ANDROID_JAR_DEPENDENCIES = \
    jar/QtAndroidWebView.jar

HEADERS += \
    qwebview_p.h \

android {
    QT += androidextras
    LIBS += -ljnigraphics
    SOURCES += \
        qwebview_android.cpp \
        qwebview.cpp \
        qwindowcontrolleritem.cpp
    HEADERS += \
        qwebview_android_p.h \
        qwindowcontrolleritem_p.h

} else {
    qtHaveModule(webengine) {
        QT += webengine webengine-private
        DEFINES += QT_WEBVIEW_WEBENGINE_BACKEND
    } else {
        SOURCES += \
            qwebview_default.cpp \
            qwebview.cpp \
            qwindowcontrolleritem.cpp
        HEADERS += \
            qwebview_default_p.h \
            qwindowcontrolleritem_p.h
    }
}
