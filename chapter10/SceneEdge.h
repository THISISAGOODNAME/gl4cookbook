//
// Created by aicdg on 2017/3/31.
//

#ifndef GL4COOKBOOK_SCENEEDGE_H
#define GL4COOKBOOK_SCENEEDGE_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneEdge : public Scene
{
private:
    GLSLProgram prog, computeProg;

    int width, height;
    GLuint fsQuad, pass1Index, pass2Index, fboHandle;

    VBOPlane *plane;
    VBOTorus *torus;
    VBOTeapot *teapot;
    VBOCube *cube;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void pass1();
    void pass2();

public:
    SceneEdge();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEEDGE_H
