#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << "format : preprocessor input.txt result.txt\n";
		return 0;
	}
	ifstream ifs(argv[1]);
	ofstream ofs(argv[2]);
	unordered_map<string, int> kv, var;
	string s;
	while (getline(ifs, s)) // 파일에서 한줄 읽기
	{
		istringstream iss(s);
		string word;
		while (iss >> word)
		{
			if (word.compare("define") == 0) continue;
			if (word.compare("MAX") == 0 || word.compare("MIN") == 0) {
				string value;
				iss >> value;
				kv[word] = std::stoi(value);
			}
			else {
				string value;
				iss >> value; value.clear();
				iss >> value;
				var[word] = kv[value];
			}
		}
	}
	//---------------------------
	auto p = begin(var);
	while (p != end(var))
	{
		ofs << p->first << " = " << p->second << "\n";
		++p;
	}
}