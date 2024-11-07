#include <stdlib.h>
#include "hash_table_chained.h"

template <typename T, typename S>
hash_table_chained<T, S>::hash_table_chained(){
	this->size = 0;
	this->num_buckets = DEFAULT_HASH_TABLE_SIZE;
	this->table = (node<T, S>**) malloc(num_buckets*sizeof(node<T, S>*));
	
	printf("Allocated Memory for table\n");
}

template <typename T, typename S>
hash_table_chained<T, S>::~hash_table_chained(){
	for(int i = 0; i < this->num_buckets; i++){
		while(*(this->table+i) != NULL){
			node<T, S>* temp = (*(this->table+i))->next;
			free(*(this->table+i));

			printf("Deallocated Memory for individual node\n");

			*(this->table+i) = temp;
		}
	}
	free(this->table);

	printf("Deallocated Memory for table\n");
}

template <typename T, typename S>
void hash_table_chained<T, S>::insert(key_value_pair<T, S> x){
	unsigned int bucket = hash_code(x.key);
	node<T, S>* temp = (node<T, S>*) malloc(sizeof(node<T, S>));

	printf("Allocated Memory for individual node\n");
	
	temp->data = x;
	(*(this->table+bucket) == NULL) ? (temp->next = NULL) : (temp->next = *(this->table+bucket));
	*(this->table+bucket) = temp;
}

template <typename T, typename S>
S hash_table_chained<T, S>::retrieve(T key){
	unsigned int bucket = hash_code(key);
	node<T, S>* head = *(this->table+bucket);
	node<T, S>* previous = NULL;
	while(head != NULL){
		if(head->data.key == key){
			S result = head->data.value;
			if(previous != NULL && head->next != NULL){
				previous->next = head->next;
			}else if(previous != NULL){
				previous->next = NULL;
			}else if(head != NULL){
				*(this->table+bucket) = head->next;
			}else{
				*(this->table+bucket) = NULL;
			}
			free(head);

			printf("Deallocated Memory for individual node\n");

			return result;
		}else{
			previous = head;
			head = head->next;
		}
	}
	return 0;
}


template <typename T, typename S>
unsigned char hash_table_chained<T, S>::member(T key){
	unsigned int bucket = hash_code(key);
	node<T, S>* head = *(this->table+bucket);
	while(head != NULL){
		if(head->data.key == key){
			return 1;
		}else{
			head = head->next;
		}
	}
	return 0;
}

template <typename T, typename S>
unsigned int hash_table_chained<T, S>::hash_code(T key){
	return ((unsigned int) key)%this->num_buckets;
}
