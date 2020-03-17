#include <Shader.h>
#include <vector>
#include <Mesh.h>

class Model {
	public:
		Model(char* path) {
			loadModel(path);
		}

		void Draw(Shader shader);
	
	private:
		std::vector<Mesh> meshes;

		void loadModel(char* path);
};