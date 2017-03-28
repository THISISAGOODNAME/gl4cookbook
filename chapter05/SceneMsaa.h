//
// Created by yangyanjun on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENEMSA_H
#define GL4COOKBOOK_SCENEMSA_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneMsaa : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    GLuint quad;

    VBOPlane *plane;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();

public:
    SceneMsaa();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};



#endif //GL4COOKBOOK_SCENEMSA_H
