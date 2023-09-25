#include "ellipse3d.h"
Ellipse3D::Ellipse3D(const Point3D& _center, double _radius_x, double _radius_y) :Curve3D(_center), radius_x{ std::fabs(_radius_x) }, radius_y{ std::fabs(_radius_y) }
{
}
Ellipse3D::~Ellipse3D() 
{
}
Point3D Ellipse3D::get_point(double t) const 
{
	return Point3D{ center.x + radius_x*std::cos(t), center.y + radius_y*std::sin(t), center.z };
}
Vector3D Ellipse3D::get_first_derivative(double t) const 
{
	return Vector3D{ -radius_x*std::sin(t),radius_y*std::cos(t) };
}