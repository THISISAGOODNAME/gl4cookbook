set(chapter06_SOURCES ${GLAD_FILES} ${COMMON_SOURCES} main.cpp)
set(SCENES
        ScenePointSprit.cpp ScenePointSprit.h
        SceneShadeWire.cpp SceneShadeWire.h
        SceneSilhouette.cpp SceneSilhouette.h
        SceneBezCurve.cpp SceneBezCurve.h
        SceneQuadTess.cpp SceneQuadTess.h
        SceneTessTeapot.cpp SceneTessTeapot.h)

add_executable(chapter06 ${chapter06_SOURCES} ${SCENES})
target_link_libraries(chapter06 ${COMMON_LIBS})