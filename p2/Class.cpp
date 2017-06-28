

#include "Class.h"
bool Class::accessible = false;

Class::Class(Class* c, const std::string& name):
		super_class(c),class_name(name),static_fields(),
		static_int_values(),static_obj_values(),inst_fields(),methods(),objects(){
}

FieldMap Class::getAllInstanceFields(){
	FieldMap map;
	for(auto& kv : inst_fields){
		map[kv.first]= kv.second;
	}
	if(super_class != nullptr){
		FieldMap super_map = super_class->getAllInstanceFields();
		map.insert(super_map.begin(), super_map.end());
	}
	return map;
}

Object* Class::newInstance(){
	Object* obj = new Object(this,getAllInstanceFields());
	objects.push_back(obj);
	return obj;
}

Class::~Class(){
	for(auto& obj : objects)
		delete obj;
	super_class = nullptr;
    static_fields.clear();
    static_int_values.clear();
    static_obj_values.clear();
    inst_fields.clear();
    methods.clear();
}

std::string Class::name()const{
	return class_name;
}

Class* Class::getSuperClass(){
	return super_class;
}


void Class::addInstanceField(std::string name, Type t){
	Field f(name,class_name,t,false);
    inst_fields.insert(pair<string, Field>(name, f));
}

void Class::addStaticField(std::string name, Type t){
	Field f(name, class_name, t, true);
    static_fields.insert(pair<string, Field>(name, f));
    if(t == INT){
        static_int_values.insert(pair<string, int>(name,0));
    } else{
        static_obj_values.insert(pair<string, Object*>(name, nullptr));
    }
}

Method Class::getMethod(std::string name){
	if(methods.find(name) != methods.end())
		return methods[name];
	if(super_class == nullptr)
		throw MethodNotFound();
	return super_class->getMethod(name);
}

Field Class::getField(std::string name){
	if(static_fields.find(name) != static_fields.end())
		return static_fields[name];
	if(inst_fields.find(name) != inst_fields.end())
		return inst_fields[name];
	if(super_class == nullptr)
		throw FieldNotFound();
	return super_class->getField(name);
}

std::list<Field> Class::getFields(){
	std::list<Field> res;
	for(auto& kv : static_fields){
		res.push_back(kv.second);
	}
    for(auto& kv : inst_fields){
        res.push_back(kv.second);
    }
	if(super_class == nullptr)
		return res;
	std::list<Field> super_res = super_class->getFields();
	res.insert(res.end(),super_res.begin(),super_res.end());
	return res;
}

std::list<Method> Class::getMethods(){
	std::list<Method> res;
	for(auto& kv : methods){
		res.push_back(kv.second);
	}
	if(super_class == nullptr)
		return res;
	std::list<Method> super_res = super_class->getMethods();
	res.insert(res.end(),super_res.begin(),super_res.end());
	return res;
}

int Class::getInt(std::string name){
	if(static_fields.find(name)!= static_fields.end()){
		if(static_fields[name].getType()!= INT)
			throw TypeError();
		return static_int_values[name];
	}

	if(super_class == nullptr)
		throw FieldNotFound();
	return super_class->getInt(name);
}

void Class::setInt(std::string name, int value){
	if(static_fields.find(name)!= static_fields.end()){
		if(static_fields[name].getType()!= INT)
			throw TypeError();
		static_int_values[name] = value;
        return;
	}

	if(super_class == nullptr)
		throw FieldNotFound();
	 super_class->setInt(name,value);
}

Object* Class::getObj(std::string name){
	if(static_fields.find(name)!= static_fields.end()){
		if(static_fields[name].getType()!= OBJECT)
			throw TypeError();
		return static_obj_values[name];
	}
	if(super_class == nullptr)
		throw FieldNotFound();
	return super_class->getObj(name);
}

void Class::setObj(std::string name, Object* value){
	if(static_fields.find(name)!= static_fields.end()){
		if(static_fields[name].getType()!= OBJECT)
			throw TypeError();
		static_obj_values[name] = value;
        return;
	}

	if(super_class == nullptr)
		throw FieldNotFound();
	 super_class->setObj(name,value);
}


bool Class::getAccessible(){
	return accessible;
}

int Class::getStaticFieldType(std::string name){
	if(static_fields.find(name)!=static_fields.end())
		return static_fields[name].getType();
	if(super_class == nullptr) return -1;
	return super_class->getStaticFieldType(name);
}

void Class::addMethod(std::string name, Func func){
	Method me(name,class_name,func);
	methods.insert(pair<string, Method>(name, me));
}

void Class::setAccessible(bool flag){
    accessible = flag;
}

