#include <iostream>
#include <utility>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#define STB_IMAGE_IMPLEMENTATION
#include "src/stb_image.h"

void handle(const aiScene* scene) {
    for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[i];
        // 顶点数据
        for (int j = 0; j < mesh->mNumVertices; ++j) {
            std::cout << mesh->mVertices[j].x << ',' << mesh->mVertices[j].y << ',' << mesh->mVertices[j].z << std::endl;
            // mesh->mVertices[j]; // position
            // mesh->mNormals[j] // normal
            // mesh->HasVertexColors(i);
            // mesh->mColors[i][j] // vcolor
            // mesh->mTextureCoords[j] // TextureCoords
        }
        // 面数据
        for (int j = 0; j < mesh->mNumFaces; ++j) {
            aiFace face = mesh->mFaces[j];
            for (int k = 0; k < face.mNumIndices; ++k) {
                // face.mIndices[k]; // 面数据
            }
        }
        break;
    }

    // 材质
    // std::cout << scene->mNumMaterials << std::endl;
    // for (unsigned int i = 0; i < scene->mNumMaterials; ++i) {
    //     aiMaterial* material = scene->mMaterials[i];
    //
    //     std::cout << material->GetName().C_Str() << std::endl;
    //
    //     enum aiTextureType s;
    //     for (s = aiTextureType_NONE; s <= aiTextureType_GLTF_METALLIC_ROUGHNESS; s= (aiTextureType)(s + 1))
    //     {
    //         aiString none_path;
    //         material -> GetTexture(s, 0, &none_path);
    //         std::cout << none_path.C_Str() << std::endl;
    //     }
    //
    // }


}

bool DoTheImportThing( const std::string& pFile) {
    // Create an instance of the Importer class
    Assimp::Importer importer;

    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll
    // probably to request more postprocessing than we do in this example.
    const aiScene* scene = importer.ReadFile( pFile,
      aiProcess_CalcTangentSpace       |
      aiProcess_Triangulate            |
      aiProcess_JoinIdenticalVertices  |
      aiProcess_SortByPType);

    // If the import failed, report it
    if (nullptr == scene) {
        std::cout << importer.GetErrorString();
        return false;
    }

    // Now we can access the file's contents.
    handle(scene);

    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}

void loadPic() {
    int width, height, nrComponents;
    unsigned char *data = stbi_load("/Users/huangkaicheng/CLionProjects/openGL/backpack/diffuse.jpg",
                              &width, &height, &nrComponents, 0);
    std::cout << data;
}



int main(int argc, char *argv[]) {
    // DoTheImportThing("/Users/huangkaicheng/CLionProjects/openGL/Survival_BackPack_2/Survival_BackPack_2.fbx");
    loadPic();
}

