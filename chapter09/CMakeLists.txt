set(chapter09_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        )

add_executable(chapter09 ${chapter09_SOURCES} ${SCENES})
target_link_libraries(chapter09 ${COMMON_LIBS})