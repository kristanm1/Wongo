#include "Core.h"
#include "Logger.h"

#include <fstream>
#include <unordered_map>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

std::string Wongo::LoadText(std::string const& path)
{
    std::fstream s(path, std::ifstream::in | std::ifstream::binary);
    if (!s.is_open())
    {
        LOG_WARN_CORE("File %s does not exist!", path);
        return {};
    }

    std::streampos pos = s.seekg(0, std::ios::end).tellg();
    if (std::streampos(-1) == pos)
    {
        LOG_WARN_CORE("End of file %s could not be found!", path);
        return {};
    }

    s.seekg(0, std::ios::beg);
    size_t size = static_cast<size_t>(pos);
    std::string src(size, '\0');
    s.read(&src[0], size);

    return src;
}

struct IndexKey
{
    int vertex;
    int normal;
    int texcoord;

    bool operator==(IndexKey const& other) const
    {
        return vertex == other.vertex
            && normal == other.normal
            && texcoord == other.texcoord;
    }
};

struct IndexKeyHash
{
    size_t operator()(IndexKey const& key) const
    {
        size_t h = 0;
        size_t h1 = static_cast<size_t>(key.vertex);
        size_t h2 = static_cast<size_t>(key.normal);
        size_t h3 = static_cast<size_t>(key.texcoord);
        h ^= std::hash<size_t>{}(h1) + 0x9e3779b9 + ((h1) << 6) + (h1 >> 2);
        h ^= std::hash<size_t>{}(h2) + 0x9e3779b9 + ((h2) << 6) + (h2 >> 2);
        h ^= std::hash<size_t>{}(h3) + 0x9e3779b9 + ((h3) << 6) + (h3 >> 2);
        return h;
    }
};

bool Wongo::LoadObj(
    std::string const& assetPath,
    std::string const& objPath,
    std::vector<float>& vertexData,
    std::vector<unsigned int>& indices,
    std::string& texturePath)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string err;
    std::string path = assetPath + objPath;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, path.c_str(), assetPath.c_str(), false);
    if (!ret)
    {
        LOG_WARN_CORE("Loading obj %s from dir %s failed!", objPath.c_str(), assetPath.c_str());
        return false;
    }

    texturePath = assetPath + materials[0].diffuse_texname;

    std::unordered_map<IndexKey, unsigned int, IndexKeyHash> indexMap;
    for (auto const& idx : shapes[0].mesh.indices)
    {
        IndexKey key{ idx.vertex_index, idx.normal_index, idx.texcoord_index };

        auto it = indexMap.find(key);

        if (it != indexMap.end())
        {
            indices.push_back(it->second);
        }
        else
        {
            int index = static_cast<unsigned int>(vertexData.size() / 8);
            indices.push_back(index);
            indexMap[key] = index;

            vertexData.push_back(attrib.vertices[3 * idx.vertex_index]);
            vertexData.push_back(attrib.vertices[3 * idx.vertex_index + 1]);
            vertexData.push_back(attrib.vertices[3 * idx.vertex_index + 2]);

            vertexData.push_back(attrib.normals[3 * idx.normal_index]);
            vertexData.push_back(attrib.normals[3 * idx.normal_index + 1]);
            vertexData.push_back(attrib.normals[3 * idx.normal_index + 2]);

            vertexData.push_back(attrib.texcoords[2 * idx.texcoord_index]);
            vertexData.push_back(attrib.texcoords[2 * idx.texcoord_index + 1]);
        }
    }

    return true;
}
