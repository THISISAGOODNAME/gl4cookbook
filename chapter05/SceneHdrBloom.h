//
// Created by yangyanjun on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENEHDRBLOOM_H
#define GL4COOKBOOK_SCENEHDRBLOOM_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"
#include "Meshes/vbosphere.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneHdrBloom : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    GLuint fsQuad, pass1Index, pass2Index, pass3Index, pass4Index, pass5Index;
    GLuint hdrFbo, blurFbo;
    GLuint hdrTex, tex1, tex2;
    GLuint linearSampler, nearestSampler;

    VBOPlane *plane;
    VBOTeapot *teapot;
    VBOSphere *sphere;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;
    int bloomBufWidth, bloomBufHeight;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void pass1();
    void pass2();
    void pass3();
    void pass4();
    void pass5();
    float gauss(float, float);
    void drawScene();
    void computeLogAveLuminance();

public:
    SceneHdrBloom();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEHDRBLOOM_H
