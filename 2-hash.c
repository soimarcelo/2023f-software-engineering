#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashItem;

typedef struct {
    HashItem** items;
} HashTable;

// ハッシュテーブルの初期化
HashTable* createHashTable() {
    HashTable* table = malloc(sizeof(HashTable));
    table->items = malloc(sizeof(HashItem*) * TABLE_SIZE);

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->items[i] = NULL;
    }

    return table;
}

// ハッシュ関数
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ハッシュテーブルに要素を挿入
void insert(HashTable* table, int key, int value) {
    HashItem* item = malloc(sizeof(HashItem));
    item->key = key;
    item->value = value;

    int hashIndex = hashFunction(key);

    while (table->items[hashIndex] != NULL && table->items[hashIndex]->key != key) {
        hashIndex++;
        hashIndex %= TABLE_SIZE;
    }

    table->items[hashIndex] = item;
}

// ハッシュテーブルから要素を検索
int search(HashTable* table, int key) {
    int hashIndex = hashFunction(key);

    while (table->items[hashIndex] != NULL) {
        if (table->items[hashIndex]->key == key)
            return table->items[hashIndex]->value;

        hashIndex++;
        hashIndex %= TABLE_SIZE;
    }

    return -1; // 要素が見つからない場合
}

int main() {
    HashTable* ht = createHashTable();
    insert(ht, 1, 20);
    insert(ht, 2, 70);
    insert(ht, 42, 80);

    printf("Key: 1, Value: %d\n", search(ht, 1));
    printf("Key: 2, Value: %d\n", search(ht, 2));
    printf("Key: 42, Value: %d\n", search(ht, 42));

    // ハッシュテーブルの解放
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->items[i] != NULL) {
            free(ht->items[i]);
        }
    }
    free(ht->items);
    free(ht);

    return 0;
}
