set(chapter07_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        )

add_executable(chapter07 ${chapter07_SOURCES} ${SCENES})
target_link_libraries(chapter07 ${COMMON_LIBS})