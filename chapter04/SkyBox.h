//
// Created by yangyanjun on 2017/3/27.
//

#ifndef GL4COOKBOOK_SKYBOX_H
#define GL4COOKBOOK_SKYBOX_H

#include "Meshes/drawable.h"

class SkyBox : public Drawable
{
private:
    unsigned int vaoHandle;

public:
    SkyBox();

    void render() const;
};


#endif //GL4COOKBOOK_SKYBOX_H
