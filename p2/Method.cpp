#include <iostream>
#include "Method.h"
#include "Object.h"


Method::Method(std::string name,std::string className,Func f):
        method_name(name), class_name(className),function_pointer(f) {
}

std::string Method::name() const{
    return method_name;
}

void Method::invoke(Object* const obj){
    if(obj == nullptr){
        throw MethodNotFound();
    }
    obj->invokeMethod(method_name);
}

std::string Method::getDeclaringClass() const{
    return class_name;
}

Func Method::getFunction(){
    return function_pointer;
}
