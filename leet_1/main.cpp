#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

// long int getNum (ListNode* l) {
//     long int num = 0;
//     long int times = 1;
//     while (l) {
//         num += l->val * times;
//         l = l->next;
//         times *= 10;
//     }
//     cout<<num<<endl;
//     return num;
// }

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     long int sum = getNum(l1) + getNum(l2);
//     cout<<sum<<endl;
//     ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
//     ret->val = sum % 10;
//     sum = sum / 10;
//     ret->next = NULL;
//     ListNode* curr = ret;
//     while (sum) {
//         ListNode* next = (ListNode*)malloc(sizeof(ListNode));
//         next->val = sum % 10;
//         next->next = NULL;
//         curr->next = next;
//         curr = next;
//         sum = sum / 10;
//     }
//     return ret;
// }

ListNode* createList(int arr[], int count) {
	ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
	ret->val = arr[0];
	ret->next = NULL;
	ListNode* curr = ret;
	for(int i = 1; i < count; i++) {
		ListNode* next = (ListNode*)malloc(sizeof(ListNode));
		next->val = arr[i];
		next->next = NULL;
		curr->next = next;
		curr = next;
	}
	return ret;
}

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// 	ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
// 	int sum = l1->val + l2->val;
// 	bool overflow = !!(sum / 10);
// 	ret->val = sum % 10;
// 	ret->next = NULL;
// 	ListNode* curr = ret;
// 	l1 = l1->next;
// 	l2 = l2->next;
// 	while (l1 && l2) {
// 		ListNode* next = (ListNode*)malloc(sizeof(ListNode));
// 		sum = l1->val + l2->val;
// 		next->val = sum % 10 + (int)overflow;
// 		overflow = !!(sum / 10);

// 		curr->next = next;
// 		curr = next;
// 	}

// 	if (l1 == NULL) {
// 		ListNode* next = (ListNode*)malloc(sizeof(ListNode));
// 		next->val = l2->val + (int)overflow;
// 		while
// 	}

// 	return	ret;
// }

// ListNode* createNode(int val1, int val2, bool *overflow) {
// 	int sum	= val1 + val2;
// 	ListNode* ret = new ListNode(sum % 10 + (int)*overflow);
// 	*overflow = !!(sum / 10);
// 	return ret;
// }

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// 	bool overflow = false;
// 	ListNode* ret = createNode(l1->val, l2->val, &overflow);
// 	l1 = l1->next;
// 	l2 = l2->next;
// 	ListNode* curr = ret;
// 	while (l1 && l2) {
// 		curr->next = createNode(l1->val, l2->val, &overflow);
// 		l1 = l1->next;
// 		l2 = l2->next;
// 		curr = curr->next;
// 	}

// 	if (l1 != NULL && l2 == NULL) {
// 		curr->createNode(l1->val, 0, &overflow);
// 		l1 = l1->next;
// 		curr = curr->next;
// 		while (l1) {
// 			curr->
// 		}
// 	}
// 	return ret;
// }

ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, bool* overflow) {
	if (l1 == NULL && l2 == NULL) {
		if (*overflow)
			return new ListNode(1);
		else return NULL;
	}

	int sum = 0;
	if (l1 == NULL && l2 != NULL) {
		sum = l2->val + (int)(*overflow);
		l2 = l2->next;
	} else if (l1 != NULL && l2 == NULL) {
		sum = l1->val + (int)(*overflow);
		l1 = l1->next;
	} else if (l1 != NULL && l2 != NULL) {
		sum = l1->val + l2->val + (int)(*overflow);
		l1 = l1->next;
		l2 = l2->next;
	}

	ListNode* ret = new ListNode(sum % 10);
	*overflow = !!(sum / 10);
	ret->next = addTwoNumbersHelper(l1, l2, overflow);
	return ret;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	bool overflow = false;
	return addTwoNumbersHelper(l1, l2, &overflow);
}


int main() {
	int arr1[] = {9};
	int arr2[] = {1,9,9,9,9,9,9,9,9,9,9,9,9};

	ListNode* l1 = createList(arr1, _countof(arr1));
	ListNode* l2 = createList(arr2, _countof(arr2));

	ListNode* l = addTwoNumbers(l1, l2);

	while (l) {
		cout<<l->val<<'\t';
		l = l->next;
	}
	cout<<endl;

	return 0;
}