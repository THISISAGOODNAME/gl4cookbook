//
// Created by yangyanjun on 2017/3/30.
//

#ifndef GL4COOKBOOK_SCENEAO_H
#define GL4COOKBOOK_SCENEAO_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"
#include "Meshes/vbomesh.h"
#include "frustum.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;
using glm::vec4;
using glm::vec3;

class SceneAo : public Scene
{
private:
    GLSLProgram prog;

    VBOTeapot *teapot;
    VBOPlane *plane;
    VBOTorus *torus;
    VBOMesh *ogre;

    int width, height;

    mat4 model, view, projection;
    vec4 lightPos;
    float angle;

    void setMatrices();
    void compileAndLinkShader();
    void drawScene();

public:
    SceneAo();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEAO_H
