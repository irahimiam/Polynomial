// Polynomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List poly;
	List poly2;
	List poly3;

	// 2x^2 + 5x^4

	poly.InsertNode(2, 2, 0);
	poly2.InsertNode(5, 2, 0);
	poly3 = poly + poly2;
	poly3.DisplayList();

	cin.get();
	cin.get();
}