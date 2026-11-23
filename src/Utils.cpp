#include "Utils.h"
#include <algorithm>
#include <ios>
#include <string_view>

std::string_view utils::FirstTwo(std::string_view s)
{
	size_t end = 0;
	size_t count = 0;

	while (end < s.size())
	{
		if ((static_cast<unsigned char>(s[end]) & 0xc0) != 0x80)
		{
			if (count == 2)
			{
				break;
			}

			count++;
		}

		end++;
	}

	return s.substr(0, end);
}

std::string utils::Uppercase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	
	return s;
}

std::string utils::Lowercase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	return s;
}
