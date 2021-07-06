#include "Move.h"
#include <string>

Move::Move()
{
}

int Move::move_toInt() const
{
	std::string start = std::to_string(start_index);
	std::string end = std::to_string(end_index);

	std::string s = start + end;

	return std::stoi(s);
}
