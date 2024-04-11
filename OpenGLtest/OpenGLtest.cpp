// OpenGLtest.cpp: 定义应用程序的入口点。
//

#include <glad/glad.h>
#include "gl/GL.h"
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;

float vertices1[] = {
    -0.8f, -0.8f, 0.0f,  1.0f, 0.0f, 0.0f, // 右下角
    -0.8f, 0.8f, 0.0f, 0.0f, 1.0f, 0.0f, // 左下角
    0.8f, 0.8f, 0.0f , 0.0f, 0.0f, 1.0f,  // 左上角
    0.8f, -0.8f, 0.0f , 0.0f, 0.0f, 1.0f  // 左上角
};
float vertices36[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

float vertices3[] = {
    //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   3.0f, 3.0f,   // 右上
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   3.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 3.0f    // 左上
};
float vertices2[] = {
    0.8f, -0.8f, 0.0f,   // 右上角
    0.0f, -0.8f, 0.0f,  // 右下角
    0.4f, 0.5f, 0.0f   // 左上角
};
glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f),
    glm::vec3( 2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f,  2.0f, -2.5f),
    glm::vec3( 1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};
glm::vec3 cubeRoates[] = {
    glm::vec3( 1.0f,  1.0f,  1.0f),
    glm::vec3( 2.0f,  5.0f, -1.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -1.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f,  2.0f, -2.5f),
    glm::vec3( 1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};
unsigned int indices[] = {
    // 注意索引从0开始!
    // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
    // 这样可以由下标代表顶点组合成矩形

    0, 1, 3, // 第一个三角形
    1, 2, 3  // 第二个三角形
};
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "layout (location = 1) in vec3 aColor;\n"
                                 "out vec4  verctcolor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "   verctcolor = vec4(aColor,1.0);\n"
                                 "}\0";
const char *fragmentShaderSource =  "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "in vec4 verctcolor;\n"
                                    "void main()\n"
                                    "{\n"
                                        //"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                    "   FragColor = verctcolor;\n"
                                    "}\0";
const char *fragmentShaderSourceyellow =  "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "uniform vec4 ourColor;\n" // 在OpenGL程序代码中设定这个变量
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = ourColor;\n"
                                   "}\0";



glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  16.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -3.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间
float lastX = 400, lastY = 300; //鼠标初始位置
float yaw = 0.0f, pitch = 0.0f;
float fov = 45.0f;
bool firstMouse = true;
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//键盘按键处理函数
void processInput(GLFWwindow* window)
{
    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

//鼠标回调函数
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.05f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}
//缩放回调函数
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if(fov >= 1.0f && fov <= 45.0f)
        fov -= yoffset;
    if(fov <= 1.0f)
        fov = 1.0f;
    if(fov >= 45.0f)
        fov = 45.0f;
}
int main()
{
    cout << "Hello CMake." << endl;

    //glfw初始化
    float screenwidth = 800;
    float screenheight = 600;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //版本号 前数字
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //版本号 后数字   3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //模式选择，核心渲染模式

    //创建一个窗口对象
    GLFWwindow* window = glfwCreateWindow(screenwidth, screenheight, "LearnOpenGL", NULL, NULL);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //隐藏鼠标，并捕捉鼠标移动量
    glfwSetCursorPosCallback(window, mouse_callback);//注册鼠标回调函数
    glfwSetScrollCallback(window, scroll_callback);//注册鼠标滚轮函数
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //初始化GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //注册窗口大小回调函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    //定点输入
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    unsigned int VAO2;
    glGenVertexArrays(1, &VAO2);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    unsigned int VBO2;
    glGenBuffers(1, &VBO2);


    unsigned int EBO;
    glGenBuffers(1, &EBO);

    Shader shader1(":/shader_vs.glsl", ":/shader_fs.glsl");
    Shader shader2(":/shader_vs.glsl", ":/shader_fs2.glsl");

#if 0
    //定点着色器
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); //添加
    glCompileShader(vertexShader); //编译

    //编译成功检测
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    //片段着色器
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //片段着色器
    unsigned int fragmentShadery;
    fragmentShadery = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShadery, 1, &fragmentShaderSourceyellow, NULL);
    glCompileShader(fragmentShadery);


    //着色器程序
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    //着色器程序
    unsigned int shaderProgramy;
    shaderProgramy = glCreateProgram();
    glAttachShader(shaderProgramy, vertexShader);
    glAttachShader(shaderProgramy, fragmentShadery);
    glLinkProgram(shaderProgramy);

    //检测连接着色器是否成功
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    else
    {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glDeleteShader(fragmentShadery);
    }
