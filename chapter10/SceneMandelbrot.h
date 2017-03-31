//
// Created by aicdg on 2017/3/31.
//

#ifndef GL4COOKBOOK_SCENEMANDELBROT_H
#define GL4COOKBOOK_SCENEMANDELBROT_H


#include "scene.h"
#include "glslprogram.h"

#include <glad/glad.h>
#include "Meshes/vbocube.h"

#include <glm/glm.hpp>
using glm::mat4;

class SceneMandelbrot : public Scene
{
private:
    GLSLProgram renderProg, computeProg;

    int width, height;
    GLuint dataBuf, fsQuad;
    VBOCube *cube;

    glm::vec2 center;
    float cheight;

    float time, deltaT, speed;
    float angle, rotSpeed;

    void compileAndLinkShader();
    void initBuffers();
    void setWindow();

public:
    SceneMandelbrot();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEMANDELBROT_H
