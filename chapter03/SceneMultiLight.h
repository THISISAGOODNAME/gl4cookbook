//
// Created by aicdg on 2017/3/24.
//

#ifndef GL4COOKBOOK_SCENEMULTILIGHT_H
#define GL4COOKBOOK_SCENEMULTILIGHT_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbomesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneMultiLight : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOPlane *plane;
    VBOMesh * mesh;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneMultiLight();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEMULTILIGHT_H
