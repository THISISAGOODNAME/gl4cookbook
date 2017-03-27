//
// Created by yangyanjun on 2017/3/27.
//

#ifndef GL4COOKBOOK_SCENEREFLECTCUBE_H
#define GL4COOKBOOK_SCENEREFLECTCUBE_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbomesh.h"
#include "Meshes/vboteapot.h"
#include "skybox.h"

// OpenGL headers
#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneReflectCube : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    VBOTeapot *teapot;
    SkyBox *sky;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void loadCubeMap( const char * baseFileName );

public:
    SceneReflectCube();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEREFLECTCUBE_H
