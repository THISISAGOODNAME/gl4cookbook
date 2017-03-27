set(chapter04_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        SceneTexture.cpp SceneTexture.h
        SceneMultiTex.cpp SceneMultiTex.h
        SceneAlphaTest.cpp SceneAlphaTest.h
        SceneNormalMap.cpp SceneNormalMap.h
        SkyBox.cpp SkyBox.h
        SceneReflectCube.cpp SceneReflectCube.h
        SceneRefractCube.cpp SceneRefractCube.h
        SceneProjTex.cpp SceneProjTex.h)

add_executable(chapter04 ${chapter04_SOURCES} ${SCENES})
target_link_libraries(chapter04 ${COMMON_LIBS})