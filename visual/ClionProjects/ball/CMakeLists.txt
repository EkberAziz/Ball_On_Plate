cmake_minimum_required(VERSION 3.6)
project(ball)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# Next line is not required, without it given path will be checked too.
#set(PostgreSQL_ROOT "C:\\Program Files\\PostgreSQL\\9.4")
#find_package(PostgreSQL REQUIRED)
# Now variables PostgreSQL_INCLUDE_DIRS, PostgreSQL_LIBRARIES, PostgreSQL_LIBRARY_DIRS are set. Just use them.

#include_directories (${PostgreSQL_INCLUDE_DIRS})
#link_directories(${PostgreSQL_LIBRARY_DIRS})


set(OPENTHREADS_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libOpenThreads.dll)
set(OSG_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosg.dll)
set(OSGDB_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgDB.dll)
set(OSGFX_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgFX.dll)
set(OSGGA_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgGA.dll)
set(OSGUTIL_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgUtil.dll)
set(OSGANIMATION_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgAnimation.dll)
set(OSGVIEWER_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgViewer.dll)
set(OSGSIM_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgSim.dll)
set(OSGPARTICLE_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgParticle.dll)
set(OSGSHADOW_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgShadow.dll)
set(OSGUI_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgUI.dll)
set(OSGTERRAIN_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgTerrain.dll)
set(OSGTEXT_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgText.dll)
set(OSGWIDGET_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgWidget.dll)
set(OSGPRESENTATION_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgPresentation.dll)
set(OSGMANIPULATOR_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgManipulator.dll)
set(OSGVOLUME_LIBRARY C:/Program\ Files\ \(x86\)/OpenSceneGraph/bin/libosgVolume.dll)

set(OPENTHREADS_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSG_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGDB_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGUTIL_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGVIEWER_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGGA_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGSIM_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGFX_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGPARTICLE_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGANIMATION_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGMANIPULATOR_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGSHADOW_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGTERRAIN_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGTEXT_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGUI_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGVOLUME_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGWIDGET_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)
set(OSGPRESENTATION_INCLUDE_DIR C:/Program\ Files\ \(x86\)/OpenSceneGraph/include)

macro(config_project PROJNAME LIBNAME)
    include_directories(${${LIBNAME}_INCLUDE_DIR})
    target_link_libraries(${PROJNAME} ${${LIBNAME}_LIBRARY})
endmacro()

add_executable(ball main.cpp)
config_project(ball OPENTHREADS)
config_project(ball OSG)
config_project(ball OSGDB)
config_project(ball OSGUTIL)
config_project(ball OSGVIEWER)
config_project(ball OSGGA)
config_project(ball OSGSIM)
config_project(ball OSGTEXT)
config_project(ball OSGFX)
config_project(ball OSGWIDGET)
config_project(ball OSGPRESENTATION)
config_project(ball OSGTERRAIN)
config_project(ball OSGSHADOW)
config_project(ball OSGMANIPULATOR)
config_project(ball OSGPARTICLE)
config_project(ball OSGVOLUME)
config_project(ball OSGANIMATION)
config_project(ball OSGUI)