#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
#include<string>
#include"pali.h"
using namespace std;

void remove(string& s, char c)
{
	string r;
	for(auto& a : s) if(a != c) r += a;
	s = r;
}

bool Pali_dic::is_special_character(char c)
{
	for(auto& a : special_chars) if(a.first.first == c) return true;
	return false;
}

Pali_dic::Pali_dic(string file)
{
	ifstream f(file);
	string word, def;
	while(getline(f, word)) {
		getline(f, def);
		dictionary[word] = def;
	}
}

int Pali_dic::search(const char* s)
{
	for(auto& a : dictionary) {
		string word = a.first;
		string def = a.second;
		for(auto& a : special_chars) remove(word, a.first.first);
		string output;
		if(word.find(s) != string::npos || def.find(s) != string::npos) {
			for(auto& c : a.first) {
				char tmp;
				if(is_special_character(tmp)) {
					output += special_chars[{tmp, c}];
				} else if(!is_special_character(c)) output += c;
				tmp = c;
			}
			cout << output << " : " << a.second << endl;
		}
	}
}

int main(int c, char** v)
{ 
	string file = getenv("HOME");
	file += "/.palidict";
	if(c == 1) {
		cout << "usage : " << v[0] << " [word] : to find" << endl;
		cout << "usage : " << v[0] << " [word] [definition]";
		cout << " : to insert into dictionary" << endl;
	} else if(c == 2) {
		Pali_dic pd(file);
		pd.search(v[1]);
	} else if(c == 3) {
		ofstream f(file, fstream::app);
		f << v[1] << endl << v[2] << endl;
	}
}
