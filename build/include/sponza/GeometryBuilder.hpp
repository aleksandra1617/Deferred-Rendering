#pragma once

#include "sponza_fwd.hpp"
#include <string>
#include <vector>

namespace sponza {

class GeometryBuilder
{
public:

    GeometryBuilder();

    ~GeometryBuilder();

    const std::vector<Mesh>& getAllMeshes() const;

    const Mesh& getMeshById(MeshId id) const;

private:

    bool readFile(std::string filepath);

    std::vector<Mesh> meshes_;

};

} // end namespace sponza
