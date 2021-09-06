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

add_executable(RollGauge-example
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        )

target_link_libraries(RollGauge-example
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        QcGaugeWidget
        )
