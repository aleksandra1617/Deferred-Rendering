#pragma once

#include "sponza_fwd.hpp"

namespace sponza {

class Material
{
public:
    Material(MaterialId i);

    MaterialId getId() const;

    bool isStatic() const { return true; }

    Vector3 getDiffuseColour() const;
    void setDiffuseColour(Vector3 c);

    Vector3 getSpecularColour() const;
    void setSpecularColour(Vector3 c);

    float getShininess() const;
    void setShininess(float s);

    bool isShiny() const;


private:
    MaterialId id;
    Vector3 diffuse_colour;
    Vector3 specular_colour;
    float shininess;

};

} // end namespace sponza
