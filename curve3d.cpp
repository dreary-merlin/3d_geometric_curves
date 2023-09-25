#include "curve3d.h"
Curve3D::Curve3D(const Point3D& _center) :center(_center) 
{
}
void Curve3D::print() const {
	std::cout << "x: " << center.x << "\ty: " << center.y << "\tz: " << center.z << std::endl;
}
Curve3D::~Curve3D(){}