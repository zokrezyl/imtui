add_executable(imtui-example-xcurses0 main.cpp)
target_include_directories(imtui-example-xcurses0 PRIVATE ..)
target_link_libraries(imtui-example-xcurses0 PRIVATE imtui-xcurses imtui-examples-common)
