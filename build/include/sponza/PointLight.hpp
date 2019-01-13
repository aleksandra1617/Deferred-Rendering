#pragma once

#include "sponza_fwd.hpp"

namespace sponza {

class PointLight
{
public:
    PointLight(LightId);

    LightId getId() const;

    bool isStatic() const;
    void setStatic(bool);

    Vector3 getPosition() const;
    void setPosition(Vector3 p);

    float getRange() const;
    void setRange(float r);

    Vector3 getIntensity() const;
    void setIntensity(Vector3 i);

private:
    LightId id;
    Vector3 position{ 0, 0, 0 };
    bool is_static{ false };
    Vector3 intensity{ 0.8f, 0.8f, 1 };
    float range{ 1 };

};

} // end namespace sponza
