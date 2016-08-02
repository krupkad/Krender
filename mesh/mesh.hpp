#ifndef MESH_H
#define MESH_H

#include <mesh/object.hpp>

#include <kdtree.hpp>

class Mesh : public Object {
  public:
    Mesh();
    Mesh(std::string objFile);

    void loadObj(std::string objFile);
    virtual glm::vec3 sample();
  protected:
    bool triIx(const Ray& ray, unsigned int i,Intersection& ix);
    virtual bool doIntersect(const Ray& ray, Intersection& ix);
    bool boxIx(Ray ray, const glm::mat4& T);
    bool sphereIx(const Ray& ray);
    glm::vec3 vMin,vMax;
    KDNode *tree;
    float totArea;
    std::vector<float> areas;
};

#endif /* MESH_H */
