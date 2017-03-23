set(chapter01_SOURCES main.cpp ${GLAD_FILES} ${COMMON_SOURCES})
set(SCENES
        SceneBasic.cpp SceneBasic.h
        SceneBasic_Attrib.cpp SceneBasic_Attrib.h
        SceneBasic_Uniform.cpp SceneBasic_Uniform.h
        SceneBasic_UniformBlock.cpp SceneBasic_UniformBlock.h)

add_executable(chapter01 ${chapter01_SOURCES} ${SCENES})
target_link_libraries(chapter01 ${COMMON_LIBS})