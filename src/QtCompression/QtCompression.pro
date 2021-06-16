NAME         = QtCompression
TARGET       = $${NAME}
QT           = core
QT          -= gui
CONFIG(static,static|shared) {
# static version does not support Qt Script now
QT          -= script
} else {
QT          += script
}
QT          += QtTransformers
QT          += QtGZip
QT          += QtBZip2
QT          += QtLzo
QT          += QtLZ4
QT          += QtQuickLZ
QT          += QtUCL
QT          += QtXz
QT          += QtLZip

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/QtCompression

HEADERS     += $${PWD}/../../include/QtCompression/QtCompression
HEADERS     += $${PWD}/../../include/QtCompression/qtcompression.h

SOURCES     += $${PWD}/compression.cpp
SOURCES     += $${PWD}/filedetails.cpp

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)
