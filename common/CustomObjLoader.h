//
// Created by Admin on 27.12.2018.
//

#ifndef OPENGL_CLION_TNG_CUSTOMOBJLOADER_H
#define OPENGL_CLION_TNG_CUSTOMOBJLOADER_H

#include <vector>
#include <string>
#include <cstring>
#include <fstream>

#include <glm/glm.hpp>


bool loadOBJ(const char * path,
        std::vector<glm::vec3> & out_vertices,
        std::vector<glm::vec2> & out_uvs,
        std::vector<glm::vec3> & out_normals);


#endif //OPENGL_CLION_TNG_CUSTOMOBJLOADER_H
