#include <thread>
#include <string>
#include <iostream>
#include <math.h>
#include <GLFW/glfw3.h>
#include "MuSoenMath.h"


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;  //FPS�� ��� ���� ó�� �ð� ����Ʈ ������ �����̸�
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    Vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    Mat3 translate;
    Mat3 scale;
    Mat3 rotation;
    Mat3 fm;
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� ��

Transform transform;  //world ����� �� transform


float scaleSize = 1.0f;
float scaleNum = 0.01f;
float translateNum = 0.001f;
float rotationNum = 1.0f;
bool isScaling = true;



void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();

    //object������
     /// Star(������) ����
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {
        star[i].pos.vec3[0][0] = -sin(radians(theta)) * 0.5f;
        star[i].pos.vec3[0][1] = cos(radians(theta)) * 0.5f;
        star[i].pos.vec3[0][2] = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;

        transformedStar[i] = star[i];

        i++;

    }

    // �� ����
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.vec3[0][0] = -sin(radians(theta)) * 0.5f;
        circle[theta].pos.vec3[0][1] = cos(radians(theta)) * 0.5f;
        circle[theta].pos.vec3[0][2] = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }

    transform.translate.Identity();
    transform.rotation = Mat3(
        cos(radians(0.0f)), sin(radians(0.0f)), 0,
        -sin(radians(0.0f)), cos(radians(0.0f)), 0,
        0, 0, 1
    );
    transform.scale.Identity();
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        transform.rotation = Mat3(
            cos(radians(rotationNum)), -sin(radians(rotationNum)), 0,
            sin(radians(rotationNum)), cos(radians(rotationNum)), 0,
            0, 0, 1);                   //��ü ȸ��

        rotationNum += 1;

        if (isScaling)
        {
            transform.scale = Mat3(
                scaleSize, 0, 0,
                0, scaleSize, 0,
                0, 0, 1
            );
            scaleSize += scaleNum;
            if (scaleSize >= 1.3f) isScaling = false;
        }
        else if (!isScaling)
        {
            transform.scale = Mat3(
                scaleSize, 0, 0,
                0, scaleSize, 0,
                0, 0, 1
            );
            scaleSize -= scaleNum;
            if (scaleSize <= 0.7f) isScaling = true;
        }                             //��ü ũ�⺯ȯ..


        transform.translate = Mat3(
            1, 0, 0,
            0, 1, 0,
            translateNum, 0, 1
        );                            //��ü �̵�..

        translateNum += 0.001f;


        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = circle[i].pos * transform.rotation * transform.scale * transform.translate;
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * transform.rotation * transform.scale * transform.translate;
        }



        //�� �ʱ�ȭ
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //���β�
        glLineWidth(7.0f);
        //������ �׸���
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec3[0][0], transformedStar[a].pos.vec3[0][1], 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec3[0][0], transformedStar[a].pos.vec3[0][1], 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec3[0][0], transformedStar[a].pos.vec3[0][1], 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec3[0][0], transformedStar[a].pos.vec3[0][1], 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec3[0][0], transformedStar[a].pos.vec3[0][1], 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec3[0][0], transformedStar[a].pos.vec3[0][1], 0.0f);
        glEnd();

        //���׸���
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.vec3[0][0], transformedCircle[theta].pos.vec3[0][1], 0.0f);
        }
        glEnd();



        //ȭ�� ����
        glfwSwapBuffers(window);
        glfwPollEvents();

        //�����ð� ����
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;
    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}