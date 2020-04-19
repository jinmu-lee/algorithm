(1) 모든 기능 다 구현완료 하였습니다.
(2) Display 기능 / Hash 기능 / List 기능 별로 header 파일을 나누어서 구현하였습니다.
	(2.1) Display 기능
		(2.1.1) void __display_removal(struct hlist_head *page_htable,struct list_head *lru_head,int *page_count);
			- List 에 20개의 Page 가 모두 찼을 경우 출력하는 함수
			- List 의 맨 뒤에 있는 Page를 삭제
		(2.1.2) void __display_add_newpage(struct hlist_head *page_htable,struct list_head *lru_head,
							LRU *list_pages,PAGE *table_pages,int *page_count);
			- 새로운 Page 가 만들어지고 기존에 있는 Page 인지 검사 및 추가
			- 기존에 있는 Page 이면 맨 앞으로 이동시킴
			- 없는 Page 이면 맨 앞에 추가시킴
		(2.1.3) void __display_htable(struct hlist_head *page_htable);
			- hash table 모든 내용을 출력
		(2.1.4) void __display_list(struct list_head *lru_head);
			- List 모든 내용을 출력
	(2.2) Hash 기능
		(2.2.1) void hlist_add_head(struct hlist_node *n,struct hlist_head *h)
			- Hash Table 의 Bucket에 hash의 node를 앞에 추가
		(2.2.2) void hlist_del(struct hlist_node *n)
			- 현재 위치의 hash node를 삭제
		(2.2.3) PAGE* hlist_find_key(struct hlist_head *heads,int pfn)
			- Hash Table 의 Bucket에서 page 가 있는지 검사
		(2.2.4) unsigned int hash_32(unsigned int val,unsigned int bits)
			- Hash Function / GOLDEN_RATIO_PRIME_32 값을 곱한 후 특정 bit 추출
		(2.2.5) unsigned int hash_func(unsigned int num)
			- Hash Function 의 Wrapper 함수
	(2.3) List 기능
		(2.3.1) void __list_add(struct list_head *new,struct list_head *prev,struct list_head *next)
			- list 에 추가
		(2.3.2) void list_add(struct list_head *new,struct list_head *head)
			- list 의 앞부분에 추가하도록 __list_add 함수를 호출
		(2.3.3) void __list_del(struct list_head * prev, struct list_head * next)
			- list 에서 삭제
		(2.3.4) void list_del(struct list_head *entry)
			- 현재 노드의 앞과 뒤의 포인터를 __list_del 넘겨주어 list 에서 삭제

(3) 어렵긴 했지만 Kernel 에서 사용하는 리스트와 해시의 기능을 온전하게 저의 기술로 만들 수 있어 보람된 시간이었습니다.
		