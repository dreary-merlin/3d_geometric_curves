#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
struct Point3D { double x, y, z; };
struct Vector3D { double x, y, z; }; // not every vector is a point
class Curve3D { // base class
public:
	Curve3D(const Point3D& _center);
	void print() const; // print coordinates of center
	virtual ~Curve3D();
	virtual Point3D get_point(double t) const = 0;
	virtual Vector3D get_first_derivative(double t) const = 0;
protected:
	Point3D center;
};