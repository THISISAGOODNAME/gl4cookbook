set(chapter07_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        frustum.cpp frustum.h
        SceneShadowMap.cpp SceneShadowMap.h
        ScenePcf.cpp ScenePcf.h
        SceneJitter.cpp SceneJitter.h
        SceneShadowVolume.cpp SceneShadowVolume.h
        SceneAo.cpp SceneAo.h)

add_executable(chapter07 ${chapter07_SOURCES} ${SCENES})
target_link_libraries(chapter07 ${COMMON_LIBS})