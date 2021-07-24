set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )

add_executable(SpeedGauge-example
        main.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        )

target_link_libraries(SpeedGauge-example
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        QcGaugeWidget
        )
