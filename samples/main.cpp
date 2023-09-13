#include "Vector.h"
int main() {
	int* a = new int[3] {3,4,5};
	int* b = new int[3] {0,1,2};
	Vector vec1(a, 3), vec2(b, 3);
	std::cout << vec1 * vec2;
}