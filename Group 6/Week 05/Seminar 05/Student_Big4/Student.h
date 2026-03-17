#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
class Student {
	char* name = nullptr;
	unsigned fn;
	double* grades = nullptr;

	int gradeCount = 0;
	int gradeCapacity = 8;

	void free();
	void copyFrom(const Student& other);
	void resize(int newCap);

public:
	// no default constructor
	Student(const char* name, unsigned fn);

	Student(const char* name, unsigned fn, double* grades, int gradesCount);

	Student(const Student& other);

	Student& operator=(const Student& other);
	~Student();

	const char* getName() const;
	void setName(const char* name);


	double* getGrades() const;
	void setGrades(const double* grades, int gradeCount);

	unsigned getFn() const;
	void setFn(unsigned fn);


	double getGradeCount() const;
	
	void addGrade(double grade);

	double getAverageGrade() const;

	


};

