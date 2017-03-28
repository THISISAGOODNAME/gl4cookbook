//
// Created by aicdg on 2017/3/28.
//

#ifndef GL4COOKBOOK_SCENEOIT_H
#define GL4COOKBOOK_SCENEOIT_H


#include "scene.h"
#include "glslprogram.h"
#include "Meshes/vboplane.h"
#include "Meshes/vbocube.h"
#include "Meshes/vbosphere.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
using glm::mat4;

enum BufferNames {
    COUNTER_BUFFER = 0,
    LINKED_LIST_BUFFER
};

struct ListNode {
    glm::vec4 color;
    GLfloat depth;
    GLuint next;
};

class SceneOit : public Scene
{
private:
    GLSLProgram prog;

    int width, height;
    GLuint buffers[2], fsQuad, headPtrTex;
    GLuint pass1Index, pass2Index;
    GLuint clearBuf;

    VBOCube *cube;
    VBOSphere *sphere;

    mat4 model;
    mat4 view;
    mat4 projection;
    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void drawScene();
    void initShaderStorage();
    void pass1();
    void pass2();
    void clearBuffers();

public:
    SceneOit();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);

};


#endif //GL4COOKBOOK_SCENEOIT_H
