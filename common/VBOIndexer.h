//
// Created by Admin on 27.12.2018.
//

#ifndef OPENGL_CLION_TNG_VBOINDEXER_H
#define OPENGL_CLION_TNG_VBOINDEXER_H

#include <vector>
#include <map>
#include <string>

#include <glm/glm.hpp>

void indexVBO(
        std::vector<glm::vec3> & in_vertices,
        std::vector<glm::vec2> & in_uvs,
        std::vector<glm::vec3> & in_normals,

        std::vector<unsigned short> & out_indices,
        std::vector<glm::vec3> & out_vertices,
        std::vector<glm::vec2> & out_uvs,
        std::vector<glm::vec3> & out_normals
);

#endif //OPENGL_CLION_TNG_VBOINDEXER_H
