#pragma once
#include "curve3d.h"
class Ellipse3D : public Curve3D {
public:
	Ellipse3D(const Point3D& _center, double _radius_x, double _radius_y);
	~Ellipse3D() override;
	Point3D get_point(double t) const override;
	Vector3D get_first_derivative(double t) const override;
private:
	double radius_x;
	double radius_y;
};