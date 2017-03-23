//
// Created by yangyanjun on 2017/3/23.
//

#ifndef GL4COOKBOOK_SCENEBASIC_H
#define GL4COOKBOOK_SCENEBASIC_H

#include "scene.h"

#include <glad/glad.h>

class SceneBasic : public Scene
{
private:
    int width, height;
    GLuint vaoHandle;

    void linkMe(GLuint vertShader, GLuint fragShader);

public:
    SceneBasic();

    void initScene();
    void update(float t);
    void render();
    void resize(int, int);

};


#endif //GL4COOKBOOK_SCENEBASIC_H
