#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <map>

#include "Class.h"
#include "Field.h"
#include "Method.h"

class Class;
class Field;
class Object;

typedef std::map<std::string, int>  IntMap;
typedef std::map<std::string, Object*>  ObjMap;
typedef std::map<std::string, Field> FieldMap;

using namespace std;


class Object {
private:
    Class* my_class;
    IntMap int_fields;
    ObjMap obj_fields;
    int from_invoke;


public:
	Object(Class* my_class, FieldMap fields);

	virtual ~Object();

	Class* getClass();

	int getInt(std::string name);

	void setInt(std::string name, int value);
	
	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);

	virtual void invokeMethod(std::string name);

	bool isInstanceOf(std::string c);
	
	bool isKindOf(std::string c);

};

#endif /* OBJECT_H_ */
