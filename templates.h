#pragma once
#include "figure_calculations.h"
template <class T>
double Area(std::tuple<vertex_t<T>, vertex_t<T>, vertex_t<T>> argsT) {
	return TriangleArea(std::get<0>(argsT), std::get<1>(argsT), std::get<2>(argsT));
};

template <class T>
double Area(std::tuple<vertex_t<T>, vertex_t<T>, vertex_t<T>, vertex_t<T>> argsT) {
	return RectangleArea(std::get<0>(argsT), std::get<1>(argsT), std::get<2>(argsT), std::get<3>(argsT));
};

// центр
template <class T>
vertex_t<T> Center(std::tuple<vertex_t<T>, vertex_t<T>, vertex_t<T>> argsT) {
	return TriangleCenter(std::get<0>(argsT), std::get<1>(argsT), std::get<2>(argsT));
};
template <class T>
vertex_t<T> Center(std::tuple<vertex_t<T>, vertex_t<T>, vertex_t<T>, vertex_t<T>> argsT) {
	return RectangleCenter(std::get<0>(argsT), std::get<1>(argsT), std::get<2>(argsT), std::get<3>(argsT));
};

// перегрузка
template <class T>
double Area(Rectangle<T> Rectangle) {
	return Rectangle.Area();
};
template <class T>
double Area(Triangle<T> Triangle) {
	return Triangle.Area();
};
template <class T>
vertex_t<T>  Center(Rectangle<T> Rectangle) {
	return Rectangle.Center();
};
template <class T>
vertex_t<T>  Center(Triangle<T> Triangle) {
	return Triangle.Center();
};


// вывод

template <typename T>
void Print(Rectangle<T> Rectangle) {
	Rectangle.Print();
};
template <typename T>
void Print(Square<T> Square) {
	Square.Print();
};

template <typename T>
void Print(std::tuple<vertex_t<T>, vertex_t<T>, vertex_t<T>, vertex_t<T>> argsT) {
	std::cout << "Координаты вершин фигуры: \n";
	std::cout << "\t" << "X" << "\t" << "Y" << std::endl;
	std::cout << "\t" << std::get<0>(argsT).first << "\t" << std::get<0>(argsT).second << std::endl;
	std::cout << "\t" << std::get<1>(argsT).first << "\t" << std::get<1>(argsT).second << std::endl;
	std::cout << "\t" << std::get<2>(argsT).first << "\t" << std::get<2>(argsT).second << std::endl;
	std::cout << "\t" << std::get<3>(argsT).first << "\t" << std::get<3>(argsT).second << std::endl;
	std::cout << "Площадь фигуры: \n";
	std::cout << "\t" << Area(argsT) << std::endl;
	std::cout << "Центр фигуры: \n";
	std::cout << "\t" << "X" << "\t" << "Y" << std::endl;
	std::cout << "\t" << Center(argsT).first << "\t" << Center(argsT).second << std::endl << std::endl;
};
template <typename T>
void Print(Triangle<T> Triangle) {
	Triangle.Print();
};
template <typename T>
void Print(std::tuple<vertex_t<T>, vertex_t<T>, vertex_t<T>> argsT) {
	std::cout << "Координаты вершин фигуры: \n";
	std::cout << "\t" << "X" << "\t" << "Y" << std::endl;
	std::cout << "\t" << std::get<0>(argsT).first << "\t" << std::get<0>(argsT).second << std::endl;
	std::cout << "\t" << std::get<1>(argsT).first << "\t" << std::get<1>(argsT).second << std::endl;
	std::cout << "\t" << std::get<2>(argsT).first << "\t" << std::get<2>(argsT).second << std::endl;
};