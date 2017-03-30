set(chapter08_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        noisetex.cpp noisetex.h
        SceneNoise.cpp SceneNoise.h
        SceneSky.cpp SceneSky.h
        SceneWood.cpp SceneWood.h
        SceneDecay.cpp SceneDecay.h)

add_executable(chapter08 ${chapter08_SOURCES} ${SCENES})
target_link_libraries(chapter08 ${COMMON_LIBS})