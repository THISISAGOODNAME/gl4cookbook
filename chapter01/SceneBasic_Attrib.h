//
// Created by yangyanjun on 2017/3/23.
//

#ifndef GL4COOKBOOK_SCENEBASIC_ATTRIB_H
#define GL4COOKBOOK_SCENEBASIC_ATTRIB_H

#include <glad/glad.h>

#include "scene.h"
#include "glslprogram.h"

class SceneBasic_Attrib : public Scene
{
private:
    int width, height;
    GLuint vaoHandle;
    GLSLProgram prog;

    void compileShaderProgram();

public:
    SceneBasic_Attrib();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEBASIC_ATTRIB_H
