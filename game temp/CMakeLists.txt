cmake_minimum_required(VERSION 3.30)
project(car_game)

set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "-static")

add_executable(car_game main.cpp
        core/Game.cpp
        core/Game.h
        enums/TileTypes.h
        entities/Car.cpp
        entities/Car.h
        entities/Tile.cpp
        entities/Tile.h
        world/Map.cpp
        world/Map.h
        ui/Renderer.cpp
        ui/Renderer.h
        ui/Hud.cpp
        ui/Hud.h
        ui/MapRenderer.cpp
        ui/MapRenderer.h
        ui/CarRenderer.cpp
        ui/CarRenderer.h
        ui/HUD.cpp
        ui/HUD.h
        world/LapTimer.cpp
        world/LapTimer.h
        ui/SpeedoMeter.cpp
        ui/SpeedoMeter.h
        core/Controller.cpp
        core/Controller.h
        core/CarController.cpp
        core/CarController.h
        core/CollisionManager.cpp
        core/CollisionManager.h
        enums/TurnTypes.h
        world/MapLoader.cpp
        world/MapLoader.h)


include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.0)
FETCHCONTENT_MAKEAVAILABLE(SFML)

target_link_libraries(car_game
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)

target_include_directories(car_game PRIVATE
        ${sfml_SOURCE_DIR}/include
)