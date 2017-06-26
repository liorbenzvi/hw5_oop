#include <iostream>
#include "Method.h"


Method::Method(std::string name,std::string className,Func f):
        method_name(name), class_name(className),function_pointer(f) {
}

std::string Method::name() const{
    return method_name;
}

void Method::invoke(Object* const obj){
    obj->invokeMethod(method_name);
}

std::string Method::getDeclaringClass() const{
    return class_name;
}