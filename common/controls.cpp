//
// Created by Admin on 27.12.2018.
//

#include "controls.h"

const mat4 &Controls::getViewMatrix() const {
    return ViewMatrix;
}

const mat4 &Controls::getProjectionMatrix() const {
    return ProjectionMatrix;
}

Controls::Controls(GLFWwindow *window) : window(window) {

}

void Controls::computeMatricesFromInputs() {

    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastTime;

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    glfwSetCursorPos(window, width/2., height/2.);

    horizontalAngle += mouseSpeed * deltaTime * (width/2. - xpos);
    verticalAngle   += mouseSpeed * deltaTime * (height/2. - ypos);

    glm::vec3 direction(
            cos(verticalAngle) * sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle) * cos(horizontalAngle)
    );
    glm::vec3 right = glm::vec3(
            sin(horizontalAngle - 3.14f/2.0f),
            0,
            cos(horizontalAngle - 3.14f/2.0f)
    );
    glm::vec3 up = glm::cross(right, direction);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        position += direction * float(deltaTime) * speed;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        position -= direction * float(deltaTime) * speed;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        position += right * float(deltaTime) * speed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        position -= right * float(deltaTime) * speed;
    }


    float FoV = initialFoV;// - 5 * glfwGetMouseWheel();

    ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);

    ViewMatrix = glm::lookAt(
            position,           // Позиция камеры
            position + direction, // Направление камеры
            up                  // Вектор "Вверх" камеры
    );

    lastTime = currentTime;
}
