
#ifndef METHOD_H_
#define METHOD_H_

#include"Object.h"

typedef void(*Func)(Object*);

class Method{
private:
	std::string method_name;
	std::string class_name;
	Func function_pointer;

public:

	std::string getDeclaringClass() const;

	Method(std::string name,std::string className,Func f);


	virtual void invoke(Object* const obj);
	
	std::string name() const;

    Func getFunction();


};


#endif /* METHOD_H_ */
