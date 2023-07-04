#include <pd-engine/pd.h>

// Standard libraries
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// Global variables

// set up camera
glm::vec3 cameraPos      = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront    = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp       = glm::vec3(0.0f, 1.0f,  0.0f);

// time variables
float deltaTime = 0.0f;
float lastFrame = 0.0f;
		
bool firstMouse = true;
float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch =  0.0f;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;
float fov   =  45.0f;


GLFWwindow* InitWindow()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window = glfwCreateWindow( SCR_WIDTH, SCR_HEIGHT, "PD Engine", NULL, NULL);
    if( window == NULL ){
        std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
        return nullptr;

    }
    glfwMakeContextCurrent(window);

		// Set callbacks
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwSetCursorPosCallback(window, mouse_callback);
		
		// Disable cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
  // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

		// Enable z-buffer
		GLCall( glEnable(GL_DEPTH_TEST) );

    std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    return window;
}

int main( void )
{
    GLFWwindow* window = InitWindow();
    if (!window)
        return -1;
    
    Level* mainLevel = new Level();
    GameObject* cube1 = new GameObject(glm::vec3(2.0f, 2.0f, -2.0f));
		GameObject* cube2 = new GameObject(glm::vec3(0.0f, 0.0f, 0.0f));

    mainLevel->AddGameObject(cube1);
		mainLevel->AddGameObject(cube2);

    // This is where we run all of the Awake() functions
    mainLevel->Awake();

    float positions[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  // A 0
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  // B 1
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  // C 2
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  // D 3
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  // E 4
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   // F 5
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,   // G 6
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,   // H 7
 
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,  // D 8
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  // A 9
        -0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  // E 10
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  // H 11
        0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   // B 12
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,   // C 13
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,   // G 14
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f,   // F 15
 
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  // A 16
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,   // B 17
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,   // F 18
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  // E 19
        0.5f,  0.5f, -0.5f,   0.0f, 0.0f,  // C 20
        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  // D 21
        -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  // H 22
        0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  // G 23
    }; 

    unsigned int indices[] = {
        // front and back
        0, 3, 2,
        2, 1, 0,
        4, 5, 6,
        6, 7 ,4,
        // left and right
        11, 8, 9,
        9, 10, 11,
        12, 13, 14,
        14, 15, 12,
        // bottom and top
        16, 17, 18,
        18, 19, 16,
        20, 21, 22,
        22, 23, 20
    }; 	

    GLCall( glEnable(GL_BLEND) );
    GLCall( glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) );

    {
        MeshRenderer *mesh = new MeshRenderer(positions, indices, sizeof(positions), 36);
        cube2->AddComponent(mesh);
        mesh->AttachTransform(cube2->transform);
    
        do {	
						// Calculate time 
						float currentFrame = glfwGetTime();
        		deltaTime = currentFrame - lastFrame;
        		lastFrame = currentFrame;
						
						// Input
						processInput(window);

						GLCall( glClearColor(0.2f, 0.3f, 0.3, 1.0f) );
            // Update()
            mainLevel->Update();

            // create transformations
            glm::mat4 view          = glm::mat4(1.0f);
            glm::mat4 projection    = glm::mat4(1.0f);
       		  
            view  = glm::lookAt(
              cameraPos, //camera position
              cameraPos + cameraFront, // target
              cameraUp // up vector in world space for calculating right vector 
            );

            projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

          	//renderer.Draw(mainLevel, va, ib, shader);
            mesh->Draw(view, projection);
            // Swap buffers
            glfwSwapBuffers(window);
            glfwPollEvents();

        } while(!glfwWindowShouldClose(window)); 
    } 
    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    const float speed = 2.5f * deltaTime;

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
      cameraPos += speed * cameraFront;
    }

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
      cameraPos -= speed * cameraFront;
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
      cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
    }

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
      cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
    }

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// uses mouse to control camera
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
  
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
} 

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
