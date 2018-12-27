#ifndef OPENGL_CLION_TNG_SHADER_H
#define OPENGL_CLION_TNG_SHADER_H

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <GL/glew.h>


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif //OPENGL_CLION_TNG_SHADER_H
