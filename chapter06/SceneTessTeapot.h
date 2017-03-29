//
// Created by aicdg on 2017/3/29.
//

#ifndef GL4COOKBOOK_SCENETESSTEAPOT_H
#define GL4COOKBOOK_SCENETESSTEAPOT_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboteapotpatch.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneTessTeapot : public Scene
{
private:
    GLSLProgram prog;

    GLuint vaoHandle;

    VBOTeapotPatch *teapot;

    mat4 model;
    mat4 view, viewport;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneTessTeapot();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENETESSTEAPOT_H
