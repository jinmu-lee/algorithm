(1) ��� ��� �� �����Ϸ� �Ͽ����ϴ�.
(2) Display ��� / Hash ��� / List ��� ���� header ������ ����� �����Ͽ����ϴ�.
	(2.1) Display ���
		(2.1.1) void __display_removal(struct hlist_head *page_htable,struct list_head *lru_head,int *page_count);
			- List �� 20���� Page �� ��� á�� ��� ����ϴ� �Լ�
			- List �� �� �ڿ� �ִ� Page�� ����
		(2.1.2) void __display_add_newpage(struct hlist_head *page_htable,struct list_head *lru_head,
							LRU *list_pages,PAGE *table_pages,int *page_count);
			- ���ο� Page �� ��������� ������ �ִ� Page ���� �˻� �� �߰�
			- ������ �ִ� Page �̸� �� ������ �̵���Ŵ
			- ���� Page �̸� �� �տ� �߰���Ŵ
		(2.1.3) void __display_htable(struct hlist_head *page_htable);
			- hash table ��� ������ ���
		(2.1.4) void __display_list(struct list_head *lru_head);
			- List ��� ������ ���
	(2.2) Hash ���
		(2.2.1) void hlist_add_head(struct hlist_node *n,struct hlist_head *h)
			- Hash Table �� Bucket�� hash�� node�� �տ� �߰�
		(2.2.2) void hlist_del(struct hlist_node *n)
			- ���� ��ġ�� hash node�� ����
		(2.2.3) PAGE* hlist_find_key(struct hlist_head *heads,int pfn)
			- Hash Table �� Bucket���� page �� �ִ��� �˻�
		(2.2.4) unsigned int hash_32(unsigned int val,unsigned int bits)
			- Hash Function / GOLDEN_RATIO_PRIME_32 ���� ���� �� Ư�� bit ����
		(2.2.5) unsigned int hash_func(unsigned int num)
			- Hash Function �� Wrapper �Լ�
	(2.3) List ���
		(2.3.1) void __list_add(struct list_head *new,struct list_head *prev,struct list_head *next)
			- list �� �߰�
		(2.3.2) void list_add(struct list_head *new,struct list_head *head)
			- list �� �պκп� �߰��ϵ��� __list_add �Լ��� ȣ��
		(2.3.3) void __list_del(struct list_head * prev, struct list_head * next)
			- list ���� ����
		(2.3.4) void list_del(struct list_head *entry)
			- ���� ����� �հ� ���� �����͸� __list_del �Ѱ��־� list ���� ����

(3) ��Ʊ� ������ Kernel ���� ����ϴ� ����Ʈ�� �ؽ��� ����� �����ϰ� ���� ����� ���� �� �־� ������ �ð��̾����ϴ�.
		