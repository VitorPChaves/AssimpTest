#include <Shader.h>

class Things {
	private:
		unsigned int cubeVAO, cubeVBO;
		unsigned int floorVAO, floorVBO;
		unsigned int cubeTexture = initTextures("C:/Users/Vitor/Documents/AdvancedOpenGL/images/marble2.jpg");
		unsigned int floorTexture = initTextures("C:/Users/Vitor/Documents/AdvancedOpenGL/images/metal.jpg");

	public:
		~Things();

		void initBuffers();

		int initTextures(char* const path);

		void drawCube(Shader* shader);

		void drawFloor(Shader* shader);

};