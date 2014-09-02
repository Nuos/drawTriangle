//
//  ShaderLoader.h
//  draw-triangle
//
//  Created by sbx_fc on 14-9-1.
//  Copyright (c) 2014年 rungame.me. All rights reserved.
//

#include <OpenGL/gl3.h>


class ShaderLoader
{
    public:
        ShaderLoader();
        ~ShaderLoader();
    
        bool initFromString(const char* vertexShader, const char* fragmentShader);
        void bind();
        void addAttribute(const char* attributeName, GLuint index);
        void unbind();
        unsigned int id();
    
    private:
        bool link();
        bool compileShader(GLuint* shader, GLenum type, const GLchar* source);
        
    private:
        GLuint _programID;
        GLuint _vertShader;
        GLuint _fragShader;
};

