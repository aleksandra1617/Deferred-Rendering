#pragma once

#include "sponza_fwd.hpp"

namespace sponza {

class SpotLight
{
public:
    SpotLight(LightId);

    LightId getId() const;

    bool isStatic() const;
    void setStatic(bool);

    Vector3 getPosition() const;
    void setPosition(Vector3 p);

    Vector3 getDirection() const;
    void setDirection(Vector3 d);

    float getConeAngleDegrees() const;
    void setConeAngleDegrees(float a);

    float getRange() const;
    void setRange(float r);

    Vector3 getIntensity() const;
    void setIntensity(Vector3 i);

    bool getCastShadow() const;
    void setCastShadow(bool);

private:
    Vector3 position{ 0, 0, 0 };
    float range{ 1 };
    Vector3 direction{ 0, 0, -1 };
    float cone_angle_degrees{ 45 };
    Vector3 intensity{ 1, 1, 0.8f };
    bool is_static{ false };
    bool cast_shadow{ true };
    LightId id;

};

} // end namespace sponza
