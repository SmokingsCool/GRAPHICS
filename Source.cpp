#include <Windows.h>
#include <iostream>
#include "Game.h"
// GLEW
//#define GLEW_STATIC
// GLFW
#include <glfw3.h>

#include <gl\GL.h>
#include <gl\GLU.h>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
Game gameObject = Game(WIDTH,HEIGHT);

// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    glfwInit();

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

   

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);
	gameObject.CreateLevel();
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
		
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, WIDTH, 0, HEIGHT);
		glMatrixMode(GL_MODELVIEW);
		gameObject.Run();
		
		//glFlush();
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);}
	else if (action == GLFW_REPEAT){
		if(/*key == GLFW_KEY_LEFT  ||*/ glfwGetKey(window,GLFW_KEY_LEFT)){
			cout << "STILL BEING PRESSED";
			gameObject.moveHoriz(2);
		}
		else if(key == GLFW_KEY_RIGHT ){
			gameObject.moveHoriz(-2);
		}
		else if(key == GLFW_KEY_UP){
			//gameObject.adjustCoord(0,-10);
		}
		else if(key == GLFW_KEY_DOWN ){
			gameObject.adjustCoord(0,10);
		}}
	else if (action == GLFW_PRESS){
		if(key == GLFW_KEY_LEFT ){
			
			gameObject.moveHoriz(1);
			
		}
		else if(key == GLFW_KEY_RIGHT ){
			gameObject.moveHoriz(-1);
		}
		else if(key == GLFW_KEY_UP ){
			gameObject.mainJump();
			//gameObject.adjustCoord(0,-10);
		}
		else if(key == GLFW_KEY_DOWN ){
			//gameObject.adjustCoord(0,10);
		}
	}
}


