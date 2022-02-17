set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set the QT version
set(QT_VERSION 5)

find_package(Qt${QT_VERSION} REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )

add_executable(Compass-example
        main.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        )

target_link_libraries(Compass-example
        PRIVATE
        Qt${QT_VERSION}::Core
        Qt${QT_VERSION}::Gui
        Qt${QT_VERSION}::Widgets
        QcGaugeWidget
        )
