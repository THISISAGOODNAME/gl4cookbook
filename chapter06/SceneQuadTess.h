//
// Created by yangyanjun on 2017/3/29.
//

#ifndef GL4COOKBOOK_SCENEQUADTESS_H
#define GL4COOKBOOK_SCENEQUADTESS_H


#include "scene.h"
#include "glslprogram.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneQuadTess : public Scene
{
private:
    GLSLProgram prog;

    GLuint vaoHandle;

    mat4 model;
    mat4 view, viewport;
    mat4 projection;

    int width, height;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneQuadTess();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEQUADTESS_H
