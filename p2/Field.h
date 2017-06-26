
#ifndef FIELD_H_
#define FIELD_H_
#include "Exceptions.h"
#include <string>

class Field  {
private:
	std::string field_name;
	std::string class_name;
	Type type;
	bool is_static;
public:
	Field(std::string name, std::string className, Type t, bool isStatic);

	Type getType();
	
	void setInt(Object* obj, int value);

	int getInt(Object* obj);
	
	void setObj(Object* obj, Object* value);

	Object* getObj(Object* obj);

	std::string getDeclaringClass() const;
	
	std::string name() const;

	
};

#endif /* FIELD_H_ */
