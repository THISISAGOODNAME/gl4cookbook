//
// Created by yangyanjun on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENEDEFERRED_H
#define GL4COOKBOOK_SCENEDEFERRED_H


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

class SceneDeferred : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    GLuint deferredFBO;
    GLuint quad, pass1Index, pass2Index;

    VBOPlane *plane;
    VBOTorus *torus;
    VBOMesh *ogre;
    VBOCube *cube;
    VBOTeapot *teapot;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void createGBufTex(GLenum, GLenum, GLuint &);
    void pass1();
    void pass2();

public:
    SceneDeferred();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEDEFERRED_H
