cmake_minimum_required(VERSION 3.14)
### 修改编译模式时，需要清除缓存防止包含旧的lib库

## 设置项目名称
set(PROJECT_NAME QTWidgetAndLib)
## 设置项目版本号
set(PROJECT_VERSION 0.1)

##  判断是否为debug模式
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug Mode")

    ### 自定义安装路径
    set(CMAKE_INSTALL_PREFIX "D:/test_dll/QTWidgetAndLib/out/install/Debug/")
    set(DEBUG_MODE ON)
else()
    message(STATUS "Release Mode")

    ### 自定义安装路径
    set(CMAKE_INSTALL_PREFIX "D:/test_dll/QTWidgetAndLib/out/install/Release/")
    set(DEBUG_MODE OFF)
endif()

############################### 参数设置区 #################################
### 工程源文件设置 ### 
set(PROJECT_SOURCES
    main.cpp
    QTWidgetAndLib.cpp
    QTWidgetAndLib.h
    QTWidgetAndLib.ui
    QTWidgetAndLib.qrc
)
############################### QT 设置区 #####################################
##### QT 版本 5
set(QT_VERSION_5 true)

#### QT 版本 6
set(QT_VERSION_6 false)

#### QT 核心模块
set(THIS_QT_CORE Core Widgets Network Gui Svg)

#### QT5 核心库
if(QT_VERSION_5)
    set(THIS_QT_CORE_LIB Qt5::Core Qt5::Widgets Qt5::Network Qt5::Gui Qt5::Svg)
endif()

#### QT6 核心库
if(QT_VERSION_6)
    set(THIS_QT_CORE_LIB Qt6::Core)
