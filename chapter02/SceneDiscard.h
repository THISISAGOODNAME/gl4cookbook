//
// Created by yangyanjun on 2017/3/24.
//

#ifndef GL4COOKBOOK_SCENEDISCARD_H
#define GL4COOKBOOK_SCENEDISCARD_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboteapot.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneDiscard : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOTeapot *teapot;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneDiscard();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEDISCARD_H