#endif
    //创建纹理
    unsigned int texture = 0;
    unsigned int texture2 = 0;
    glGenTextures(1, &texture);
    glGenTextures(1, &texture2);


    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 加载并生成纹理
    stbi_set_flip_vertically_on_load(true);//纹理Y轴旋转
    int width, height, nrChannels;
    //load纹理之前要先激活
    glActiveTexture(GL_TEXTURE0);
    //然后绑定纹理
    glBindTexture(GL_TEXTURE_2D, texture);
    //然后load纹理图片
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    //load纹理之前要先激活
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    unsigned char *data2 = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
    if (data2)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    stbi_image_free(data2);
    //查看定点属性数量
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
    // 0. 复制顶点数组到缓冲中供OpenGL使用
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //// 1. 设置顶点属性指针
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    //// 2. 当我们渲染一个物体时要使用着色器程序
    //glUseProgram(shaderProgram);
    // 3. 绘制物体
    //someOpenGLFunctionThatDrawsOurTriangle();

    Shader shader3(":/shader_vs3.glsl", ":/shader_fs3.glsl");


    // 1. 绑定VAO
    glBindVertexArray(VAO);
    //glBindVertexArray(VAO);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // 2. 把顶点数组复制到缓冲中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices36), vertices36, GL_STATIC_DRAW);
    // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // 3. 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 颜色属性
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    //glEnableVertexAttribArray(1);
    //纹理属性
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // 2. 把顶点数组复制到缓冲中供OpenGL使用
    // 1. 绑定VAO2
    //glBindVertexArray(VAO2);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    shader3.use(); // 不要忘记在设置uniform变量之前激活着色器程序！
    //glUniform1i(glGetUniformLocation(shader3.ID, "texture1"), 0); // 手动设置
    shader3.setInt("texture1", 0); // 或者使用着色器类设置
    shader3.setInt("texture2", 1); // 或者使用着色器类设置
    //设置绘图模式是否是填充
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    float opcity = 0.2;


    //glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    // 译注：下面就是矩阵初始化的一个例子，如果使用的是0.9.9及以上版本 需要初始化
    // 下面这行代码就需要改为:
    //glm::mat4 trans = glm::mat4(1.0f);
    // 之后将不再进行提示
    //glm::mat4 trans;
    //trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    //trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    //unsigned int transformLoc = glGetUniformLocation(shader3.ID, "transform");
    //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));




    // 渲染循环
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        // 输入
        processInput(window);
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS )
        {
            opcity -= 0.0001;
            if (opcity < 0.00001)
            {
                opcity = 0.0;
            }
            std::cout << "opcity GLFW_KEY_DOWN= " << opcity<< std::endl;
        }
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS )
        {
            opcity += 0.0001;
            if (opcity > 1.00001)
            {
                opcity = 1.0;
            }
            std::cout << "opcity GLFW_KEY_UP = " << opcity<< std::endl;
        }
        shader3.setFloat2("opticety", opcity,1.0);
        // 渲染指令
        //....
        glm::mat4 trans = glm::mat4(1.0f);
        ///旋转变化命令
        //trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        //trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        //unsigned int transformLoc = glGetUniformLocation(shader3.ID, "transform");
        //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

        glEnable(GL_DEPTH_TEST);

        //glm::mat4 model = glm::mat4(1.0f);
        ////model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));;
        //int modelLoc = glGetUniformLocation(shader3.ID, "model");
        //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //矩阵可以放到循环外面，如果需要变化，则放到循环里面
        //投影矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        //projection = glm::perspective(glm::radians(60.0f), 4.0f / 3.0f, 0.1f, 100.0f);
        projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);//鼠标缩放控制的是投影矩阵
        int modelLocp = glGetUniformLocation(shader3.ID, "projection");
        glUniformMatrix4fv(modelLocp, 1, GL_FALSE, glm::value_ptr(projection));

        //观察矩阵
        glm::mat4 view = glm::mat4(1.0f);
        //// 注意，我们将矩阵向我们要进行移动场景的反方向移动。
        ////view = glm::translate(view, glm::vec3(0.0f, 0.0f, -9.0f));  //x, y, z, 右手坐标系
        //float radius = 10.0f;
        //float camX = sin(glfwGetTime()) * radius;
        //float camZ = cos(glfwGetTime()) * radius;

        //view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        int modelLocv = glGetUniformLocation(shader3.ID, "view");
        glUniformMatrix4fv(modelLocv, 1, GL_FALSE, glm::value_ptr(view));


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //模型矩阵
        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);//初始化每个立方体的模型坐标
            //float angle = 20.0f * i;
            model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), cubeRoates[i]);//设置每个模型立方体自身的旋转
            int modelLoc = glGetUniformLocation(shader3.ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glDrawArrays(GL_TRIANGLES, 0, 36); //glDrawArray 函数在glclear 之后调用 //每个立方体都有36个点
        }

        //glUseProgram(shaderProgram);
        //shader3.use();
        //glBindTexture(GL_TEXTURE_2D, texture);
        //glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, texture);
        //glActiveTexture(GL_TEXTURE1);
        //glBindTexture(GL_TEXTURE_2D, texture2);
        //glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        //glDrawArrays(GL_TRIANGLES, 0, 36);
        //glBindVertexArray(0);
        //glUseProgram(shaderProgramy);
        //// 更新uniform颜色
        //double timeValue = glfwGetTime();
        //float greenValue = abs(sin(timeValue) / 2.0f + 0.5f);
        //shader2.use();
        //shader2.setFloat4("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
        ////int vertexColorLocation = glGetUniformLocation(shaderProgramy, "ourColor");
        ////glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        //glBindVertexArray(VAO2);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0);

        // 检查并调用事件，交换缓冲
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    //释放资源
    glfwTerminate();
	return 0;
}
