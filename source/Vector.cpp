#include "Vector.h"
Vector::Vector(int* _arr, int _N) {
	arr = new int[_N];
	N = _N;
	for (int i = 0; i < _N; i++) arr[i] = _arr[i];
}
Vector::Vector(int _N) {
	arr = new int[_N];
	N = _N;
}
Vector::Vector(const Vector& vec) {
	arr = new int[N = vec.N];
	std::copy(arr, arr + N, vec.arr);
}
int Vector::operator[](size_t i) {
	return arr[i];
}
int Vector::operator*(const Vector& a) const {
	if (this->N != a.N) throw std::invalid_argument("error");
	int amount = 0;
	for (int i = 0; i < this->N; i++) {
		amount += this->arr[i] * a.arr[i];
	}
	return amount;
}


Vector Vector::v_mult(Vector& a) {
	if (this->N != 3 || a.N != 3) {
		throw std::invalid_argument("error");
	}
	int* result = new int[3];
	result[0] = arr[1] * a.arr[2] - arr[2] * a.arr[1];
	result[1] = arr[2] * a.arr[0] - arr[0] * a.arr[2];
	result[2] = arr[0] * a.arr[1] - arr[1] * a.arr[0];
	return Vector(result, 3);
}