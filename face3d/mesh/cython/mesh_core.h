#ifndef __MESH_CORE_H__
#define __MESH_CORE_H__
#include "point.h"
#include "triangle.h"

// Judge whether the point is in the triangle
// http://blackpawn.com/texts/pointinpoly
bool IsPointInTri(Point p, Triangle tri);

void GetPointWeight(double* weight, Point p, Point p0, Point p1, Point p2);

#endif