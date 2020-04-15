#include <stdio.h>
#include "reciprocal_div.h"

/*
 * For a description of the algorithm please have a look at
 * include/linux/reciprocal_div.h
 */
#define do_div(n, base) ({						\
			unsigned int __base = (base);					\
			unsigned int __rem;						\
			__rem = ((unsigned long long)(n)) % __base;			\
			(n) = ((unsigned long long)(n)) / __base;			\
			__rem;								\
		})
#define max(x, y) ({				\
			typeof(x) _max1 = (x);			\
			typeof(y) _max2 = (y);			\
			(void) (&_max1 == &_max2);		\
			_max1 > _max2 ? _max1 : _max2; })

#define min(x, y) ({				\
			typeof(x) _min1 = (x);			\
			typeof(y) _min2 = (y);			\
			(void) (&_min1 == &_min2);		\
			_min1 < _min2 ? _min1 : _min2; })


static __always_inline int fls(unsigned int x)
{
		return x ? sizeof(x) * 8 - __builtin_clz(x) : 0;
}


struct reciprocal_value reciprocal_value(u32 d)
{
	struct reciprocal_value R;
	u64 m;
	int l;

	l = fls(d - 1);
	m = ((1ULL << 32) * ((1ULL << l) - d));
	do_div(m, d);
	++m;
	R.m = (u32)m;
	R.sh1 = min(l, 1);
	R.sh2 = max(l - 1, 0);

	return R;
}
