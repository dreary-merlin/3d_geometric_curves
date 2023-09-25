#pragma once
#include "curve3d.h"
class Helix3D : public Curve3D {
	static constexpr double round = M_PI * 2.0;
public:
	Helix3D(const Point3D& _center, double _radius, double _step);
	~Helix3D() override;
	Point3D get_point(double t) const override;
	Vector3D get_first_derivative(double t) const override;
private:
	double radius;
	double step;
};