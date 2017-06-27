#ifndef CLASS_H_
#define CLASS_H_
#include <string>
#include <map>
#include <vector>
#include <list>
#include"Exceptions.h"
class Field;
class Method;
class Object;
typedef void(*Func)(Object*);
typedef std::map<std::string, Field> FieldMap;
typedef std::map<std::string, Method> MethodMap;
typedef std::vector<Object*> ObjectVector;
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
	ObjectVector objects;
public:

	~Class();
	//DONE
	Class(Class* c, const std::string& name);
	//DONE
	Class* getSuperClass();
	
	FieldMap getAllInstanceFields();

	Object* newInstance(); // the constructor expect map of all instanceFields (of class and all superClasses)
	//DONE
	void addMethod(std::string name, Func func);
	//DONE
	void addInstanceField(std::string name, Type t);
	//DONE
	void addStaticField(std::string name, Type t);
	//DONE
	Field getField(std::string name);
	//DONE
	std::list<Field> getFields();
	//DONE
	Method getMethod(std::string name);
	//DONE
	std::list<Method> getMethods();

	//DONE
    int getInt(std::string name);

	void setInt(std::string name, int value);

	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);
	
	//DONE
    std::string name() const;
    //DONE
	static void setAccessible(bool flag);

    // Aid functions for object:
	//DONE
    bool getAccessible();
    //DONE
    // if the field doesn't exist return (-1) else return TYPE (should look for static fields at class and his superclasses)
    int getStaticFieldType(std::string name);



};

#endif /* CLASS_H_ */
