#pragma once

class Pali_dic
{
public:
	Pali_dic(std::string filename);
	bool is_special_character(char c);
	int search(const char* s);
	bool duplicate(const char* s);

protected:
	std::map<std::string, std::string> dictionary;
	std::map<std::pair<char, char>, std::string> special_chars = {
		{{'.', 'm'}, "\u1e43"}, {{'.', 's'}, "\u1e63"}, {{'^', 'a'}, "\u0101"},
		{{'^', 'i'}, "\u012b"}, {{'.', 'n'}, "\u1e47"}, {{'.', 'd'}, "\u1e0d"},
		{{'~', 'n'}, "\u00f1"}, {{'.', 't'}, "\u1e6d"}, {{'.', 'l'}, "\u1e37"},
		{{'`', 'n'}, "\u1e45"}, {{'^', 'u'}, "\u0169"}
	};//unicode latin extended A block
};