endif()
### 用于参数设置，根据自己的工程情况进行修改 ###
if(WIN32)
    ### windows 环境下 exe 输出路径设置 ###
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/build")
    ### 三方库 头文件的 输出路径设置 ###
    set(CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include")

    ### QT 的安装路径设置 ###
    set(QT_INSTALL_DIR "D:/Soft/QT/5.14.2/msvc2017_64/")
    ### 动态库的输出路径设置 ###

    ### 创建输出目录 ###
    make_directory(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    make_directory(${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY})

else(UNIX)
    ### linux 环境下 exe 输出路径设置 ###
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out/build")
    ### 三方库 头文件的 输出路径设置 ###
    set(CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include")
    
    ### QT 的安装路径设置 ###
    set(QT_INSTALL_DIR "xxxxx")
    ### 创建输出目录 ###
    make_directory(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    make_directory(${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY})
endif()

### 设置是从外部目录导入还是从运行目录导入###
# 默认从运行目录导入#
set(SET_LINK_INCLUE_DIR_THIS ON)


######################## 添加动态库 按照模板添加即可 #######################
###############################模板 - 动态库################################

#### 设置局部变量 用于存储 动态库的路径####
#### 编译环境分为 window 与 linux 请根据自己的环境设置 ####

############################# windows 环境 #########################################
#### 动态库路径设置 dll \ lib####

#### DYNAMIC_LIB_DIR 是动态库 LIB 的路径 ####
#### 这里只需要将动态库文件路径加入即可 ####

if(DEBUG_MODE)
    set(WIN32_DYNAMIC_LIB_DIR
        "D:/Soft/AtamiLib/CommunicationModule/Lib/Debug/"
        "D:/Soft/opencv/Debug/"
        )
    #### 动态库 DLL 的路径 ####
    #### 若存储路径和LIB 路径不同 请设置 ####
    set(WIN32_DYNAMIC_DLL_DIR 
       #"D:/Soft/opencv/build/x64/vc16/bin/"
        )
    #### 动态库头文件 h 路径设置 ####
    #### 这里只需要将动态库 头文件 路径加入即可 ####
    set(WIN32_DYNAMIC_INCLUDE_DIR 
        "D:/Soft/AtamiLib/CommunicationModule/include/"
        "D:/Soft/opencv/build/include/"
        )
else()

    set(WIN32_DYNAMIC_LIB_DIR
        "D:/Soft/AtamiLib/CommunicationModule/Lib/Release/"
        "D:/Soft/opencv/Release/"
        )
    #### 动态库 DLL 的路径 ####
    #### 若存储路径和LIB 路径不同 请设置 ####
    set(WIN32_DYNAMIC_DLL_DIR 
        #"/home/Test11/lib/"
    )
    #### 动态库头文件 h 路径设置 ####
    #### 这里只需要将动态库 头文件 路径加入即可 ####
    set(WIN32_DYNAMIC_INCLUDE_DIR 
        "D:/Soft/AtamiLib/CommunicationModule/include/"
        "D:/Soft/opencv/build/include/"
    )
endif()






################################# linux 环境 ###############################
#### 动态库路径设置so ####
if(DEBUG_MODE)
    set(LINUX_DYNAMIC_SO_DIR
        "/home/user01/CommunicationModule/Lib/Debug/"
        )
        #### 动态库头文件 h 路径设置 ####
        #### 这里只需要将动态库 头文件 路径加入即可 ####
    set(LINUX_DYNAMIC_INCLUDE_DIR 
    "/home/user01/CommunicationModule/Include/"
        )

else()
    set(LINUX_DYNAMIC_SO_DIR
        "/home/user01/CommunicationModule/Lib/Release/"
        )
        #### 动态库头文件 h 路径设置 ####
        #### 这里只需要将动态库 头文件 路径加入即可 ####
     set(LINUX_DYNAMIC_INCLUDE_DIR 
         "/home/user01/CommunicationModule/Include/"
        )
endif()



######################## 参数检查 ###################

#### 检查文件路径是否存在 ####
if(WIN32)
    foreach(var IN ITEMS ${WIN32_DYNAMIC_LIB_DIR} ${WIN32_DYNAMIC_DLL_DIR} ${WIN32_DYNAMIC_INCLUDE_DIR})
        if(NOT EXISTS ${var})
            message(FATAL_ERROR "${var} 不存在，请检查路径是否正确")
        endif()
    endforeach()
else()
    foreach(var IN ITEMS ${LINUX_DYNAMIC_SO_DIR} ${LINUX_DYNAMIC_INCLUDE_DIR})
        if(NOT EXISTS ${var})
            message(FATAL_ERROR "${var} 不存在，请检查路径是否正确")
        endif()
    endforeach()
endif()

################################################## 功能区 ##################################
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## 设置 工程名称与版本号
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)
############################################### 文件拷贝设置 ###########################################

### 拷贝动态库到运行目录 ###
if(WIN32)
    ### 拷贝动态库到运行目录/bin  hmy 内容修正###  
    foreach(var IN ITEMS ${WIN32_DYNAMIC_LIB_DIR} ${WIN32_DYNAMIC_DLL_DIR})
        file(COPY ${var} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)
    endforeach()
else(UNIX)
    ### 拷贝动态库到运行目录/lib 
    foreach(var IN ITEMS ${LINUX_DYNAMIC_SO_DIR})
        file(COPY ${var} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)
    endforeach()
endif()
### 拷贝动态库头文件到运行目录 ###
if(WIN32)
    foreach(var IN ITEMS ${WIN32_DYNAMIC_INCLUDE_DIR})
        file(COPY ${var} DESTINATION ${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY})
    endforeach()
else(UNIX)
    foreach(var IN ITEMS ${LINUX_DYNAMIC_INCLUDE_DIR})
    message(STATUS "CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY}")
    message(STATUS "LINUX_DYNAMIC_INCLUDE_DIR: ${LINUX_DYNAMIC_INCLUDE_DIR}")
        file(COPY ${var} DESTINATION ${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY})
    endforeach()
endif()

if(WIN32)
    foreach(var IN ITEMS ${WIN32_DYNAMIC_LIB_DIR})
        ### 查询动态库文件 ###
        file(COPY ${var} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()
else(LINUX)
    foreach(var IN ITEMS ${LINUX_DYNAMIC_SO_DIR})
        ### 查询动态库文件 ###
        file(COPY ${var} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()
endif()

##################################### 动态库头文件路径 #####################################
if(WIN32)
    ### 动态库头文件路径设置 ###
    if(SET_LINK_INCLUE_DIR_THIS)
        ### 从拷贝的头文件路径中设置 即运行目录的头文件路径 ###
        include_directories(${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY})
    else()
        ### 从外部目录设置 即外部库的头文件路径 ###
        foreach(var IN ITEMS ${WIN32_DYNAMIC_INCLUDE_DIR})
            include_directories(${var})
        endforeach()
    endif()
else(LINUX)
    if(SET_LINK_INCLUE_DIR_THIS)
        ### 从拷贝的头文件路径中设置 即运行目录的头文件路径 ###
        include_directories(${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY})
    else()
        ### 从外部目录设置 即外部库的头文件路径 ###
        foreach(var IN ITEMS ${LINUX_DYNAMIC_INCLUDE_DIR})
            include_directories(${var})
        endforeach()
    endif()
endif()


##################################### 动态库路径设置 #####################################
if(WIN32)
    if(SET_LINK_INCLUE_DIR_THIS)
        ### 从拷贝的动态库路径中设置 即运行目录的动态库路径 ###
        file(GLOB_RECURSE WIN32_DYNAMIC_LIB_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} "**/*.lib")
        ### 动态库文件加入链接目录 ###
        link_directories(${WIN32_DYNAMIC_LIB_FILES})
    else()
        ### 从外部目录设置 即外部库的动态库路径 ###
        foreach(var IN ITEMS ${WIN32_DYNAMIC_LIB_DIR})
            ### 查询动态库文件 ###
            file(GLOB_RECURSE WIN32_DYNAMIC_LIB_FILES ${var} "**/*.lib")
             ### 动态库文件加入链接目录 ###
            link_directories(${WIN32_DYNAMIC_LIB_FILES})
             ### 调试信息 ###
            message(STATUS "WIN32_DYNAMIC_LIB_FILES: ${WIN32_DYNAMIC_LIB_FILES}")
        endforeach()
    endif()
else(LINUX)
    if(SET_LINK_INCLUE_DIR_THIS)
        ### 从拷贝的动态库路径中设置 即运行目录的动态库路径 ###
        file(GLOB_RECURSE LINUX_DYNAMIC_SO_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} "**/*.so")
        ### 动态库文件加入链接目录 ###
        link_directories(${LINUX_DYNAMIC_SO_FILES})
    else()
        ### 从外部目录设置 即外部库的动态库路径 ###
        foreach(var IN ITEMS ${LINUX_DYNAMIC_SO_DIR})
            ### 查询动态库文件 ###
            file(GLOB_RECURSE LINUX_DYNAMIC_SO_FILES ${var} "**/*.so")
            ### 动态库文件加入链接目录 ###
            link_directories(${LINUX_DYNAMIC_SO_FILES})
            ### 调试信息 ###
            message(STATUS "LINUX_DYNAMIC_SO_FILES: ${LINUX_DYNAMIC_SO_FILES}")
        endforeach()
    endif()
endif()


################################ QT设置 ################################
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${THIS_QT_CORE})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${THIS_QT_CORE})



############################### 使用QT生成可执行文件 #########################
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(
        ${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
endif()


######################## 链接库设置 ######################
if(WIN32)
    target_link_libraries(QTWidgetAndLib PRIVATE 
                        ${THIS_QT_CORE_LIB}
                        ${WIN32_DYNAMIC_LIB_FILES}
                        )
else(UNIX)
    target_link_libraries(QTWidgetAndLib PRIVATE 
                        ${THIS_QT_CORE_LIB}
                        ${LINUX_DYNAMIC_SO_FILES}
                        )
endif()


######################### 其他设置 ###############
# 根据QT版本设置MACOSX_BUNDLE_GUI_IDENTIFIER选项
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTWidgetAndLib)
endif()

# 设置QTWidgetAndLib目标的属性
set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 如果QT主版本为6，则调用qt_finalize_executable函数
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTWidgetAndLib)
endif()
########################################### 安装设置 ###################################

### 设置安装路径 ###
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)
if(WIN32)
    if(DEBUG_MODE)
        # 安装 .lib 和 .dll 文件
        install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
            DESTINATION lib
            FILES_MATCHING PATTERN "*.lib"
        )
        install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
            DESTINATION bin
            FILES_MATCHING PATTERN "*.dll"
        )

        # 安装 Qt 库
        foreach(var IN ITEMS ${THIS_QT_CORE})
            install(DIRECTORY ${QT_INSTALL_DIR}/bin/
                DESTINATION bin
                FILES_MATCHING PATTERN "Qt5${var}d.dll"
            )
        endforeach()


        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/iconengines
            DESTINATION bin
            FILES_MATCHING PATTERN "*"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/imageformats
            DESTINATION bin
            FILES_MATCHING PATTERN "*"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/platforms
            DESTINATION bin
            FILES_MATCHING PATTERN "qwindowsd.dll"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/styles
            DESTINATION bin
            FILES_MATCHING PATTERN "qwindowsvistastyled.dll"
        )

    else()
        # 安装 .lib 和 .dll 文件
        install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
            DESTINATION lib
            FILES_MATCHING PATTERN "*.lib"
        )
        install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
            DESTINATION bin
            FILES_MATCHING PATTERN "qwindowsvistastyled.dll"
        )

         # 安装 Qt 库
        foreach(var IN ITEMS ${THIS_QT_CORE})
            install(DIRECTORY ${QT_INSTALL_DIR}/bin/
                DESTINATION bin
                FILES_MATCHING PATTERN "Qt5${var}.dll"
            )
        endforeach()

       

        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/iconengines
            DESTINATION bin
            FILES_MATCHING PATTERN "*"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/imageformats
            DESTINATION bin
            FILES_MATCHING PATTERN "*"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/platforms
            DESTINATION bin
            FILES_MATCHING PATTERN "qwindows.dll"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/styles
            DESTINATION bin
            FILES_MATCHING PATTERN "qwindowsvistastyle.dll"
        )
    endif()
