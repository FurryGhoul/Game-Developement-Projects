#include <iostream>
#include "Vec3.h"
using namespace std;
int main()
{
	Vec3<float> vec1(2.0f, 4.0f, 7.0f);

	cout << "The sum: " << vec1.getX() << endl;

	system("pause");
}