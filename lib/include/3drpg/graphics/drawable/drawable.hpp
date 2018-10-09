#ifndef RPG_INCLUDED_DRAWABLE
#define RPG_INCLUDED_DRAWABLE

#include <glm/glm.hpp>

namespace rpg {
  class Drawable {
  public:
    Drawable() {}
    virtual ~Drawable() {}

    virtual bool loadModel(const char* file) = 0;
    virtual void setTransform(const glm::mat4& mat) = 0;
    virtual void setAnimation(const char* name) = 0;
    virtual void setAnimationPosition(float pos) = 0;
  };
}

#endif
