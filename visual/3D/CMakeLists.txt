#[[
cmake_minimum_required(VERSION 3.6)
project(3D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(OPENTHREADS_LIBRARY /usr/local/lib64/libOpenThreads.so)
set(OSG_LIBRARY /usr/local/lib64/libosg.so)
set(OSGDB_LIBRARY /usr/local/lib64/libosgDB.so)
set(OSGFX_LIBRARY /usr/local/lib64/libosgFX.so)
set(OSGGA_LIBRARY /usr/local/lib64/libosgGA.so)
set(OSGUTIL_LIBRARY /usr/local/lib64/libosgUtil.so)
set(OSGANIMATION_LIBRARY /usr/local/lib64/libosgAnimation.so)
set(OSGVIEWER_LIBRARY /usr/local/lib64/libosgViewer.so)
set(OSGSIM_LIBRARY /usr/local/lib64/libosgSim.so)
set(OSGPARTICLE_LIBRARY /usr/local/lib64/libosgParticle.so)
set(OSGSHADOW_LIBRARY /usr/local/lib64/libosgShadow.so)
#set(OSGUI_LIBRARY /usr/local/lib64/libosgUI.so)
set(OSGTERRAIN_LIBRARY /usr/local/lib64/libosgTerrain.so)
set(OSGTEXT_LIBRARY /usr/local/lib64/libosgText.so)
set(OSGWIDGET_LIBRARY /usr/local/lib64/libosgWidget.so)
set(OSGPRESENTATION_LIBRARY /usr/local/lib64/libosgPresentation.so)
set(OSGMANIPULATOR_LIBRARY /usr/local/lib64/libosgManipulator.so)
set(OSGVOLUME_LIBRARY /usr/local/lib64/libosgVolume.so)

set(OPENTHREADS_INCLUDE_DIR /usr/local/include/include)
set(OSG_INCLUDE_DIR /usr/local/include)
set(OSGDB_INCLUDE_DIR /usr/local/include)
set(OSGUTIL_INCLUDE_DIR /usr/local/include)
set(OSGVIEWER_INCLUDE_DIR /usr/local/include)
set(OSGGA_INCLUDE_DIR /usr/local/include)
set(OSGSIM_INCLUDE_DIR /usr/local/include)
set(OSGFX_INCLUDE_DIR /usr/local/include)
set(OSGPARTICLE_INCLUDE_DIR /usr/local/include)
set(OSGANIMATION_INCLUDE_DIR /usr/local/include)
set(OSGMANIPULATOR_INCLUDE_DIR /usr/local/include)
set(OSGSHADOW_INCLUDE_DIR /usr/local/include)
set(OSGTERRAIN_INCLUDE_DIR /usr/local/include)
set(OSGTEXT_INCLUDE_DIR /usr/local/include)
set(OSGUI_INCLUDE_DIR /usr/local/include)
set(OSGVOLUME_INCLUDE_DIR /usr/local/include)
set(OSGWIDGET_INCLUDE_DIR /usr/local/include)
set(OSGPRESENTATION_INCLUDE_DIR /usr/local/include)

macro(config_project PROJNAME LIBNAME)
    include_directories(${${LIBNAME}_INCLUDE_DIR})
    target_link_libraries(${PROJNAME} ${${LIBNAME}_LIBRARY})
endmacro()

add_executable(3D main.cpp)
config_project(3D OPENTHREADS)
config_project(3D OSG)
config_project(3D OSGDB)
config_project(3D OSGUTIL)
config_project(3D OSGVIEWER)
config_project(3D OSGGA)
config_project(3D OSGSIM)
config_project(3D OSGTEXT)
config_project(3D OSGFX)
config_project(3D OSGWIDGET)
config_project(3D OSGPRESENTATION)
config_project(3D OSGTERRAIN)
config_project(3D OSGSHADOW)
config_project(3D OSGMANIPULATOR)
config_project(3D OSGPARTICLE)
config_project(3D OSGVOLUME)
config_project(3D OSGANIMATION)
config_project(3D OSGUI)
]]
cmake_minimum_required(VERSION 3.6)
project(3D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

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

add_executable(3D main.cpp rs232.h rs232.cpp)
config_project(3D OPENTHREADS)
config_project(3D OSG)
config_project(3D OSGDB)
config_project(3D OSGUTIL)
config_project(3D OSGVIEWER)
config_project(3D OSGGA)
config_project(3D OSGSIM)
config_project(3D OSGTEXT)
config_project(3D OSGFX)
config_project(3D OSGWIDGET)
config_project(3D OSGPRESENTATION)
config_project(3D OSGTERRAIN)
config_project(3D OSGSHADOW)
config_project(3D OSGMANIPULATOR)
config_project(3D OSGPARTICLE)
config_project(3D OSGVOLUME)
config_project(3D OSGANIMATION)
config_project(3D OSGUI)