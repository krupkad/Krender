#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include <shader.hpp>
#include <conf.hpp>

struct Ray {
  Ray(glm::vec3 p0, glm::vec3 dir, int iter, bool out) :
    p0(p0),
    dir(dir),
    invDir(1.0f/dir),
    iter(iter),
    outside(out),
    tx(1,1,1),
    diffuse(false) {}
  Ray() :
    p0(0),
    dir(0),
    iter(0),
    outside(true),
    tx(1,1,1),
    diffuse(false) {}
  glm::vec3 p0, dir, invDir;
  int iter;
  bool outside, diffuse;
  glm::vec3 tx;
};

struct Intersection {
  Intersection() : t(-1), mat(NULL) {}
  // The parameter `t` along the ray which was used. (A negative value indicates no intersection.)
  float t;
  // The surface normal at the point of intersection. (Ignored if t < 0.)
  glm::vec3 normal;
  MatConf *mat;
  glm::vec3 pos;
};

// A base class for objects in the scene graph.
class Object : public GLEntity {
  public:
    Object();
    virtual ~Object();

    virtual void draw(Shader* shader);
    virtual void bind(Shader *shader);
    virtual void unbind(Shader *shader);

    virtual glm::vec3 sample() = 0;
    bool intersect(const glm::mat4& locModel, const glm::mat4& locModelInv,
                    const Ray& ray, Intersection& ix);

  protected:
    virtual bool doIntersect(const Ray& ray, Intersection &ix) = 0;
    void uploadVBO();

    std::vector<glm::vec3> vtx;        // vertex buffer
    std::vector<glm::vec3> nrm;         // normal buffer
    std::vector<glm::vec2> tex;
    std::vector<unsigned int> idx;      // index buffer
    float *data;

    unsigned int vboData, vboIdx;
    int sso_vtx,sso_nrm,sso_tex;
};

#endif /* GEOMETRY_H */
