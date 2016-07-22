#pragma once
#include <string>

class HashString
{
public:
	static unsigned long HashName(const std::string& name)
	{
		unsigned long hash = 5381;
		int c;

		for (unsigned i = 0; i < name.size(); i++)
		{
			c = name[i];
			hash = ((hash << 5) + hash) + c;
		}

		return hash;
	}
};