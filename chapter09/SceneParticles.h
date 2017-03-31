//
// Created by yangyanjun on 2017/3/31.
//

#ifndef GL4COOKBOOK_SCENEPARTICLES_H
#define GL4COOKBOOK_SCENEPARTICLES_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneParticles : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    GLuint initVel, startTime, particles;
    GLuint nParticles;

    VBOPlane *plane;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle;
    float time;

    void setMatrices();
    void compileAndLinkShader();
    void initBuffers();
    float randFloat();

public:
    SceneParticles();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEPARTICLES_H
