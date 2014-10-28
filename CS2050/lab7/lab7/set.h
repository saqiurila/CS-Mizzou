/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 22
*/
#ifndef SET_H_
#define SET_H_

typedef struct Set_{
	int data;
	struct Set_* next;
}Set;

Set* set_insert(Set* list,int data);
Set* set_remove(Set* list,int data);
Set* set_intersection(Set* first,Set* second);
void print_list(Set* list);
void free_list(Set* list);

#endif