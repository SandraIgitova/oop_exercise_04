#pragma once
#include <iostream>
#include <tuple>

#include "figure_calculations.h"

template <class T>
class Rectangle{// Прямоугольник
	using vertex_t = std::pair<T, T>;
public:
	vertex_t a, b, c, d;
	Rectangle(vertex_t A, vertex_t B, vertex_t C, vertex_t D) {
		a.first = A.first; a.second = A.second;
		b.first = B.first; b.second = B.second;
		c.first = C.first; c.second = C.second;
		d.first = D.first; d.second = D.second;
	};
	
	double Area() {
		return RectangleArea(a, b, c, d);
	};
	vertex_t Center() {
		return RectangleCenter(a, b, c, d);
	};
	void Print() {
		std::cout << "Координаты вершин фигуры: \n";
		std::cout << "\t" << "X" << "\t" << "Y" << std::endl;
		std::cout << "\t" << a.first << "\t" << a.second << std::endl;
		std::cout << "\t" << b.first << "\t" << b.second << std::endl;
		std::cout << "\t" << c.first << "\t" << c.second << std::endl;
		std::cout << "\t" << d.first << "\t" << d.second << std::endl;

	};


};
