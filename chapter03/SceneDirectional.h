//
// Created by aicdg on 2017/3/24.
//

#ifndef GL4COOKBOOK_SCENEDIRECTIONAL_H
#define GL4COOKBOOK_SCENEDIRECTIONAL_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbotorus.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneDirectional : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOPlane *plane;
    VBOTorus *torus;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneDirectional();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEDIRECTIONAL_H
