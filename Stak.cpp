#include <stdio.h>;
#include <iostream>;

struct element { 
	int Data; 
	element* next;
};

void push_element(element** top, int D) { 
	element* q; 
	q = new element(); 
	q->Data = D; 
	if (top == NULL) { 
		*top = q; 
	}
	else 
	{
		q->next = *top;
		*top = q; 
	}
}

int pop_element(element ** top, int N) {
	element* q = *top; 
	element* prev_element = NULL;
	while (q != NULL) {
		if (q->Data == N) {
			if (q == *top) {
				*top = q->next;
				free(q);
				return q->Data; 
			}
			else
			{
				prev_element->next = q->next;
				free(q);
				return q->Data;
			}
		}
		prev_element = q; 
		q = q->next;
		
	}

}

void pop_stak(element** top)
{
	if (*top == 0) return;
	element* p = *top;
	element* t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;

	}
	*top = NULL;
}

void print_stak(element* top) {
	element* q = top;
	if (top == 0) {
		printf_s("Stak havn't elements\n");
		return;
	}
	else {
		while (q) {
			printf_s("%i ", q->Data);
			q = q->next;
		}
	}
}




void main() {
	element* top = NULL;
	push_element(&top, 5);
	push_element(&top, 4);
	push_element(&top, 3);
	push_element(&top, 2);
	push_element(&top, 1);
	
	print_stak(top);
	pop_element(&top, 2); 
	printf_s("\n");
	print_stak(top);
	pop_stak(&top);
	printf_s("\n");
	print_stak(top);
	
}


