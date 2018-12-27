#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "common/shader.h"
#include "common/loadDDS.h"

GLFWwindow* window;

using namespace glm;

int main() {

    if (!glfwInit()){
        std::cout << "glfw not init" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow( 1024, 768, "OpenGL_clion", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "not open glfw window" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "not initialize GLEWn");
        return -1;
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    GLuint programID = LoadShaders("shaders/VertexShader.vertexshader", "shaders/FragmentShader.fragmentshader");
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    mat4 Projection = perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    mat4 View = lookAt(
            glm::vec3(-4, 3, -3), // Камера находится в мировых координатах (4,3,3)
            glm::vec3(0, 0, 0), // И направлена в начало координат
            glm::vec3(0, 1, 0)  // "Голова" находится сверху
    );
    mat4 Model = mat4(1.0f);
    mat4 MVP = Projection * View * Model;

    GLuint Texture = loadDDS("uvtemplate.DDS");
    GLuint TextureID = glGetUniformLocation(programID, "texSampler");

    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
    };

    static const GLfloat g_uv_buffer_data[] = {
            0.000059f, 0.000004f,
            0.000103f, 0.336048f,
            0.335973f, 0.335903f,
            1.000023f, 0.000013f,
            0.667979f, 0.335851f,
            0.999958f, 0.336064f,
            0.667979f, 0.335851f,
            0.336024f, 0.671877f,
            0.667969f, 0.671889f,
            1.000023f, 0.000013f,
            0.668104f, 0.000013f,
            0.667979f, 0.335851f,
            0.000059f, 0.000004f,
            0.335973f, 0.335903f,
            0.336098f, 0.000071f,
            0.667979f, 0.335851f,
            0.335973f, 0.335903f,
            0.336024f, 0.671877f,
            1.000004f, 0.671847f,
            0.999958f, 0.336064f,
            0.667979f, 0.335851f,
            0.668104f, 0.000013f,
            0.335973f, 0.335903f,
            0.667979f, 0.335851f,
            0.335973f, 0.335903f,
            0.668104f, 0.000013f,
            0.336098f, 0.000071f,
            0.000103f, 0.336048f,
            0.000004f, 0.671870f,
            0.336024f, 0.671877f,
            0.000103f, 0.336048f,
            0.336024f, 0.671877f,
            0.335973f, 0.335903f,
            0.667969f, 0.671889f,
            1.000004f, 0.671847f,
            0.667979f, 0.335851f
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    glClearColor(0.4f, 0.5f, 0.4f, 0.5f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glUniform1i(TextureID, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
                3,                  // Размер
                GL_FLOAT,           // Тип
                GL_FALSE,           // Указывает, что значения не нормализованы
                0,                  // Шаг
                (void*)0            // Смещение массива в буфере
        );

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
                1,                                // Атрибут. Здесь необязательно указывать 1, но главное, чтобы это значение совпадало с layout в шейдере..
                2,                                // Размер
                GL_FLOAT,                         // Тип
                GL_FALSE,                         // Нормализован?
                0,                                // Шаг
                (void*)0                          // Смещение
        );

        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

    return 0;
}
