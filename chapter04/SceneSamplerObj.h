//
// Created by yangyanjun on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENESAMPLEROBJ_H
#define GL4COOKBOOK_SCENESAMPLEROBJ_H


// OpenGL headers
#include <glad/glad.h>

#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"

#include <glm/glm.hpp>
using glm::mat4;

class SceneSamplerObj : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOPlane *plane;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle;
    GLuint linearSampler, nearestSampler;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneSamplerObj();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENESAMPLEROBJ_H
