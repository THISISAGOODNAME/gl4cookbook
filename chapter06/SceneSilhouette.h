//
// Created by yangyanjun on 2017/3/29.
//

#ifndef GL4COOKBOOK_SCENESILHOUETTE_H
#define GL4COOKBOOK_SCENESILHOUETTE_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vbomeshadj.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

class SceneSilhouette : public Scene
{
private:
    GLSLProgram prog;

    VBOMeshAdj *ogre;

    mat4 model;
    mat4 view, viewport;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    int width, height;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneSilhouette();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENESILHOUETTE_H
