
project( extinguisher )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )
set( CMAKE_AUTOUIC ON )

find_package( Qt6 COMPONENTS Core REQUIRED )
find_package( Qt6 COMPONENTS Widgets REQUIRED )

set( SRC main.cpp )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../../include )

link_directories( ${CMAKE_CURRENT_BINARY_DIR}/../../lib )

add_executable( extinguisher ${SRC} )

target_link_libraries( extinguisher widgets Qt6::Widgets )
