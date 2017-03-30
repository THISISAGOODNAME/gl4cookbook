//
// Created by yangyanjun on 2017/3/30.
//

#ifndef GL4COOKBOOK_SCENESHADOWMA_H
#define GL4COOKBOOK_SCENESHADOWMA_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbotorus.h"
#include "Meshes/vboteapot.h"
#include "frustum.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;
using glm::vec4;
using glm::vec3;

class SceneShadowMap : public Scene
{
private:
    GLSLProgram prog, solidProg;
    GLuint shadowFBO, pass1Index, pass2Index;

    VBOTeapot *teapot;
    VBOPlane *plane;
    VBOTorus *torus;

    int width, height;
    int shadowMapWidth, shadowMapHeight;
    float tPrev;

    mat4 model, view, projection;
    mat4 lightPV;
    mat4 shadowBias;
    float angle;

    Frustum *lightFrustum;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void drawScene();
    void spitOutDepthBuffer();

public:
    SceneShadowMap();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENESHADOWMA_H
