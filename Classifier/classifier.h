#pragma once

#include<iostream>
#include<string.h>

using namespace std;

class Classifier
{
public:
	virtual void method();

};

class FuzzyClassifier : public Classifier
{
private:


};
class ClearClassifier : public Classifier
{
private:

};
