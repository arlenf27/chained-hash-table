#include <stdio.h>
#include "hash_table_chained.h"

void test_insert_member_retrieve();

int main(){
	test_insert_member_retrieve();
	return 0;
}

void test_insert_member_retrieve(){
	hash_table_chained<int, int> table = hash_table_chained<int, int>();
	printf("Inserting (0, 5)\n");
	table.insert(key_value_pair<int, int>(0, 5));
	printf("Inserting (254354, 434)\n");
	table.insert(key_value_pair<int, int>(254354, 434));
	printf("Inserting (2354, 34)\n");
	table.insert(key_value_pair<int, int>(2354, 34));
	printf("Inserting (254, 43)\n");
	table.insert(key_value_pair<int, int>(254, 43));
	printf("Inserting (100, 78)\n");
	table.insert(key_value_pair<int, int>(100, 78));
	printf("Inserting (154354, 4)\n");
	table.insert(key_value_pair<int, int>(154354, 4));
	printf("Testing member(0): %d\n", table.member(0));
	printf("Testing member(100): %d\n", table.member(100));
	printf("Testing member(5): %d\n", table.member(5));
	printf("Testing member(254354): %d\n", table.member(254354));
	printf("Testing member(254): %d\n", table.member(254));
	printf("Testing member(32): %d\n", table.member(32));
	printf("Retrieved (100, %d)\n", table.retrieve(100));
	printf("Retrieved (0, %d)\n", table.retrieve(0));
	printf("Retrieved (254354, %d)\n", table.retrieve(254354));
	printf("Testing member(254354): %d\n", table.member(254354));
	printf("Testing member(0): %d\n", table.member(0));
	printf("Testing member(100): %d\n", table.member(100));
}
