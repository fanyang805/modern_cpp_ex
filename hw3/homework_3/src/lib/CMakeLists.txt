add_library(html_writer html_writer.cpp)

add_library(image_browser image_browser.cpp)

target_link_libraries(image_browser html_writer)