endif()

if(UNIX)
    if(DEBUG_MODE STREQUAL "Debug")
        # 安装 .so 文件
        install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
            DESTINATION lib
            FILES_MATCHING PATTERN "*.so"
        )
        # 安装 Qt 库
        install(DIRECTORY ${QT_INSTALL_DIR}/lib/
            DESTINATION lib
            FILES_MATCHING PATTERN "*.so*"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/
            DESTINATION lib
            FILES_MATCHING PATTERN "*"
        )
    else()
        # 安装 .so 文件
        install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
            DESTINATION lib
            FILES_MATCHING PATTERN "*.so"
        )
        # 安装 Qt 库
        install(DIRECTORY ${QT_INSTALL_DIR}/lib/
            DESTINATION lib
            FILES_MATCHING PATTERN "*.so*"
        )
        # 安装 Qt 平台 #直接拷贝文件夹
        install(DIRECTORY ${QT_INSTALL_DIR}/plugins/
            DESTINATION lib
            FILES_MATCHING PATTERN "*"
        )
    endif()
endif()
### 设置安装路径 ###
install(DIRECTORY ${CMAKE_LIBRARY_INCLUDE_OUTPUT_DIRECTORY}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
### 设置安装路径 ###
install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
    DESTINATION bin
    FILES_MATCHING PATTERN "*.dll"
)


