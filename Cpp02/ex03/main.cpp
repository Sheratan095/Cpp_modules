/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 04:48:36 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);
static void testBsp();

int	main()
{
	testBsp();

	return (0);
}

static void	testBsp()
{
	// Triangle vertices
	Point a(Fixed(1), Fixed(1));
	Point b(Fixed(5), Fixed(1));
	Point c(Fixed(3), Fixed(6));

	// Test case 1: Point inside the triangle
	Point insidePoint(Fixed(2), Fixed(1.5f));
	if (bsp(a, b, c, insidePoint))
		std::cout << "Test 1 passed: Point is inside the triangle.\n";
	else
		std::cout << "Test 1 failed: Point should be inside the triangle.\n";

	// Test case 2: Point outside the triangle
	Point outsidePoint(Fixed(15), Fixed(5));
	if (!bsp(a, b, c, outsidePoint))
		std::cout << "Test 2 passed: Point is outside the triangle.\n";
	else
		std::cout << "Test 2 failed: Point s	hould be outside the triangle.\n";

	// Test case 3: Point on the edge of the triangle
	Point edgePoint(Fixed(1), Fixed(2));
	if (!bsp(a, b, c, edgePoint))
		std::cout << "Test 3 passed: Point is on the edge of the triangle.\n";
	else
		std::cout << "Test 3 failed: Point should be on the edge of the triangle.\n";

	// Test case 4: Point at a vertex of the triangle
	Point vertexPoint = a;
	if (!bsp(a, b, c, vertexPoint))
		std::cout << "Test 4 passed: Point is at a vertex of the triangle.\n";
	else
		std::cout << "Test 4 failed: Point should be at a vertex of the triangle.\n";

	// Test case 5: Degenerate triangle (all points are collinear)
	Point collinearA(Fixed(0), Fixed(0));
	Point collinearB(Fixed(5), Fixed(5));
	Point collinearC(Fixed(10), Fixed(10));
	Point testPoint(Fixed(3), Fixed(3));
	if (!bsp(collinearA, collinearB, collinearC, testPoint))
		std::cout << "Test 5 passed: Degenerate triangle handled correctly.\n";
	else
		std::cout << "Test 5 failed: Degenerate triangle should return false.\n";
}
