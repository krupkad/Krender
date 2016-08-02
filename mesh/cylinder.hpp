#ifndef CYLINDER_H
#define CYLINDER_H

#include <mesh/object.hpp>

class Cylinder : public Object {
  public:
    Cylinder();
    virtual ~Cylinder();
    virtual glm::vec3 sample();

  private:
    virtual  bool doIntersect(const Ray& ray,Intersection& ix);
    void buildObject();
    float radius_;
    float height_;
};

#endif
