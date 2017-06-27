#include "Field.h"
#include "Object.h"
using namespace std;

Field::Field(string name, string className, Type t, bool isStatic) :
		field_name(name), class_name(className), type(t), is_static(isStatic){
}

string Field::name() const{
	return field_name;
}

Type Field::getType(){
	return type;
}

void Field::setInt(Object* obj, int value){
	if(type != INT){
		throw new TypeError();
	}
	obj->setInt(field_name,value);
}

int Field::getInt(Object* obj){
	if(type != INT){
		throw new TypeError();
	}
	return obj->getInt(field_name);
}

Object* Field::getObj(Object* obj){
	if(type != OBJECT){
		throw new TypeError();
	}
	return obj->getObj(field_name);
}

void Field::setObj(Object* obj, Object* value){
	if(type != OBJECT){
		throw new TypeError();
	}
	obj->setObj(field_name,value);
}
string Field::getDeclaringClass() const{
	return class_name;
}

