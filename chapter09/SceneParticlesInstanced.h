//
// Created by yangyanjun on 2017/3/31.
//

#ifndef GL4COOKBOOK_SCENEPARTICLESINSTANCED_H
#define GL4COOKBOOK_SCENEPARTICLESINSTANCED_H



#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbotorus.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneParticlesInstanced : public Scene
{
private:
    GLSLProgram prog;

    int width, height;

    GLuint particleArray;
    GLuint initVel, startTime;

    int nParticles;

    VBOPlane *plane;
    VBOTorus *torus;

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
    SceneParticlesInstanced();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEPARTICLESINSTANCED_H
