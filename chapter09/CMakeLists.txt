set(chapter09_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        SceneWave.cpp SceneWave.h
        SceneParticles.cpp SceneParticles.h
        SceneParticlesFeedback.cpp SceneParticlesFeedback.h
        SceneParticlesInstanced.cpp SceneParticlesInstanced.h
        SceneFire.cpp SceneFire.h SceneSmoke.cpp SceneSmoke.h)

add_executable(chapter09 ${chapter09_SOURCES} ${SCENES})
target_link_libraries(chapter09 ${COMMON_LIBS})