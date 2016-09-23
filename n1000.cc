#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
#include<string>
using namespace std;

void remove(string& s, char c)
{
	string r;
	for(auto& a : s) if(a != c) r += a;
	s = r;
}

int main(int c, char** v)
{ 
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std::string> special_chars = {
		{"!m", "\u1e43"}, {"!s", "\u1e63"}, {"^a", "\u0101"}, {"^i", "\u012b"},
		{"!n", "\u1e47"}
	};
	string file = getenv("HOME");
	file += "/.palidict";
	if(c == 1) {
		cout << "usage : " << v[0] << " [word] : to find" << endl;
		cout << "usage : " << v[0] << " [word] [definition]";
		cout << " : to insert into dictionary" << endl;
	} else if(c == 2) {
		ifstream f(file);
		string word, def;
		while(getline(f, word)) {
			getline(f, def);
			dictionary[word] = def;
		}
		for(auto& a : dictionary) {
			word = a.first;
			def = a.second;
			remove(word, '!');
			remove(word, '^');
			if(word.find(v[1]) != string::npos || def.find(v[1]) != string::npos) {
				for(auto& b : special_chars) 
					a.first.replace(a.first.find(b.first), 2, b.second); 
				cout << a.first << endl << endl << a.second << endl;
			}
		} 
	}else if(c == 3) {
		ofstream f(file, fstream::app);
		f << v[1] << endl << v[2] << endl;
	}
}
