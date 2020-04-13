project(arcanoid)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()


find_package(Qt5 COMPONENTS Quick Core Network Widgets Qml QuickControls2)
find_package(Qt5QuickCompiler)
find_package(Threads REQUIRED)
qtquick_compiler_add_resources(RESOURCES resources.qrc)

add_executable(${PROJECT_NAME} 
    main.cpp
    domain/game/game.cpp
    domain/entities/board/board.cpp
    domain/entities/board/qboard.cpp
    ${RESOURCES}
    )

target_include_directories(${PROJECT_NAME} PUBLIC   
    ${CMAKE_CURRENT_SOURCE_DIR}/
)    




target_link_libraries(${PROJECT_NAME} 
    Threads::Threads
    spdlog::spdlog
    Qt5::Widgets 
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickControls2
    )






