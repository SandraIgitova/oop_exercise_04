#pragma once
#include <iostream>
#include <tuple>

#include "figure_calculations.h"

template <class T>
class Triangle{// Треугольник
	using vertex_t = std::pair<T, T>;
public:
	vertex_t a, b, c;
	Triangle(vertex_t A, vertex_t B, vertex_t C) {
		a.first = A.first; a.second = A.second;
		b.first = B.first; b.second = B.second;
		c.first = C.first; c.second = C.second;
	};

	double Area() {
		return TriangleArea(a, b, c);
	};
	vertex_t Center() {
		return TriangleCenter(a, b, c);
	};
	void Print() {
		std::cout << "Координаты вершин фигуры: \n";
		std::cout << "\t" << "X" << "\t" << "Y" << std::endl;
		std::cout << "\t" << a.first << "\t" << a.second << std::endl;
		std::cout << "\t" << b.first << "\t" << b.second << std::endl;
		std::cout << "\t" << c.first << "\t" << c.second << std::endl;
	};
};