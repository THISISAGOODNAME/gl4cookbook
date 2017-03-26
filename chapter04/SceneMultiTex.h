//
// Created by aicdg on 2017/3/26.
//

#ifndef GL4COOKBOOK_SCENEMULTITEX_H
#define GL4COOKBOOK_SCENEMULTITEX_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vbocube.h"

// OpenGL headers
#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneMultiTex : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOCube *cube;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneMultiTex();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};



#endif //GL4COOKBOOK_SCENEMULTITEX_H
