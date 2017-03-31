//
// Created by yangyanjun on 2017/3/31.
//

#ifndef GL4COOKBOOK_SCENEFIRE_H
#define GL4COOKBOOK_SCENEFIRE_H


#include "scene.h"
#include "glslprogram.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneFire : public Scene
{
private:
    GLSLProgram prog;

    int width, height;

    GLuint posBuf[2], velBuf[2];
    GLuint particleArray[2];
    GLuint feedback[2], initVel, startTime[2];
    GLuint drawBuf;
    GLuint renderSub, updateSub;

    int nParticles;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle;
    float time, deltaT;

    void setMatrices();
    void compileAndLinkShader();
    void initBuffers();
    float randFloat();

public:
    SceneFire();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEFIRE_H
