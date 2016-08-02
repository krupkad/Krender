#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <glm/glm.hpp>

#define vec2Type typename glm::tvec2<T,P>
#define vec3Type typename glm::tvec3<T,P>
#define vec4Type typename glm::tvec4<T,P>

template <typename T, glm::precision P>
std::ostream& operator<<(std::ostream& os, const vec3Type& vec) {
  os << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")";
  return os;
}

template <typename T, glm::precision P>
std::istream& operator>>(std::istream& is, vec3Type& vec) {
  is >> vec[0];
  is >> vec[1];
  is >> vec[2];
  return is;
}

template <typename T, glm::precision P>
std::ostream& operator<<(std::ostream& os, const vec4Type& vec) {
  os << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] << ")";
  return os;
}

template <typename T, glm::precision P>
std::ostream& operator<<(std::ostream& os, const vec2Type& vec) {
  os << "(" << vec[0] << ", " << vec[1] << ")";
  return os;
}

template <typename T, glm::precision P>
std::istream& operator>>(std::istream& is, vec4Type& vec) {
  is >> vec[0];
  is >> vec[1];
  is >> vec[2];
  is >> vec[3];
  return is;
}

template <typename T, glm::precision P>
std::istream& operator>>(std::istream& is, vec2Type& vec) {
  is >> vec[0];
  is >> vec[1];
  return is;
}

template <typename T, glm::precision P>
vec3Type::bool_type operator>(const vec3Type& v1, T x) {
  return glm::greaterThan(v1,vec3Type(x));
}


template <typename T, glm::precision P>
vec3Type::bool_type operator<(const vec3Type& v1, T x) {
  return glm::lessThan(v1,vec3Type(x));
}

void printGLErrorLog();

#endif /* UTIL_H */
