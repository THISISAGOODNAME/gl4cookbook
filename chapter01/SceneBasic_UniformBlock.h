//
// Created by yangyanjun on 2017/3/23.
//

#ifndef GL4COOKBOOK_SCENEBASIC_UNIFORMBLOCK_H
#define GL4COOKBOOK_SCENEBASIC_UNIFORMBLOCK_H

#include "scene.h"

#include <glad/glad.h>
#include "glslprogram.h"

#include <glm/glm.hpp>
using glm::mat4;

class SceneBasic_UniformBlock : public Scene
{
private:
    int width, height;
    GLuint vaoHandle;
    GLSLProgram prog;
    float angle;
    mat4 rotationMatrix;

    void compile();
    void initUniformBlockBuffer();

public:
    SceneBasic_UniformBlock();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};



#endif //GL4COOKBOOK_SCENEBASIC_UNIFORMBLOCK_H
