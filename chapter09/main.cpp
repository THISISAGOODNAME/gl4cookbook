//
// Created by yangyanjun on 2017/3/31.
//


// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// STL
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>
using std::stringstream;

//
#include "scene.h"
#include "glutils.h"
#include "SceneWave.h"
#include "SceneParticles.h"
#include "SceneParticlesFeedback.h"
#include "SceneParticlesInstanced.h"
#include "SceneFire.h"
#include "SceneSmoke.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

Scene *scene;
GLFWwindow *window;
std::string title;

std::string parseCLArgs(int argc, char **argv);
void printHelpInfo(const char *);

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
    {
        if (scene)
            scene->animate( !(scene->animating()) );
    }
}

void initializeGL() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
#ifndef __APPLE__
    glDebugMessageCallback(GLUtils::debugCallback, NULL);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
    glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 0,
                         GL_DEBUG_SEVERITY_NOTIFICATION, -1 , "Start debugging");
#endif
    scene->initScene();
}

void mainLoop() {
    const int samples = 50;
    float time[samples];
    int index = 0;

    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_SPACE)) {
        GLUtils::checkForOpenGLError(__FILE__, __LINE__);
        scene->update(float(glfwGetTime()));
        scene->render();
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Update FPS
        time[index] = float(glfwGetTime());
        index = (index + 1) % samples;

        if( index == 0 ) {
            float sum = 0.0f;
            for( int i = 0; i < samples-1 ; i++ )
                sum += time[i + 1] - time[i];
            float fps = samples / sum;

            stringstream strm;
            strm << title;
            strm.precision(4);
            strm << " (fps: " << fps << ")";
            glfwSetWindowTitle(window, strm.str().c_str());
        }
    }
}

void resizeGL(int w, int h) {
    scene->resize(w, h);
}

int main(int argc, char * argv[]) {
    std::string recipe = parseCLArgs(argc, argv);

    //
    glfwInit();
#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#endif
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_SAMPLES, 8);
//    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    // Open the window
    title = "Chapter 09 -- " + recipe;
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, title.c_str(), nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    // Load OpenGL Functions
    gladLoadGL();
    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

    // Viewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    GLUtils::dumpGLInfo();

    // Initialization
    resizeGL(width, height);
    initializeGL();

    // Enter the main loop
    mainLoop();

    // Close window and terminate GLFW
    glfwTerminate();
    return EXIT_SUCCESS;
}

std::string parseCLArgs(int argc, char ** argv) {

    if( argc < 2 ) {
        printHelpInfo(argv[0]);
        exit(EXIT_FAILURE);
    }

    std::string recipe = argv[1];

    if( recipe == "fire" ) {
        scene = new SceneFire();
    } else if( recipe == "particles") {
        scene = new SceneParticles();
    } else if( recipe == "particles-feedback") {
        scene = new SceneParticlesFeedback();
    } else if( recipe == "particles-instanced" ) {
        scene = new SceneParticlesInstanced();
    } else if( recipe == "smoke" ) {
        scene = new SceneSmoke();
    } else if( recipe == "wave" ) {
        scene = new SceneWave();
    } else {
        printf("Unknown recipe: %s\n", recipe.c_str());
        printHelpInfo(argv[0]);
        exit(EXIT_FAILURE);
    }

    return recipe;
}

void printHelpInfo(const char * exeFile) {
    printf("Usage: %s recipe-name\n\n", exeFile);
    printf("Recipe names: \n");
    printf("  fire                 : particles simulating fire\n");
    printf("  particles            : a fountain of particles\n");
    printf("  particles-feedback   : a fountain of particles implemented with transform feedback\n");
    printf("  particles-instanced  : a fountain of instanced particles, mmmm.. donuts\n");
    printf("  smoke                : particles simulating smoke\n");
    printf("  wave                 : a plane wave displacement animation\n");
}

