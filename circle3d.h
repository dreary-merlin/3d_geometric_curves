#pragma once
#include "curve3d.h"
class Circle3D: public Curve3D{
public:
	Circle3D(const Point3D& _center, double _radius);
	~Circle3D() override;
	Point3D get_point(double t) const override;
	Vector3D get_first_derivative(double t) const override;
	double get_radius() const;
private:
	double radius;
};