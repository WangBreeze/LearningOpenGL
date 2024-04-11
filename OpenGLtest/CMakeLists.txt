# CMakeList.txt: OpenGLtest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
# 查找Qt包
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick QuickWidgets SerialPort Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick QuickWidgets SerialPort Concurrent)
find_package(GLFW REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 包含Qt头文件
include_directories(${Qt5Core_INCLUDE_DIRS}
    glm
)

qt5_add_resources(QRC_SOURCES qrc.qrc)


file(GLOB_RECURSE PROJECT_SOURCES   *.cpp *.hpp *.qrc *.json *.c *.rc *.ini)
file(GLOB_RECURSE PROJECT_SOURCESC   *.c *.h)

# 将源代码添加到此项目的可执行文件。
add_executable (OpenGLtest
    ${QRC_SOURCES}
    ${PROJECT_SOURCES}
    ${PROJECT_SOURCESC}

)

# 链接Qt库
#target_link_libraries(OpenGLtest Qt5::Core)
target_link_libraries(OpenGLtest Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickWidgets  Qt${QT_VERSION_MAJOR}::Concurrent)
#set(glfw3_DIR ${GLFW_INCLUDE_DIRS}../lib/cmake/glfw3/glfw3Config.cmake)
#find_package(GLFW REQUIRED)
#include_directories(${GLFW_INCLUDE_DIRS})
#find_package(glfw3 REQUIRED)
#target_link_libraries(OpenGLtest GLFW)

########
include_directories("C:\\ProgramData\\Glad\\include")
#include_directories("C:\\ProgramData\\GLFW\\include")
###使用 target_link_libraries 正确，不能使用 link_libraries
target_link_libraries(OpenGLtest "C:\\ProgramData\\GLFW\\lib\\glfw3d.lib")
#target_link_libraries(OpenGLtest "C:\\ProgramData\\GLFW\\lib\\glfw3.lib")
#target_link_libraries(OpenGLtest "C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.22621.0\\um\\x64\\OpenGL32.Lib")
#link_libraries("C:\\ProgramData\\GLFW\\lib\\glfw3d.lib")
#link_libraries("C:\\ProgramData\\GLFW\\lib\\glfw3.lib")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGLtest PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
