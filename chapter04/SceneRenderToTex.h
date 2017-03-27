//
// Created by aicdg on 2017/3/27.
//

#ifndef GL4COOKBOOK_SCENERENDERTOTEX_H
#define GL4COOKBOOK_SCENERENDERTOTEX_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vboteapot.h"

// OpenGL headers
#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneRenderToTex : public Scene
{
private:
    GLSLProgram prog;

    GLuint fboHandle;
    int width, height;
    VBOCube *cube;
    VBOTeapot *teapot;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle;
    float tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void renderToTexture();
    void renderScene();

public:
    SceneRenderToTex();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENERENDERTOTEX_H
