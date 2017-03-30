//
// Created by yangyanjun on 2017/3/30.
//

#ifndef GL4COOKBOOK_SCENEPCF_H
#define GL4COOKBOOK_SCENEPCF_H


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

class ScenePcf : public Scene
{
private:
    GLSLProgram prog;
    GLuint shadowFBO, pass1Index, pass2Index;

    VBOTeapot *teapot;
    VBOPlane *plane;
    VBOTorus *torus;
    VBOMesh *mesh;

    Frustum *lightFrustum;

    int width, height;
    int shadowMapWidth, shadowMapHeight;
    float tPrev;

    mat4 model, view, projection;
    mat4 lightView, lightProjection, lightPV;
    mat4 shadowScale;
    vec3 lightPos;
    float angle;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void drawScene();
    void drawBuildingScene();

public:
    ScenePcf();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEPCF_H
