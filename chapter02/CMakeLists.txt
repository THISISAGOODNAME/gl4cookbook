set(chapter02_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        SceneADS.cpp SceneADS.h
        SceneDiffuse.cpp SceneDiffuse.h)

add_executable(chapter02 ${chapter02_SOURCES} ${SCENES})
target_link_libraries(chapter02 ${COMMON_LIBS})
