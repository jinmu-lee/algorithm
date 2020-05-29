#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct People
{
	string name;
	int age;
	People(string n, int a) : name(n), age(a) {}
	void Dump() const { cout << name << "(" << age << ")" << endl; }
};
int main()
{
	vector<shared_ptr<People>> v;
	// ("kim", 10), ("lee", 15), ("park", 5), ("jung", 20), ("choi", 12) �� v�� �־��ּ���.
	v.emplace_back(make_shared<People>("kim", 10));
	v.emplace_back(make_shared<People>("lee", 15));
	v.emplace_back(make_shared<People>("park", 5));
	v.emplace_back(make_shared<People>("jung", 20));
	v.emplace_back(make_shared<People>("choi", 12));

	// �̸������� �����ؼ� ����� ������
	sort(v.begin(), v.end(), [](shared_ptr<People> a, shared_ptr<People> &b) {
		return a->name < b->name;
	});
	for (auto data : v) {
		cout << data->name << " , " << data->age << "\n";
	}
	// ���̼����� �����ؼ� ����� ������.
	sort(v.begin(), v.end(), [](shared_ptr<People> a, shared_ptr<People> &b) {
		return a->age < b->age;
	});
	for (auto data : v) {
		cout << data->name << " , " << data->age << "\n";
	}
}