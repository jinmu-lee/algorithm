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

	// Register 의 3번째 인자는 우선순위, 4번째 인자는 스레드사용여부 입니다.
	// 우선순위 1일 제일 낮고, 3일 제일 높다가 가정합니다.
	// NEW_THREAD 지정시 해당 함수는 새로운 스레드로 동작해야 합니다.
	nc.Register("TEST_EVENT", bind(&foo, _1, "one"s), 1);
	nc.Register("TEST_EVENT", bind(&foo, _1, "two"s), 2, NEW_THREAD);
	nc.Register("TEST_EVENT", bind(&foo, _1, "three"s), 3);
	nc.Notify("TEST_EVENT", (void*)0); // 등록된 순서가 아닌 우선순위가

	// 높은 순서로 실행되게 해주세요
	// NEW_THREAD 옵션을 가진 경우. 새로운
	// 스레드로 해당 함수를 동작되게 해주세요.
}

