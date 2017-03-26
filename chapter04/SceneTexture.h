//
// Created by aicdg on 2017/3/26.
//

#ifndef GL4COOKBOOK_SCENETEXTURE_H
#define GL4COOKBOOK_SCENETEXTURE_H


#include <glad/glad.h>

#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"

#include <glm/glm.hpp>
using glm::mat4;

class SceneTexture : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOCube *cube;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneTexture();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENETEXTURE_H
