#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "expr_assert.h"

void test_create_node_returns_a_node_variable_that_contains_data_and_pointer_to_null(){
	int a = 5;
	NodePtr node = create_node(&a);
	assertEqual(*(int *)node->data, 5);
	free(node);
}

void test_add_to_list_returns_1_if_it_adds_the_node_to_the_list() {
	int a = 5;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	int isAdd = add_to_list(&list, node);
	assertEqual(isAdd, 1);
	free(node);
}
void test_create_list_returns_list_with_null_in_head_and_tail_and_0_in_count_fields(){
	LinkedList list = createList();
	assertEqual((int)list.head, 0);
	assertEqual((int)list.tail, 0);
	assertEqual(list.count, 0);	
}

void addOne(void *data){
	int *a = data;
	(*a)++;
}

void test_traverse_performs_operation_on_each_node_of_the_list(){
	int a = 5,b = 10;
	LinkedList list = createList();
	NodePtr node1 = create_node(&a);
	NodePtr node2 = create_node(&b);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	traverse(list, &addOne);
	assertEqual(*(int *)(list.head->data), 6);
	assertEqual(*(int *)(list.tail->data), 11);
}
void test_get_first_element_gives_the_address_of_the_first_element_in_the_list(){
	int a = 5;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	add_to_list(&list, node);
	assertEqual(*(int *)(get_first_element(list)), 5);
}
void test_get_last_element_gives_the_address_of_the_last_element_in_the_list(){
	int a = 5;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	add_to_list(&list, node);
	assertEqual(*(int *)(get_last_element(list)), 5);
}
void test_getElementAt_returns_the_pointer_to_the_node_at_the_particulat_index(){
	int a = 5, b = 10;
	int *result;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	NodePtr node1 = create_node(&b);
	add_to_list(&list, node);
	add_to_list(&list, node1);
	result = getElementAt(list, 1);
	assertEqual(*result, 10);
}

void test_indexOf_returns_the_index_of_the_element_in_the_list(){
	int a = 5, b = 10;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	NodePtr node1 = create_node(&b);
	add_to_list(&list, node);
	add_to_list(&list, node1);
	assertEqual(indexOf(list, &a), 0);
}

void test_indexOf_returns_minus_1_if_the_element_is_not_in_the_list(){
	int a = 5, b = 10;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	add_to_list(&list, node);
	assertEqual(indexOf(list, &b), -1);
}

void test_deleteElementAt_deletes_the_element_and_returns_the_pointer_to_the_new_item_in_the_index(){
	int a = 5, b = 10;
	LinkedList list = createList();
	NodePtr node = create_node(&a);
	NodePtr node1 = create_node(&b);
	NodePtr node2 = create_node(&a);
	NodePtr result;
	add_to_list(&list, node);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	result = deleteElementAt(&list, 1);
	assertEqual(result,node2);
	assertEqual(list.count,2);
}