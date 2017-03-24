//
// Created by aicdg on 2017/3/23.
//

#ifndef GL4COOKBOOK_SCENEADS_H
#define GL4COOKBOOK_SCENEADS_H

#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vbotorus.h"

#include <glad/glad.h>

#include <glm/glm.hpp>

class SceneADS : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOTorus *torus;
    float angle;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneADS();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);

};


#endif //GL4COOKBOOK_SCENEADS_H
