CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

CMAKE_POLICY(SET CMP0020 NEW)

FILE(GLOB ${PROJ_NAME}_SRCS *.cpp)
FILE(GLOB ${PROJ_NAME}_HDRS *.h)
FILE(GLOB ${PROJ_NAME}_FORMS *.ui)


SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
FIND_PACKAGE(Qt5Widgets REQUIRED)
QT5_WRAP_UI(${PROJ_NAME}_UIHDRS ${${PROJ_NAME}_FORMS})

SET(Boost_USE_STATIC_LIBS        ON)
SET(Boost_USE_MULTITHREADED      ON)
SET(Boost_USE_STATIC_RUNTIME    OFF)
FIND_PACKAGE(Boost)

IF (Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
ENDIF ()

SET(default_project_path "${CMAKE_SOURCE_DIR}/..")
GET_FILENAME_COMPONENT(${default_project_path} ${default_project_path} REALPATH)

SET(project_path "${default_project_path}" CACHE PATH "path to the other mo projects")
SET(lib_path "${project_path}/../../install/libs")

INCLUDE_DIRECTORIES(${project_path}/uibase/src
                    ${project_path}/game_features/src
                    ${project_path}/game_gamebryo/src)
LINK_DIRECTORIES(${project_path}/uibase/build/src
                 ${lib_path})


ADD_LIBRARY(${PROJ_NAME} SHARED ${${PROJ_NAME}_HDRS} ${${PROJ_NAME}_SRCS} ${${PROJ_NAME}_UIHDRS})
TARGET_LINK_LIBRARIES(${PROJ_NAME}
                      Qt5::Widgets
                      ${Boost_LIBRARIES}
                      uibase
                      gameGamebryo)

SET_TARGET_PROPERTIES(${PROJ_NAME} PROPERTIES COMPILE_FLAGS /GL)
SET_TARGET_PROPERTIES(${PROJ_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/LTCG /LARGEADDRESSAWARE /OPT:REF /OPT:ICF")

QT5_USE_MODULES(${PROJ_NAME} Widgets)

###############
## Installation

INSTALL(TARGETS ${PROJ_NAME}
        RUNTIME DESTINATION bin/plugins)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJ_NAME}.pdb DESTINATION pdb)
