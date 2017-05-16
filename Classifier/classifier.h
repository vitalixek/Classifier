#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "D:\project\demods-master\DSCore\DSCore\DSCore.h"

using namespace std;

class Classifier
{
public:
	virtual ~Classifier(){}

	virtual void method() = 0;

};

class FuzzyClassifier : public Classifier
{
private:


};
class ClearClassifier : public Classifier
{
private:

};

class Scale
{
public:
	Scale() {};
	~Scale() {};
	virtual bool isComputational() = 0;
protected:
	bool computational_;
};

class ScaleInt : public Scale
{
public:
	ScaleInt();
	~ScaleInt() {};
	bool isComputational();
	void setValue(int value);
	int getValue();
private:
	int value_;
};

class ScaleDouble : public Scale
{
public:
	ScaleDouble();
	~ScaleDouble() {};
	bool isComputational();
	void setValue(double value);
	double getValue();
private:
	double value_;
};

class ScaleText : public Scale
{
public:
	ScaleText();
	~ScaleText() {};
	bool isComputational();
	void setValue(string value);
	string getValue();
private:
	string value_;
};

class DictionaryObject
{
public:
	DictionaryObject(string name, string type, string scale);
	~DictionaryObject();
	string getName();
	string getType();
	Scale* getScale();
private:
	string name_, type_;
	Scale* scale_;
};

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	void insert(DictionaryObject object);
	int find(string name);
	void remove(string name);
	int getCount();
	int getAttributesCount();
	int getClassesCount();
	int getComputationalCount();

private:
	int count_ = 0;
	int attributes_count_=0;
	int classes_count_ = 0;
	int computational_ = 0;
	vector<DictionaryObject> objects_;
};

class Teacher
{
public:
	Teacher() {};
	~Teacher() {};
	
private:
	Dictionary dictionary_;
};



