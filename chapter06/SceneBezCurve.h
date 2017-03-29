//
// Created by yangyanjun on 2017/3/29.
//

#ifndef GL4COOKBOOK_SCENEBEZCURVE_H
#define GL4COOKBOOK_SCENEBEZCURVE_H


#include "scene.h"
#include "glslprogram.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneBezCurve : public Scene
{
private:
    GLSLProgram prog;
    GLSLProgram solidProg;

    GLuint vaoHandle;

    mat4 model;
    mat4 view, viewport;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneBezCurve();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEBEZCURVE_H
