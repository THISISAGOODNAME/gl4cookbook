//
// Created by aicdg on 2017/3/30.
//

#ifndef GL4COOKBOOK_SCENEPAINT_H
#define GL4COOKBOOK_SCENEPAINT_H


#include "scene.h"
#include "glslprogram.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;
using glm::vec4;
using glm::vec3;

#include "Meshes/vboteapot.h"

class ScenePaint : public Scene
{
private:
    GLSLProgram prog;

    VBOTeapot *teapot;

    GLuint quad;
    int width, height;

    mat4 model, view, projection;
    vec4 lightPos;
    float angle;

    void setMatrices();
    void compileAndLinkShader();
    void drawScene();

public:
    ScenePaint();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEPAINT_H
