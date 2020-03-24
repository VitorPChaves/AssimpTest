
#include <Shader.h>
#include <Model.h>
#include <Camera.h>

GLFWwindow* window = nullptr;

Camera* camera = new Camera;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	camera->mouse_callback(window, xpos, ypos);
}

bool initGL() {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	window = glfwCreateWindow(1024, 768, "Audaces CG Internship Test", NULL, NULL);

	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not OpenGL 3.3 compatible.\n");
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true; // http://glew.sourceforge.net/basic.html
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_BLEND);// you enable blending function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}


int main() {

	if (!initGL()) {
		return -1;
	}

	Shader myShader("C:/Users/Vitor/Documents/AssimpTest/shaders/vs.txt", "C:/Users/Vitor/Documents/AssimpTest/shaders/fs.txt");
	Model crysis("C:/Users/Vitor/Documents/AssimpTest/nanosuit/nanosuit.obj");

	glEnable(GL_DEPTH_TEST);

	do {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera->input(window);

		myShader.use();

		camera->transform(&myShader);


		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		myShader.setMat4("model", model);
		crysis.Draw(myShader);


		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));


	glfwTerminate();

	return 0;
}