#include <stdio.h>
#include <stdbool.h>
#include "slist.h"

snode* snode_create(int data, snode* next) {
	snode* p = (snode*)malloc(sizeof(snode));
	p->data = data;
	p->next = next;

	return p;
}
slist* slist_create(void) {
	slist* p = (slist*)malocc(sizeof(slist));
	p->head = NULL;
	p->tail = NULL;
	p->size = 0;

	return p;
}
bool slist_empty(slist* list) { return list->size == 0; }
size_t slist_size(slist* list) { return list->size; }

void slist_popfront(slist* list) {
	snode* p = list->head;
	list->head = list->head->next;
	free(p);
	--list->size;
}
void slist_popback(slist* list) {
	snode* p = list->head;
	snode* prev = p;
	while (p->next != NULL) {
		prev = p;
		p = p->next;
	}
	prev->next = NULL;
	free(p);
	list->tail = prev;
	--list->size;
}
void slist_pushfront(slist* list, int data) {
	snode* p = snode_create(data, list->head);
	list->head = p;
	if (list->size == 0) { list->tail = p; }
	++list->size;
}
void slist_pushbac()