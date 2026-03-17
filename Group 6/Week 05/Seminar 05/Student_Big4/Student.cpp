#include "Student.h"

double* Student::getGrades() const
{
	return grades;
}

void Student::setGrades(const double* grades, int gradeCount)
{
	if (grades == nullptr || this->grades == grades || gradeCount == 0) {
		return;
	}
	delete[] this->grades;
	this->gradeCount = gradeCount;
	gradeCapacity = gradeCount;
	this->grades = new double[gradeCapacity];
	for (int i = 0; i < gradeCount; i++)
	{
		this->grades[i] = grades[i];
	}

}

unsigned Student::getFn() const
{
	return fn;
}

void Student::setFn(unsigned fn)
{
	this->fn = fn;
}

double Student::getGradeCount() const
{
	return gradeCount;
}

void Student::addGrade(double grade)
{
	if (grade < 2.0 || grade>6.0) {
		return;
	}

	if (gradeCount == gradeCapacity) {
		resize(gradeCapacity * 2);
	}
	grades[gradeCount++] = grade;
}

double Student::getAverageGrade() const
{
	double sum = 0;
	for (int i = 0; i < gradeCount; i++)
	{
		sum += grades[i];
	}
	return sum/gradeCount;
}

void Student::free()
{
	delete[] name;
	delete[] grades;
}

void Student::copyFrom(const Student& other)
{
	int len = strlen(other.name);
	name = new char[len + 1];
	strcpy(name, other.name);
	fn = other.fn;

	gradeCount = other.gradeCount;
	gradeCapacity = other.gradeCapacity;
	grades = new double[gradeCapacity];
	for (int i = 0; i < gradeCount; i++)
	{
		grades[i] = other.grades[i];
	}


}

void Student::resize(int newCap)
{
	gradeCapacity = newCap;
	double* temp = new double[gradeCapacity];
	for (int i = 0; i < gradeCount; i++)
	{
		temp[i] = grades[i];
	}
	delete[] grades;
	grades = temp;
}

Student::Student(const char* name, unsigned fn)
{
	setName(name);
	setFn(fn);
	grades = new double[gradeCapacity];
}

Student::Student(const char* name, unsigned fn, double* grades, int gradesCount)
{
	setName(name);
	setFn(fn);
	setGrades(grades, gradesCount);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

const char* Student::getName() const
{
	return name;
}

void Student::setName(const char* name)
{
	if (name == nullptr || this->name == name) {
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}
