//
// Created by yangyanjun on 2017/3/24.
//

#ifndef GL4COOKBOOK_SCENEDIFFUSE_H
#define GL4COOKBOOK_SCENEDIFFUSE_H

#include "scene.h"
#include "glslprogram.h"
#include "vbotorus.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneDiffuse :public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOTorus *torus;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneDiffuse();

    void initScene();
    void update( float f );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEDIFFUSE_H
