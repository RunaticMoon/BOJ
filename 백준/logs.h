#pragma once
#include <iostream>

/* [사용법]
	#include "logs.h"

	로그를 찍을 곳에서
	int a, b;
	print(L(a), L(b));

	이런식으로 호출.
*/

#define L(Variable) (#Variable),(Variable)

static unsigned long long __PRINT_INDEX__ = 1;

template<typename T>
void print(T arg) {
	std::cout << arg << std::endl;
	__PRINT_INDEX__++;
}

template<typename T>
void printType(T arg) {
	std::cout << arg;
	if (__PRINT_INDEX__ % 2) {
		std::cout << " : ";
	}
	else {
		std::cout << ", ";
	}
	__PRINT_INDEX__++;
}

template<typename T, typename... Args>
inline void print(T arg, Args... args) {
	printType(arg);
	print(args...);
}