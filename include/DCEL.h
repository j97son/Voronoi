#ifndef DCEL_H
#define DCEL_H

// #include <memory>
#include <vector>

struct Vertex {
  double x, y;
  Halfedge* incident;

  Vertex(double x, double y) : x(x), y(y), incident(nullptr) {}
};

struct Halfedge {
  Vertex* origin;
  Halfedge* twin;
  Halfedge* next;
  Halfedge* prev;

  Halfedge(Vertex* origin)
      : origin(origin), twin(nullptr), next(nullptr), prev(nullptr) {}
};

// struct Face {};

class DCEL {
 public:
  std::vector<Vertex*> vertices;
  std::vector<Halfedge*> halfedges;
  // std::vector<Face> faces;

  inline Vertex* add_vertex(double x, double y) {
    Vertex* v = new Vertex(x, y);
    vertices.push_back(v);
    return v;
  }
};

#endif  // DCEL_H
