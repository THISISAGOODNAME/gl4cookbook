//
// Created by aicdg on 2017/3/26.
//

#ifndef GL4COOKBOOK_SCENEALPHATEST_H
#define GL4COOKBOOK_SCENEALPHATEST_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vboteapot.h"

// OpenGL headers
#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneAlphaTest : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOTeapot *teapot;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneAlphaTest();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEALPHATEST_H
