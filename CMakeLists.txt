cmake_minimum_required(VERSION 3.22)

project(simrace)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(races
	"races/Race.cpp"
	"races/GroundRace.cpp"
	"races/AirRace.cpp"
	"races/GroundAirRace.cpp")

set(vehicles
	"vehicles/Vehicle.cpp"
	"vehicles/GroundVehicle.cpp"
	"vehicles/AirVehicle.cpp"
	
	"vehicles/groundVehicles/Camel.cpp"
	"vehicles/groundVehicles/CamelFast.cpp"
	"vehicles/groundVehicles/Centaur.cpp"
	"vehicles/groundVehicles/BootsATV.cpp"

	"vehicles/airVehicles/MagicCarpet.cpp"
	"vehicles/airVehicles/Eagle.cpp"
	"vehicles/airVehicles/Broom.cpp")

add_library(simraceObjects SHARED ${races} ${vehicles})

add_executable(simrace main.cpp)

target_link_libraries(simrace PUBLIC simraceObjects)

target_include_directories(simrace PUBLIC races vehicles)
target_include_directories(simraceObjects PUBLIC races vehicles)
