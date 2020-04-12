#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)
//# define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __LINE__)
#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
#define __used			__attribute__((__used__))

#define __MODULE_INFO(tag, name, info)					  \
static const char __UNIQUE_ID(name)[]					  \
  __used __attribute__((section(".modinfo"), unused, aligned(1)))	  \
  = __stringify(tag) "=" info
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)
#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)

MODULE_LICENSE("GPL"); MODULE_LICENSE("BSD");

int main()
{
}

