#ifndef CUBE_H
#define CUBE_H

#include <mesh/object.hpp>

class Cube : public Object {
  public:
    Cube();
    virtual ~Cube();

    virtual glm::vec3 sample();

  protected:
    virtual bool doIntersect(const Ray& ray,Intersection& ix);
    void buildObject();

    float len;
};

#endif
