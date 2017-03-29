set(chapter06_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        )

add_executable(chapter06 ${chapter06_SOURCES} ${SCENES})
target_link_libraries(chapter06 ${COMMON_LIBS})