#pragma once

#include "sponza_fwd.hpp"

namespace sponza {

class DirectionalLight
{
public:
    DirectionalLight(LightId);

    LightId getId() const;

    bool isStatic() const;
    void setStatic(bool);

    Vector3 getDirection() const;
    void setDirection(Vector3 d);

    Vector3 getIntensity() const;
    void setIntensity(Vector3 i);

private:
    Vector3 direction{ 0, 0, -1 };
    bool is_static{ true };
    Vector3 intensity{ 0.1f, 0.1f, 0.1f };
    LightId id;

};

} // end namespace sponza
