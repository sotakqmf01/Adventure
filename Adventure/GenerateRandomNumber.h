#pragma once
#include <random>
using namespace std;

template <typename T>
T generateRandomNumber(T first, T last)
{
	random_device rd;
	mt19937 generateEngine(rd());
	uniform_int_distribution<T> randomNumber(first, last);

	return randomNumber(generateEngine);
}