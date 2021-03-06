#ifndef MESH_H
#define MESH_H
#pragma once


#include <glm/glm.hpp>
#include "Shader.h"

namespace Automata {
	struct Vertex {
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	struct Texture {
		unsigned int id;
		std::string type; // i.e diffuse, specular, etc..
		std::string path; // path of texture
	};
	
	class Mesh
	{
	public:
		std::vector<Vertex> Vertices;
		std::vector<unsigned int> Indices;
		std::vector<Texture> Textures;

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		~Mesh();
		void Draw(Shader& shader);
		void Clean();

		// render data
		unsigned int VAO, VBO, EBO;
	private:
		void setUpMesh();
	};
}
#endif