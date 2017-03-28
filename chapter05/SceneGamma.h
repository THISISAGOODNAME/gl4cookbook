//
// Created by yangyanjun on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENEGAMMA_H
#define GL4COOKBOOK_SCENEGAMMA_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"
#include "Meshes/vbomesh.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneGamma : public Scene
{
private:
    GLSLProgram prog;

    int width, height;

    VBOPlane *plane;
    VBOTorus *torus;
    VBOMesh *ogre;
    VBOCube *cube;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneGamma();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEGAMMA_H
