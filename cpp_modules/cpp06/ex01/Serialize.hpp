#pragma once

#include <iostream>
#include <stdint.h>

struct Data;

class Serialize
{
	public:
		~Serialize();
		static Data			*deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data *ptr);

	private:
		Serialize();
		Serialize(const Serialize &obj);
		Serialize& operator=(const Serialize &obj);

};