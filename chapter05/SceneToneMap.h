//
// Created by yangyanjun on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENETONEMAP_H
#define GL4COOKBOOK_SCENETONEMAP_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"
#include "Meshes/vbosphere.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneToneMap : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    GLuint hdrFBO;
    GLuint quad, pass1Index, pass2Index;
    GLuint hdrTex, avgTex;

    VBOPlane *plane;
    VBOTorus *torus;
    VBOTeapot *teapot;
    VBOSphere *sphere;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void pass1();
    void pass2();
    void computeLogAveLuminance();
    void drawScene();

public:
    SceneToneMap();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENETONEMAP_H
