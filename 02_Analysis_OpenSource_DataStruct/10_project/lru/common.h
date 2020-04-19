#pragma once
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_PAGES 20
#define PAGE_FRAME_MAX_NUM 40
#define container_of(ptr,type,member) \
	(type *)((char *)ptr - (unsigned long)&((type *)0)->member)

#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

#define hlist_for_each(pos, head) \
	for (pos = (head)->first; pos ; pos = pos->next)
