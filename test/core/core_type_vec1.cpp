///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2014-10-11
// Updated : 2014-10-11
// Licence : This source is under MIT License
// File    : test/core/type_vec1.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#define GLM_SWIZZLE
#include <glm/vector_relational.hpp>
#include <glm/gtc/vec1.hpp>
#include <vector>

int test_vec1_operators()
{
	int Error(0);

	glm::vec1 A(1.0f);
	glm::vec1 B(1.0f);
	{
		bool R = A != B;
		bool S = A == B;

		Error += (S && !R) ? 0 : 1;
	}

	{
		A *= 1.0f;
		B *= 1.0;
		A += 1.0f;
		B += 1.0;

		bool R = A != B;
		bool S = A == B;

		Error += (S && !R) ? 0 : 1;
	}

	return Error;
}

int test_vec1_ctor()
{
	int Error = 0;

/*
#if GLM_HAS_INITIALIZER_LISTS
	{
		glm::vec1 a{ 0 };
		std::vector<glm::vec1> v = {
			{0.f},
			{4.f},
			{8.f}};
	}

	{
		glm::dvec2 a{ 0 };
		std::vector<glm::dvec1> v = {
			{0.0},
			{4.0},
			{8.0}};
	}
#endif
*/
#if GLM_HAS_ANONYMOUS_UNION && defined(GLM_SWIZZLE)
	{
		glm::vec2 A = glm::vec2(1.0f, 2.0f);
		glm::vec2 B = A.xy;
		glm::vec2 C(A.xy);
		glm::vec2 D(A.xy());

		Error += glm::all(glm::equal(A, B)) ? 0 : 1;
		Error += glm::all(glm::equal(A, C)) ? 0 : 1;
		Error += glm::all(glm::equal(A, D)) ? 0 : 1;
	}
#endif// GLM_HAS_ANONYMOUS_UNION && defined(GLM_SWIZZLE)

	{
		glm::vec2 A = glm::vec2(2.0f);
		glm::vec2 B = glm::vec2(2.0f, 3.0f);
		glm::vec2 C = glm::vec2(2.0f, 3.0);
		//glm::vec2 D = glm::dvec2(2.0); // Build error TODO: What does the specification says?
		glm::vec2 E(glm::dvec2(2.0));
		glm::vec2 F(glm::ivec2(2));
	}

	return Error;
}

int test_vec1_size()
{
	int Error = 0;
	
	Error += sizeof(glm::vec1) == sizeof(glm::mediump_vec1) ? 0 : 1;
	Error += 8 == sizeof(glm::mediump_vec1) ? 0 : 1;
	Error += sizeof(glm::dvec1) == sizeof(glm::highp_dvec1) ? 0 : 1;
	Error += 16 == sizeof(glm::highp_dvec1) ? 0 : 1;
	Error += glm::vec1().length() == 2 ? 0 : 1;
	Error += glm::dvec1().length() == 2 ? 0 : 1;
	
	return Error;
}

int test_vec1_operator_increment()
{
	int Error(0);

	glm::ivec1 v0(1);
	glm::ivec1 v1(v0);
	glm::ivec1 v2(v0);
	glm::ivec1 v3 = ++v1;
	glm::ivec1 v4 = v2++;

	Error += glm::all(glm::equal(v0, v4)) ? 0 : 1;
	Error += glm::all(glm::equal(v1, v2)) ? 0 : 1;
	Error += glm::all(glm::equal(v1, v3)) ? 0 : 1;

	int i0(1);
	int i1(i0);
	int i2(i0);
	int i3 = ++i1;
	int i4 = i2++;

	Error += i0 == i4 ? 0 : 1;
	Error += i1 == i2 ? 0 : 1;
	Error += i1 == i3 ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	glm::vec1 v;
	assert(v.length() == 1);

	Error += test_vec1_size();
	Error += test_vec1_ctor();
	Error += test_vec1_operators();
	Error += test_vec1_operator_increment();
	
	return Error;
}
