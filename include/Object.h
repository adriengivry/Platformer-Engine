#pragma once

#include <string>

#include "Info.h"

class Object
{
public:
	Object();
	virtual ~Object() { --s_objectCounter; }

	void SetObjectType(const std::string p_objectType) { m_objectType = p_objectType; }

	std::string& GetObjectType() { return m_objectType; }
	size_t& GetObjectId() { return m_objectId; }
	static size_t& GetObjectCounter() { return s_objectCounter; }
	static size_t& GetObjectTotalCounter() { return s_objectIdMax; }

	bool IsA(const std::string p_objectType) const { return m_objectType == p_objectType; }

	static size_t GetObjectInstancied() { return s_objectIdMax; }

protected:
	static size_t s_objectIdMax;
	static size_t s_objectCounter;
	size_t m_objectId;
	std::string m_objectType;
};

