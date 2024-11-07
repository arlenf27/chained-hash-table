#ifndef HASH_TABLE_CHAINED_H
#define HASH_TABLE_CHAINED_H
#define DEFAULT_HASH_TABLE_SIZE 100


template <typename T, typename S>
struct key_value_pair{
	T key;
	S value;
	key_value_pair(T key, S value){
		this->key = key;
		this->value = value;
	}
};

template <typename T, typename S>
struct node{
	key_value_pair<T, S> data;
	node* next;
};

template <typename T, typename S>
class hash_table_chained{
	private: 
		node<T, S>** table;
		unsigned long size;
		unsigned long num_buckets;

	public: 
		hash_table_chained();
		void insert(key_value_pair<T, S> x);
		S retrieve(T key);
		unsigned char member(T key);
		unsigned int hash_code(T key);
		~hash_table_chained();
};

#include "hash_table_chained.tcc"

#endif