### 安装其他三方库 ###
if(WIN32)
    ### 查询 WIN32_DYNAMIC_LIB_DIR 里有多个路径 ###
    foreach(var IN ITEMS ${WIN32_DYNAMIC_LIB_DIR})
        install(DIRECTORY ${var}/
            DESTINATION lib
            FILES_MATCHING PATTERN "**/*.lib"
         )
    endforeach()
    ### 查询 WIN32_DYNAMIC_DLL_DIR 里有多个路径 ###
    foreach(var IN ITEMS ${WIN32_DYNAMIC_DLL_DIR})
        install(DIRECTORY ${var}/
            DESTINATION bin
            FILES_MATCHING PATTERN "**/*.dll"
         )
    endforeach()
    ### 查询 WIN32_DYNAMIC_INCLUDE_DIR 里有多个路径 ###
    foreach(var IN ITEMS ${WIN32_DYNAMIC_INCLUDE_DIR})
        install(DIRECTORY ${var}/
            DESTINATION include
            FILES_MATCHING PATTERN "*.h"
         )
    endforeach()
else(UNIX)
    ### 查询 LINUX_DYNAMIC_SO_DIR 里有多个路径 ###
    foreach(var IN ITEMS ${LINUX_DYNAMIC_SO_DIR})
        install(DIRECTORY ${var}/
            DESTINATION lib
            FILES_MATCHING PATTERN "**/*.so"
         )
    endforeach()
    ### 查询 LINUX_DYNAMIC_INCLUDE_DIR 里有多个路径 ###
    foreach(var IN ITEMS ${LINUX_DYNAMIC_INCLUDE_DIR})
        install(DIRECTORY ${var}/
            DESTINATION include
            FILES_MATCHING PATTERN "*.h"
         )
    endforeach()
endif()


