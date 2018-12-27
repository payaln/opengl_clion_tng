//
// Created by Admin on 27.12.2018.
//

#ifndef OPENGL_CLION_TNG_CONTROLS_H
#define OPENGL_CLION_TNG_CONTROLS_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class Controls {

public:
    Controls(GLFWwindow* window);

    const mat4 &getViewMatrix() const;

    const mat4 &getProjectionMatrix() const;

    void computeMatricesFromInputs();

private:
    glm::mat4 ViewMatrix;
    glm::mat4 ProjectionMatrix;
    GLFWwindow* window;


    glm::vec3 position = glm::vec3(0, 0, 5);
    float horizontalAngle = 3.14f;
    float verticalAngle = 0.0f;
    float initialFoV = 45.0f;
    float speed = 8.0f; // 3 units / second
    float mouseSpeed = 2.0f;
};


#endif //OPENGL_CLION_TNG_CONTROLS_H
