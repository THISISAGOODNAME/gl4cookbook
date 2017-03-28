set(chapter05_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        SceneEdge.cpp SceneEdge.h
        SceneBlur.cpp SceneBlur.h
        SceneToneMap.cpp SceneToneMap.h
        SceneHdrBloom.cpp SceneHdrBloom.h
        SceneGamma.cpp SceneGamma.h)

add_executable(chapter05 ${chapter05_SOURCES} ${SCENES})
target_link_libraries(chapter05 ${COMMON_LIBS})