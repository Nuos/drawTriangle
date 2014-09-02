#include <stdio.h>
#include <OpenGL/gl3.h>
#define GLFW_INCLUDE_GLCOREARB
//define GLFW_INCLUDE_GLCOREARB to avoid glfw include gl.h, which is conflict with gl3.h
//ref http://stackoverflow.com/questions/19825582/modern-opengl-with-glfw3-on-mac-osx-10-8-4-missing-glgenvertexarrays-and-glb
#include <GLFW/glfw3.h>
#include "ShaderLoader.h"
#include "SimpleShader.h"


ShaderLoader myShader;

//设置三角形
void initTriangle(void)
{

    GLfloat vertex_data[] = {
        -1.0f,-1.0f,0.0f,
        1.0f,-1.0f,0.0f,
        0.0f,1.0f,0.0f,
    };
    
    GLfloat color_data[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };
    
    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    
    GLuint vbo[2];
    glGenBuffers(2, vbo);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color_data), color_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,0);
}

//初始化着色器
void initShader(void)
{
    myShader.initFromString(vert_shader, frag_shader);
    myShader.addAttribute("position", 0);
    myShader.addAttribute("color", 1);
    myShader.bind();
}

//绘制三角形
void drawTriangle(void)
{
    //画三角形
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(void)
{
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    initShader();
    initTriangle();
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        
        glClearColor(0.0f,0.0f,0.0f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        drawTriangle();
        
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

