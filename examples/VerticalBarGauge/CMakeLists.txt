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

add_executable(VerticalBarGauge-example
        main.cpp
        verticalbargauge.ui
        verticalbargauge.h
        verticalbargauge.cpp
        )

target_link_libraries(VerticalBarGauge-example
        PRIVATE
        Qt${QT_VERSION}::Core
        Qt${QT_VERSION}::Gui
        Qt${QT_VERSION}::Widgets
        QcGaugeWidget
        )
