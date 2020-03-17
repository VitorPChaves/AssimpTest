#include <Shader.h>
#include <vector>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec3 TexCoord;
};

struct Texture {
	unsigned int id;
	std::string type;
};

class Mesh {
	public:
		std::vector<Vertex> vertices;
		std::vector<Texture> textures;
		std::vector<unsigned int> indices;

		Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures, std::vector<unsigned int> indices);
		void Draw(Shader shader);

	private:
		unsigned int VAO, VBO, EBO;
		void setupMesh();
};