#include "Object.h"

size_t Object::s_objectIdMax = 0;
size_t Object::s_objectCounter = 0;

Object::Object()
{
	SetObjectType("OBJECT");
	m_objectId = s_objectIdMax++;
	++s_objectCounter;
}
