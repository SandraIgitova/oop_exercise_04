#pragma once

#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
#include <tuple>

#define TYPE double // тип координат

template <typename T>
using vertex_t = std::pair<T, T>; // вершина std:pair<TYPE,TYPE>


 // сортировка вершин
template <typename T>
void Sort(int n, vertex_t<T> *arr) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && arr[j - 1].first > arr[j].first; j--) {
			vertex_t<T> tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}


//------------------- математика------------------------------

template <typename T>
bool IsRectangle(vertex_t<T> A, vertex_t<T> B, vertex_t<T> C, vertex_t<T> D) {
	vertex_t<T> mas[4] = { A, B, C, D };
	Sort(4, mas); // для введения точек в произвольном порядке	
	if (mas[0].first == mas[1].first) {
		if (mas[0].second > mas[1].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[0]; mas[0] = hlp; }
		if (mas[2].second < mas[3].second) { vertex_t<T> hlp = mas[2]; mas[2] = mas[3]; mas[3] = hlp; }
	}
	else if (mas[1].second < mas[3].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[3]; mas[3] = hlp; }
	vertex_t<T> vector1, vector2, vector3, vector4;
	vector1.first = mas[1].first - mas[0].first; vector1.second = mas[1].second - mas[0].second;
	vector2.first = mas[2].first - mas[1].first; vector2.second = mas[2].second - mas[1].second;
	vector3.first = mas[3].first - mas[2].first; vector3.second = mas[3].second - mas[2].second;
	vector4.first = mas[0].first - mas[3].first; vector4.second = mas[0].second - mas[3].second;
	// проверяем два угла скалярными произведениями
	if (((vector1.first * vector2.first + vector1.second * vector2.second) == 0) && ((vector3.first * vector2.first + vector3.second * vector2.second) == 0) && ((vector4.first * vector3.first + vector4.second * vector3.second) == 0)) {
		return true;
	}
	else { return false; }

}
template <typename T>
bool IsSquare(vertex_t<T> A, vertex_t<T> B, vertex_t<T> C, vertex_t<T> D) {
	vertex_t<T> mas[4] = { A, B, C, D };
	Sort(4, mas); // для введения точек в произвольном порядке	
	if (mas[0].first == mas[1].first) {
		if (mas[0].second > mas[1].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[0]; mas[0] = hlp; }
		if (mas[2].second < mas[3].second) { vertex_t<T> hlp = mas[2]; mas[2] = mas[3]; mas[3] = hlp; }
	}
	else if (mas[1].second < mas[3].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[3]; mas[3] = hlp; }
	double d1 = sqrt(pow(mas[1].first - mas[0].first, 2) + pow(mas[1].second - mas[0].second, 2));
	double d2 = sqrt(pow(mas[2].first - mas[1].first, 2) + pow(mas[1].second - mas[2].second, 2));
	vertex_t<T> vector1, vector2, vector3, vector4;
	vector1.first = mas[1].first - mas[0].first; vector1.second = mas[1].second - mas[0].second;
	vector2.first = mas[2].first - mas[1].first; vector2.second = mas[2].second - mas[1].second;
	vector3.first = mas[3].first - mas[2].first; vector3.second = mas[3].second - mas[2].second;
	vector4.first = mas[0].first - mas[3].first; vector4.second = mas[0].second - mas[3].second;
	// проверяем два угла скалярными произведениями и равенство сторон	
	if (((vector1.first * vector2.first + vector1.second * vector2.second) == 0) && ((vector3.first * vector2.first + vector3.second * vector2.second) == 0) && ((vector4.first * vector3.first + vector4.second * vector3.second) == 0) && (d1 == d2)) {
		return true;
	}
	else { return false; }
}





 // сортировка вершин
/*template <typename T>
void Sort(int n, vertex_t<T> *arr) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && arr[j - 1].first > arr[j].first; j--) {
			vertex_t<T> tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}*/

// площадь прямоугольника
template <typename T>
double RectangleArea(vertex_t<T> a, vertex_t<T> b, vertex_t<T> c, vertex_t<T> d)
{
	vertex_t<T> mas[4] = { a, b, c, d };
	Sort(4, mas);
	// x- first, y - second
	if (mas[0].first == mas[1].first) {
		if (mas[0].second > mas[1].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[0]; mas[0] = hlp; }
		if (mas[2].second < mas[3].second) { vertex_t<T> hlp = mas[2]; mas[2] = mas[3]; mas[3] = hlp; }
	}
	else if (mas[1].second < mas[3].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[3]; mas[3] = hlp; }
	double d1 = sqrt(pow(mas[1].first - mas[0].first, 2) + pow(mas[1].second - mas[0].second, 2));
	double d2 = sqrt(pow(mas[2].first - mas[1].first, 2) + pow(mas[1].second - mas[2].second, 2));
	return d1 * d2;
}

// площадь треугольника по формуле Герона
template <typename T>
double TriangleArea(vertex_t<T> a, vertex_t<T> b, vertex_t<T> c)
{
	vertex_t<T> mas[3] = { a, b, c };
	Sort(3, mas);
	// x- first, y - second
	if (mas[0].first == mas[1].first)
		if (mas[0].second > mas[1].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[0]; mas[0] = hlp; }
	if (mas[1].first == mas[2].first)
		if (mas[2].second > mas[1].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[2]; mas[2] = hlp; }
		else if (mas[1].second < mas[2].second) { vertex_t<T> hlp = mas[1]; mas[1] = mas[2]; mas[2] = hlp; }
	double a1 = sqrt(pow(mas[1].first - mas[0].first, 2) + pow(mas[1].second - mas[0].second, 2));
	double b1 = sqrt(pow(mas[1].first - mas[2].first, 2) + pow(mas[2].second - mas[1].second, 2));
	double c1 = sqrt(pow(mas[2].first - mas[0].first, 2) + pow(mas[0].second - mas[2].second, 2));
	double p = (a1 + b1 + c1) / 2;
	return  sqrt(p*(p - a1)*(p - b1)*(p - c1));
}

// центр прямоугольника
template <typename T>
vertex_t<T> RectangleCenter(vertex_t<T> a, vertex_t<T> b, vertex_t<T> c, vertex_t<T> d) {
	vertex_t<T> center;
	// x- first, y - second
	center.first = (a.first + b.first + c.first + d.first) / 4;
	center.second = (a.second + b.second + c.second + d.second) / 4;
	return center;
}

// центр треугольника
template <typename T>
vertex_t<T> TriangleCenter(vertex_t<T> a, vertex_t<T> b, vertex_t<T> c) {
	vertex_t<T> center;
	// x- first, y - second
	center.first = (a.first + b.first + c.first) / 3;
	center.second = (a.second + b.second + c.second) / 3;
	return center;
}
