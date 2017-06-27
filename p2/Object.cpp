#include "Object.h"
#include "Class.h"
#include "Field.h"
#include "Method.h"

Object::Object(Class* my_class, FieldMap fields): my_class(my_class){
    for (map<string, Field>::iterator it = fields.begin(); it != fields.end(); ++it)
    {
        if(it->second.getType() == INT){
            int_fields.insert(pair<string,int>(it->first,0));
        } else{
            obj_fields.insert(pair<string,Object*>(it->first,nullptr));
        }
    }
}

Object::~Object() {
    my_class = nullptr;
    int_fields.clear();
    obj_fields.clear();
}

Class* Object::getClass(){
    return my_class;
}

int Object::getInt(string name){
    if(int_fields.find(name) != int_fields.end()) {
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        return int_fields[name];
    }
    if(obj_fields.find(name) != obj_fields.end()){
        throw TypeError();
    }
    int static_field = my_class->getStaticFieldType(name);
    if(static_field== -1){
        throw FieldNotFound();
    }
    if((Type)(static_field) == OBJECT){
        throw TypeError();
    }
    if((Type)(static_field) == INT){
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        return my_class->getInt(name);
    }
}

Object* Object::getObj(string name){
    if(int_fields.find(name) != int_fields.end()) {
        throw TypeError();
    }
    if(obj_fields.find(name) != obj_fields.end()){
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        return obj_fields[name];
    }
    int static_field = my_class->getStaticFieldType(name);
    if(static_field== -1){
        throw FieldNotFound();
    }
    if((Type)(static_field) == OBJECT){
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        return my_class->getObj(name);
    }
    if((Type)(static_field) == INT){
        throw TypeError();
    }
}

void Object::setInt(string name, int value){
    if(int_fields.find(name) != int_fields.end()) {
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        int_fields[name]= value;
    }
    if(obj_fields.find(name) != obj_fields.end()){
        throw TypeError();
    }
    int static_field = my_class->getStaticFieldType(name);
    if(static_field== -1){
        throw FieldNotFound();
    }
    if((Type)(static_field) == OBJECT){
        throw TypeError();
    }
    if((Type)(static_field) == INT){
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        return my_class->setInt(name, value);
    }
}

void Object::setObj(string name, Object* value){
    if(int_fields.find(name) != int_fields.end()) {
        throw TypeError();
    }
    if(obj_fields.find(name) != obj_fields.end()){
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        obj_fields[name] = value;
    }
    int static_field = my_class->getStaticFieldType(name);
    if(static_field== -1){
        throw FieldNotFound();
    }
    if((Type)(static_field) == OBJECT){
        if(!my_class->getAccessible()){
            throw FieldNotAccessible();
        }
        return my_class->setObj(name, value);
    }
    if((Type)(static_field) == INT){
        throw TypeError();
    }
}

bool Object::isInstanceOf(string c){
    return (c == my_class->name());
}

bool Object::isKindOf(std::string c){
    for(Class* ptr = my_class; ptr!= nullptr; ptr = ptr->getSuperClass()){
        if(ptr->name() == c) return true;
    }
    return false;
}

void Object::invokeMethod(string name){
    Method method = my_class->getMethod(name);
    Func function = method.getFunction();
    function(this);
}
