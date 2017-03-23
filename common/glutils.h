#ifndef GLUTILS_H
#define GLUTILS_H

#include <glad/glad.h>

class GLUtils
{
public:
    GLUtils();

    static int checkForOpenGLError(const char *, int);
    static void dumpGLInfo(bool dumpExtensions = false);

    static void APIENTRY debugCallback( GLenum source, GLenum type, GLuint id,
                                 GLenum severity, GLsizei length, const GLchar * msg, const void * param );
};

#endif // GLUTILS_H
