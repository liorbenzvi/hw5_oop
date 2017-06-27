#ifndef CLASS_H_
#define CLASS_H_

#include "Field.h"
#include "Object.h"
#include "Method.h"
#include <string>
#include <map>
#include <list>

typedef std::map<std::string, Field> FieldMap;
typedef std::map<std::string, Method> MethodMap;
typedef std::map<std::string, Object*> ObjectMap;
typedef std::map<std::string, int>  IntMap;
typedef std::map<std::string, Object*>  ObjMap;

class Class{

private:
	Class* super_class;
	std::string class_name;
	bool accessible;
	FieldMap static_fields;
    IntMap static_int_values;
    ObjMap static_obj_values;
	FieldMap inst_fields;
	MethodMap methods;
	ObjectMap objects;
public:
	Class(Class* c, const std::string& name);
		
	Class* getSuperClass();
	
	Object* newInstance(); // the constructor expect map of all instanceFields (of class and all superClasses)

	void addMethod(std::string name, Func func);
	
	void addInstanceField(std::string name, Type t);

	void addStaticField(std::string name, Type t);

	Field getField(std::string name);

	std::list<Field> getFields();

	Method getMethod(std::string name);

	std::list<Method> getMethods();

	// only static fields (from FAQ) -  also should look for static fields at class and his superclasses.
    int getInt(std::string name);

	void setInt(std::string name, int value);

	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);
	

    std::string name() const;

	static void setAccessible(bool flag);

    // Aid functions for object:

    bool getAccessible();
    // if the field doesn't exist return (-1) else return TYPE (should look for static fields at class and his superclasses)
    int getStaticFieldType(std::string name);



};

#endif /* CLASS_H_ */
