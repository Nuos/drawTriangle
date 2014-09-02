//
//  SimpleShader.h
//  draw-triangle
//
//  Created by sbx_fc on 14-9-1.
//  Copyright (c) 2014年 rungame.me. All rights reserved.
//

const char* vert_shader =
"\
#version 150\n\
\n\
in vec3 position;\n\
in vec3 color;\n\
out vec3 ver_color;\n\
\n\
void main(void) { \n\
ver_color = color;\n\
gl_Position = vec4(position, 1.0);\n\
}\n\
";

const char* frag_shader =
"\
#version 150\n\
\n\
in vec3 ver_color;\n\
out vec4 frag_color;\n\
\n\
void main(void) { \n\
frag_color = vec4(ver_color,1.0);\n\
}\n\
";

