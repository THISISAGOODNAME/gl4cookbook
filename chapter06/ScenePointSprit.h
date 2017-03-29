//
// Created by yangyanjun on 2017/3/29.
//

#ifndef GL4COOKBOOK_SCENEPOINTSPRIT_H
#define GL4COOKBOOK_SCENEPOINTSPRIT_H


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

class ScenePointSprite : public Scene
{
private:
    GLSLProgram prog;

    GLuint sprites;

    int width, height;

    VBOPlane *plane;
    VBOTorus *torus;
    VBOMesh *ogre;
    VBOCube *cube;

    int numSprites;
    float *locations;

    mat4 model;
    mat4 view;
    mat4 projection;

    void setMatrices();
    void compileAndLinkShader();

public:
    ScenePointSprite();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};


#endif //GL4COOKBOOK_SCENEPOINTSPRIT_H
