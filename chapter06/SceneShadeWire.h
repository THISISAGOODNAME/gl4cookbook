//
// Created by yangyanjun on 2017/3/29.
//

#ifndef GL4COOKBOOK_SCENESHADEWIRE_H
#define GL4COOKBOOK_SCENESHADEWIRE_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vbomesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneShadeWire : public Scene
{
private:
    GLSLProgram prog;

    VBOMesh *ogre;

    mat4 model;
    mat4 view, viewport;
    mat4 projection;

    int width, height;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneShadeWire();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENESHADEWIRE_H
