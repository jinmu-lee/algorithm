#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>
using namespace std;
using namespace std::placeholders;

class NotificationCenter
{
    using HANDLER = function<void(void*)>;

    map<string, vector<HANDLER>> notif_map;
public:
    void Register(string key, HANDLER h)
    {
        notif_map[key].push_back(h);
    }
    void Notify( string key, void* param)
    {
        vector<HANDLER>& v = notif_map[key];

        for( auto f : v)
            f(param);
    }
};

//void f1(void* p) { cout << "f1" << endl;}
//void f2(void* p, int a, int b) { cout << "f2" << endl;}

void foo(void* p, string name)
{
	cout << name << " : " << this_thread::get_id() << endl;
	this_thread::sleep_for(3s);
	cout << name << " end" << endl;
}

int main()
{
    NotificationCenter nc;
//    nc.Register("CONNECT_WIFI", &f1);
//    nc.Register("CONNECT_WIFI", bind(&f2, _1, 0, 0) );
//    nc.Notify("CONNECT_WIFI", (void*)0);

	// Register �� 3��° ���ڴ� �켱����, 4��° ���ڴ� �������뿩�� �Դϴ�.
	// �켱���� 1�� ���� ����, 3�� ���� ���ٰ� �����մϴ�.
	// NEW_THREAD ������ �ش� �Լ��� ���ο� ������� �����ؾ� �մϴ�.
	nc.Register("TEST_EVENT", bind(&foo, _1, "one"s), 1);
	nc.Register("TEST_EVENT", bind(&foo, _1, "two"s), 2, NEW_THREAD);
	nc.Register("TEST_EVENT", bind(&foo, _1, "three"s), 3);
	nc.Notify("TEST_EVENT", (void*)0); // ��ϵ� ������ �ƴ� �켱������

	// ���� ������ ����ǰ� ���ּ���
	// NEW_THREAD �ɼ��� ���� ���. ���ο�
	// ������� �ش� �Լ��� ���۵ǰ� ���ּ���.
}

