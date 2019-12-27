#ifndef __POINT_H__
#define __POINT_H__

struct Point {
  double x;
  double y;

  double Dot(Point p);
  Point operator-(const Point& p);
  Point operator+(const Point& p);
  Point operator*(double s);
};

#endif  // __POINT_H__
