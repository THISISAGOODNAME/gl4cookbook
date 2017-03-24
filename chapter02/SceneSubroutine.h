//
// Created by yangyanjun on 2017/3/24.
//

#ifndef GL4COOKBOOK_SCENESUBROUTINE_H
#define GL4COOKBOOK_SCENESUBROUTINE_H



#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneSubroutine : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOTorus *torus;
    VBOTeapot *teapot;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneSubroutine();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENESUBROUTINE_H
