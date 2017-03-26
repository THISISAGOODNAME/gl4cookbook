//
// Created by aicdg on 2017/3/26.
//

#ifndef GL4COOKBOOK_SCENEFOG_H
#define GL4COOKBOOK_SCENEFOG_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vboteapot.h"
#include "Meshes/vbotorus.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneFog : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    float tPrev;
    VBOPlane *plane;
    VBOTeapot *teapot;
    VBOTorus *torus;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneFog();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEFOG_H
