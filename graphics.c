#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600

void error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
    glfwTerminate();
    exit(1);
}


int main(){
    glfwSetErrorCallback(error_callback);

    if(!glfwInit()){
        fprintf(stderr, "Failed to initalize glfw");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Graphics Engine", NULL, NULL);

    if(!window){
        fprintf(stderr, "Failed to create window");
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glViewport(0, 0, WIDTH, HEIGHT);

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  

    while(!glfwWindowShouldClose(window)){
        //int width, height;
        //glfwGetFramebufferSize(window, &width, &height);
        //glViewport(0,0,width,height);

        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}