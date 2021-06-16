win32 {
qtcompressionhelp.input    = $${PWD}/QtCompression.qhp
qtcompressionhelp.output   = $${PWD}/${QMAKE_FILE_BASE}.qch
qtcompressionhelp.commands = qhelpgenerator.exe ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT}
QMAKE_EXTRA_COMPILERS     += qtcompressionhelp
}

OTHER_FILES               += $${PWD}/*.bat
OTHER_FILES               += $${PWD}/*.qhp
OTHER_FILES               += $${PWD}/*.html
OTHER_FILES               += $${PWD}/*.css
OTHER_FILES               += $${PWD}/images/*
OTHER_FILES               += $${PWD}/en/*
OTHER_FILES               += $${PWD}/cn/*
OTHER_FILES               += $${PWD}/tw/*
