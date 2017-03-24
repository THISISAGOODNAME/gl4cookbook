set(chapter03_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        SceneMultiLight.cpp SceneMultiLight.h
        SceneDirectional.cpp SceneDirectional.h)

add_executable(chapter03 ${chapter03_SOURCES} ${SCENES})
target_link_libraries(chapter03 ${COMMON_LIBS})