//
// Created by aicdg on 2017/3/31.
//

#ifndef GL4COOKBOOK_SCENECLOTH_H
#define GL4COOKBOOK_SCENECLOTH_H


#include "scene.h"
#include "glslprogram.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneCloth : public Scene
{
private:
    GLSLProgram renderProg, computeProg, computeProgNorm;

    int width, height;
    GLuint clothVao;
    GLuint numElements;

    glm::ivec2 nParticles;  // Number of particles in each dimension
    glm::vec2 clothSize;    // Size of cloth in x and y

    float time, deltaT, speed;
    GLuint readBuf;
    GLuint posBufs[2], velBufs[2];
    GLuint normBuf, elBuf, tcBuf;

    glm::mat4 view, model, projection;

    void compileAndLinkShader();
    void initBuffers();
    void setMatrices();

public:
    SceneCloth();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENECLOTH_H
