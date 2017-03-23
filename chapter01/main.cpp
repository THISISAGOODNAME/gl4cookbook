//
// Created by yangyanjun on 2017/3/23.
//

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// STL
#include <iostream>
#include <string>

//
#include "scene.h"
#include "glutils.h"
#include "SceneBasic.h"
#include "SceneBasic_Attrib.h"
#include "SceneBasic_Uniform.h"
#include "SceneBasic_UniformBlock.h"

Scene *scene;
GLFWwindow *window;

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
    scene->initScene();
}

void mainLoop() {
    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_SPACE)) {
        GLUtils::checkForOpenGLError(__FILE__, __LINE__);
        scene->update(float(glfwGetTime()));
        scene->render();
        glfwSwapBuffers(window);
        glfwPollEvents();
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

    // Open the window
    std::string title = "Chapter 01 -- " + recipe;
    window = glfwCreateWindow(500, 500, title.c_str(), nullptr, nullptr);
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

    if( recipe == "basic" ) {
        scene = new SceneBasic();
    } else if( recipe == "basic-attrib") {
        scene = new SceneBasic_Attrib();
    } else if( recipe == "basic-uniform") {
        scene = new SceneBasic_Uniform();
    } else if( recipe == "basic-uniform-block" ) {
        scene = new SceneBasic_UniformBlock();
//    } else if( recipe == "basic-debug" ) {
//        scene = new SceneBasic_Debug();
    } else {
        printf("Unknown recipe: %s\n", recipe.c_str());
        exit(EXIT_FAILURE);
    }

    return recipe;
}

void printHelpInfo(const char * exeFile) {
    printf("Usage: %s recipe-name\n\n", exeFile);
    printf("Recipe names: \n");
    printf("  basic              : Basic scene.\n");
    printf("  basic-attrib       : Prints active attributes.\n");
//    printf("  basic-debug        : Display debug messages.\n");
    printf("  basic-uniform      : Basic scene with a uniform variable.\n");
    printf("  basic-uniform-block: Scene with a uniform block variable.\n");
}