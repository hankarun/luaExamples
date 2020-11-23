cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)


project(luaTest)

add_subdirectory(lua-5.4.1)
add_subdirectory(sol2)
find_package(SDL2 CONFIG REQUIRED)

set(IMGUIFILES
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_win32.cpp
    imgui/backends/imgui_impl_dx11.cpp
    imgui/ImSequencer.cpp
    imgui/ImCurveEdit.cpp
)

add_executable(sdlLua 
    main.cpp
    window.cpp
    windowmanager.cpp
    renderwindow.cpp
    demowindow.cpp
    testwindow.cpp
    timelinewindow.cpp
    filemanager.h
    ${IMGUIFILES})

target_link_libraries(sdlLua dxgi d3d11 d3dcompiler lua_static sol2  SDL2::SDL2 SDL2::SDL2main)

target_include_directories(sdlLua 
        PRIVATE imgui
        PRIVATE imgui/backends)

#target_link_libraries(sdlLua lua_static sol2  SDL2::SDL2 SDL2::SDL2main)
#target_link_libraries(sdlLua SDL2::SDL2 SDL2::SDL2main)