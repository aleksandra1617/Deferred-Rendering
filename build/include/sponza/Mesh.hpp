#pragma once

#include "sponza_fwd.hpp"
#include <vector>

namespace sponza {

class Mesh
{
public:
    Mesh(MeshId i);

    MeshId getId() const;

    bool isStatic() const { return true; }

    const std::vector<Vector3>& getPositionArray() const;

    const std::vector<Vector3>& getNormalArray() const;

    const std::vector<Vector3>& getTangentArray() const;

    const std::vector<Vector2>& getTextureCoordinateArray() const;

    const std::vector<unsigned int> getElementArray() const;

    void assignPositionArray(std::vector<Vector3>&& p);
    void assignNormalArray(std::vector<Vector3>&& n);
    void assignTangentArray(std::vector<Vector3>&& t);
    void assignTextureCoordinateArray(std::vector<Vector2>&& t);
    void assignElementArray(std::vector<unsigned int>&& e);


private:
    MeshId id;
    std::vector<Vector3> position_array;
    std::vector<Vector3> normal_array;
    std::vector<Vector3> tangent_array;
    std::vector<Vector2> texcoord_array;
    std::vector<unsigned int> element_array;

};

} // end namespace sponza
