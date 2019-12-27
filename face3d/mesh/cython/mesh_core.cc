/*
Functions that can not be optimized by vectorization in Python.
1. Rasterization. (need process each triangle)
2. Normal of eact vertex. (use one-ring, need process each vertex)
3. Write obj
Reference:
https://github.com/YadiraF/face3d/blob/master/face3d/mesh/cython/mesh_core.cpp
*/
#include "mesh_core.h"

// Judge whether the point is in the triangle
// http://blackpawn.com/texts/pointinpoly
bool IsPointInTri(Point p, Triangle tri) {
  // Vectors
  Point v0 = tri.p2 - tri.p0;
  Point v1 = tri.p1 - tri.p0;
  Point v2 = p - tri.p0;
  double dot00 = v0.Dot(v0);
  double dot01 = v0.Dot(v1);
  double dot02 = v0.Dot(v2);
  double dot11 = v1.Dot(v1);
  double dot12 = v1.Dot(v2);
  // Compute barycentric coordinates
  if (dot00 * dot11 - dot01 * dot01 == 0) {
    return true;
  }
  double inverDeno = 1 / (dot00 * dot11 - dot01 * dot01);
  double u = (dot11 * dot02 - dot01 * dot12) * inverDeno;
  double v = (dot00 * dot12 - dot01 * dot02) * inverDeno;

  return ((u >= 0) && (v >= 0) && (u + v < 1));
}
