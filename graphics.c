#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

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

    GLFWwindow* window = glfwCreateWindow(600, 900, "Graphics Engine", NULL, NULL);

    if(!window){
        fprintf(stderr, "Failed to create window");
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    while(!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}