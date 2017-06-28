
#ifndef METHOD_H_
#define METHOD_H_

#include "Exceptions.h"

class Object;
typedef void(*Func)(Object*);

class Method{
private:
	std::string method_name;
	std::string class_name;
	Func function_pointer;

public:

	std::string getDeclaringClass() const;

	Method(std::string name,std::string className,Func f);

	Method()=default;

	virtual ~Method() = default;

	virtual void invoke(Object* const obj);
	
	std::string name() const;

    Func getFunction();


};


#endif /* METHOD_H_ */
