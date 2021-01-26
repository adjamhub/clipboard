# CMake things ------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(FeatureSummary)


# Project things ----------------------------------------------------------
project(clipboard VERSION "0.0.0" LANGUAGES CXX)

configure_file(config.h.in config.h)
include_directories(${PROJECT_BINARY_BIN})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Qt things ---------------------------------------------------------------
set(QT_MINIMUM_VERSION "5.14.0")

find_package(Qt5 "${QT_MINIMUM_VERSION}" COMPONENTS REQUIRED
    Core
    Gui
    Widgets
)


# Compile && Link ---------------------------------------------------------
add_executable(clipboard
    src/main.cpp
    src/clipboardtray.cpp
    src/clipboardmanager.cpp
    src/settingsdialog.cpp
)

target_link_libraries(clipboard PRIVATE 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)


# INSTALL ----------------------------------------------------------------
install(TARGETS clipboard RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

install(FILES data/clipboard.desktop   DESTINATION "${CMAKE_INSTALL_PREFIX}/share/applications")
install(FILES LICENSE                  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/adjam/clipboard")


# --------------------------------------------------------------------------
feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
