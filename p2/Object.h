#ifndef OBJECT_H_
#define OBJECT_H_

#include "Class.h"

typedef std::map<std::string, int>  IntMap;
typedef std::map<std::string, Object*>  ObjMap;

using namespace std;

class Object {
private:
    Class* my_class;
    IntMap int_fields;
    ObjMap obj_fields;


public:
	Object(Class* my_class, FieldMap fields);

    ~Object();

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
