#ifndef NODE_H
#define NODE_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <mesh/object.hpp>
#include <mesh/cube.hpp>
#include <mesh/cylinder.hpp>
#include <mesh/sphere.hpp>
#include <shader.hpp>
#include <conf.hpp>
#include <texture.hpp>

#include <string>
#include <iostream>
#include <deque>
#include <set>

class Scene;
class Node {
  public:
    Node(std::string name);
    Node(std::string name, Object *m);
    Node(const NodeConf& conf);
    Node(const NodeConf& conf, Object *m);
    ~Node();

    void addChild(Node *n);
    void delChild(Node *n);

    void addShader(Shader *s);
    void delShader(Shader *s);

    void bindTexture(Texture *tex);
    void unbindTexture();

    void bindMaterial(MatConf *mat);

    void draw(Shader *shader);
    void buildPreOrder(std::deque<std::string>& vec);

    void translate(glm::vec3 dv);
    void rotate(glm::vec3 dv);
    void scale(glm::vec3 dv);
    void center(const glm::vec3& v);

    Intersection raytrace(const Ray& ray);

    void sample(Intersection& ix) const;

  protected:
    glm::mat4 getLocalModel() const;
    bool raytrace(const Ray& ray, Intersection& ix);
    void updateLocalModel();

    Node *parent;
    std::vector<Node*> children;
    Object *geometry;
    glm::vec3 tx,rot,sc,ctr;
    std::string name;

    std::set<Shader*> shaders;
    Texture *tex;
    MatConf *mat;

    glm::mat4 localModel, localModelInv;
};

#endif /* NODE_H */
