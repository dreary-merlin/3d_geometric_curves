// 3d_geometric_curves.cpp: определяет точку входа для консольного приложения.
//

#include "helix3d.h"
#include "circle3d.h"
#include "ellipse3d.h"
#include <memory>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <typeinfo>
#include <numeric>

using curves3d = std::vector<std::shared_ptr<Curve3D>>;
using circles3d = std::vector<std::shared_ptr<Circle3D>>;

std::shared_ptr<Curve3D> random_curve(double start, double end) // random manner
{
	std::mt19937 mersenne(static_cast<std::size_t>(std::chrono::steady_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<std::uint16_t> curve_dist(0, 2);
	if (end < start) std::swap(start, end);
	std::uniform_real_distribution<double> dist(start, end);
	switch (curve_dist(mersenne))
	{
	case 0:
		return std::make_shared<Circle3D>(Point3D{ dist(mersenne) , dist(mersenne) ,dist(mersenne) }, std::fabs(dist(mersenne)));
	case 1:
		return std::make_shared<Ellipse3D>(Point3D{ dist(mersenne) , dist(mersenne) ,dist(mersenne) }, std::fabs(dist(mersenne)), std::fabs(dist(mersenne)));
	default:
		return std::make_shared<Helix3D>(Point3D{ dist(mersenne) , dist(mersenne) ,dist(mersenne) }, std::fabs(dist(mersenne)), dist(mersenne));
	}
}

curves3d generate_random_curves(std::size_t n, double start, double end) // populate container of different curves
{
	curves3d curves;
	curves.reserve(n);
	for (std::size_t i = 0; i < n; i++)
	{
		curves.emplace_back(random_curve(start, end));
	}
	return curves;
}

template <typename T>
void print_curves(const std::vector<std::shared_ptr<T>> &curves, double t) // print coordinates
{
	for (const auto &curve : curves)
	{
		auto point = curve->get_point(t);
		auto derivative = curve->get_first_derivative(t);
		std::cout << typeid(*curve).name() << ": point = (" << point.x << "; " << point.y << "; " << point.z << "), derivative = (" << derivative.x << "; " << derivative.y << "; " << derivative.z << ")" << std::endl;
	}
	std::cout << std::endl;
}

circles3d sort_circles(const curves3d& curves) // populate and sort container of circles
{
	circles3d circles;
	for (const auto &curve : curves)
	{
		if (typeid(*curve) == typeid(Circle3D))
			circles.emplace_back(std::dynamic_pointer_cast<Circle3D>(curve));
	}
	std::sort(circles.begin(), circles.end(), [](const auto &left, const auto &right) 
	{
		return left->get_radius() < right->get_radius();
	});
	for (const auto &circle : circles)
		std::cout << circle->get_radius() << " ";
	std::cout << std::endl;
	return circles;
}

double total_sum_of_radius(const circles3d& circles) // total sum of circles
{
	return std::accumulate(circles.begin(), circles.end(), 0.0, [](double sum, const std::shared_ptr<Circle3D> &circle)
	{
		return sum + circle->get_radius();
	});
}

int main()
{
	curves3d curves = generate_random_curves(10,-10.5,10.0);
	print_curves(curves, M_PI_4);
	circles3d circles = sort_circles(curves);
	std::cout << total_sum_of_radius(circles) << std::endl;
	system("pause");
    return 0;
}

