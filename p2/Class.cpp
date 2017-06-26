#include "Class.h"

Class::Class(Class* c, const std::string& name):
		super_class(c),class_name(name),accessible(false),static_fields(),
		inst_fields(),methods(),objects(){

}

std::string Class::name()const{
	return class_name;
}

Class* Class::getSuperClass(){
	return super_class;
}

void Class::addMethod(std::string name, Func func){
	//to do
}

void Class::addInstanceField(std::string name, Type t){
	Field f(name,class_name,t,false);
	inst_fields[name]=f;
}

void Class::addStaticField(std::string name, Type t){
	Field f(name,class_name,t,false);
	inst_fields[name]=f;
	//add to all instances
}

Field Class::getField(std::string name){
	if(static_fields.find(name)!=static_fields.end())
		return static_fields[name];
	if(inst_fields.find(name)!=inst_fields.end())
		return inst_fields[name];
	if(super_class==nullptr)
		throw new FieldNotFound();
	return super_class->getField(name);
}

std::list<Field> Class::getFields(){
	std::list<Field> res;
	for(auto& kv : static_fields){
		res.push_back(kv.second);
	}
	if(super_class == nullptr)
		return res;
	std::list<Field> super_res = super_class->getFields();
	res.insert(res.end(),super_res.begin(),super_res.end());
	return res;
}

static bool Class::getAccessible(){
	return accessible;

}

