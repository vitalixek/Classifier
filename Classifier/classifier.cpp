#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "classifier.h"

using namespace std;

//Int
ScaleInt::ScaleInt()
{
	computational_ = true;
}
bool ScaleInt::isComputational()
{
	return computational_;
}
void ScaleInt::setValue(int value)
{
	value_ = value;
}
int ScaleInt::getValue()
{
	return value_;
}
//Double
ScaleDouble::ScaleDouble()
{
	computational_ = true;
}
bool ScaleDouble::isComputational()
{
	return computational_;
}
void ScaleDouble::setValue(double value)
{
	value_ = value;
}
double ScaleDouble::getValue()
{
	return value_;
}
//Text
ScaleText::ScaleText()
{
	computational_ = false;
}
bool ScaleText::isComputational()
{
	return computational_;
}
void ScaleText::setValue(string value)
{
	value_ = value;
}
string ScaleText::getValue()
{
	return value_;
}
//DictionaryObject
DictionaryObject::DictionaryObject(string name, string type, string scale)
{
	name_ = name;
	type_ = type;
	if (scale == "NumericInt")
		scale_ = new ScaleInt();
	else if (scale == "NumericDouble")
		scale_ = new ScaleDouble();
	else if (scale == "Text")
		scale_ = new ScaleText();
}
DictionaryObject::~DictionaryObject()
{
	name_.clear();
	type_.clear();
	delete scale_;
}
string DictionaryObject::getName()
{
	return name_;
}
string DictionaryObject::getType()
{
	return type_;
}
Scale* DictionaryObject::getScale()
{
	return scale_;
}

Dictionary::Dictionary()
{

}
Dictionary::~Dictionary()
{

}
void Dictionary::insert(DictionaryObject object)
{
	objects_.push_back(object);
	if (object.getScale()->isComputational())
		computational_++;
	if (object.getType() == "Attribute")
		attributes_count_++;
	else if (object.getType() == "Class")
		classes_count_++;
	count_++;
}
int Dictionary::find(string name)
{
	for (int i = 0; i < objects_.size(); i++)
		if (objects_[i].getName() == name)
			return i;
	return -1;
}
void Dictionary::remove(string name)
{
	if (objects_[find(name)].getScale()->isComputational())
		computational_--;
	if (objects_[find(name)].getType() == "Attribute")
		attributes_count_--;
	else if (objects_[find(name)].getType() == "Class")
		classes_count_--;
	count_--;
	objects_.erase(objects_.begin() + find(name));
}
int Dictionary::getCount()
{
	return count_;
}
int Dictionary::getAttributesCount()
{
	return attributes_count_;
}
int Dictionary::getClassesCount()
{
	return classes_count_;
}
int Dictionary::getComputationalCount()
{
	return computational_;
}