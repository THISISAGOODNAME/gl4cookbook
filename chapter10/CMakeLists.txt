set(chapter10_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        SceneParticles.cpp SceneParticles.h
        SceneCloth.cpp SceneCloth.h
        SceneEdge.cpp SceneEdge.h
        SceneMandelbrot.cpp SceneMandelbrot.h)

add_executable(chapter10 ${chapter10_SOURCES} ${SCENES})
target_link_libraries(chapter10 ${COMMON_LIBS})