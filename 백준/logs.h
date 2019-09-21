#pragma once
#include <iostream>

/* [����]
	#include "logs.h"

	�α׸� ���� ������
	int a, b;
	print(L(a), L(b));

	�̷������� ȣ��.
*/

#define L(Variable) (#Variable),(Variable)

static bool __PRINT_INDEX__ = true;

template<typename T>
void print(T arg) {
	std::cout << arg << std::endl;
	__PRINT_INDEX__ = !__PRINT_INDEX__;
}

template<typename T>
void printType(T arg) {
	std::cout << arg;
	if (__PRINT_INDEX__) {
		std::cout << ": ";
	}
	else {
		std::cout << ", ";
	}
	__PRINT_INDEX__ = !__PRINT_INDEX__;
}

template<typename T, typename... Args>
inline void print(T arg, Args... args) {
	printType(arg);
	print(args...);
}