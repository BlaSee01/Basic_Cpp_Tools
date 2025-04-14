#include <iostream>

using namespace std;

#define SIZE 30

struct HashTable_item
{
    string word;
    HashTable_item* next;
};

struct HashTable
{
    int size;
    HashTable_item** table;
};

unsigned int start(const string word)
{
    unsigned int h = 0, i;
    int word_length = word.length();
    for (i = 0; i < word_length; i++)
    {
        h = 31 * h + word[i] - 65; // SUMA ASCII W SLOWIE
    }
    return h;
}

void add_word(HashTable* ht, string word)
{
    unsigned int hash = start(word) % ht->size;
    HashTable_item* new_node = new HashTable_item;
    new_node->word = word;
    new_node->next = ht->table[hash];
    ht->table[hash] = new_node;
}

void display_table(HashTable *ht)
{
    int i;
    for (i = 0; i < ht->size; i++)
    {
        HashTable_item *item = ht->table[i];
        cout << "INDEX[" << i << "]: ";
        while (item != NULL)
        {
            cout << item->word << " ";
            item = item->next;
        }
        cout << endl;
    }
}

HashTable_item *last_found_item = NULL;
unsigned int last = 0;

HashTable_item *find_word(HashTable *ht, string word)
{
    unsigned int hash = start(word) % ht->size;
    if (last_found_item != NULL && last == hash && last_found_item->word == word)
    {
        return last_found_item;
    }

    HashTable_item *item = ht->table[hash];
    while (item != NULL)
    {
        if (item->word == word)
        {
            last_found_item = item;
            last = hash;
            return item;
        }
        item = item->next;
    }
    return NULL;
}

void delete_word(HashTable *ht, string word)
{
    unsigned int hash = start(word) % ht->size;
    HashTable_item *item = ht->table[hash];
    HashTable_item *prev_item = NULL;
    while (item != NULL)
    {
        if (item->word == word)
        {
            if (prev_item == NULL)
            {
                ht->table[hash] = item->next;
            }
            else
            {
                prev_item->next = item->next;
            }
            delete item;
            return;
        }
        prev_item = item;
        item = item->next;
    }
}
int main()
{

    setlocale(LC_ALL, "");

    HashTable h;
    h.size = SIZE;
    h.table = (HashTable_item **) calloc(h.size, sizeof(HashTable_item *));

    add_word(&h, "ala");
    add_word(&h, "ola");
    add_word(&h, "lala");
    add_word(&h, "wymagajace_slowo");
    add_word(&h, "xyz");

    display_table(&h);

    delete_word(&h, "xyz");

    cout << endl << "Po usuniêciu 'xyz': " << endl << endl;

    display_table(&h);

    cout << endl;

    HashTable_item* item = find_word(&h, "nie_ma_takiego");

    item = find_word(&h, "xyz");

    if (item != NULL)
    {
        printf("WORD FOUND\n");
    }
    else
    {
        printf("WORD NOT FOUND\n");
    }


    if (item != NULL)
    {
        printf("WORD FOUND\n");
    }
    else
    {
        printf("WORD NOT FOUND\n");
    }

    item = find_word(&h, "wymagajace_slowo");
    if (item != NULL)
    {
        printf("WORD FOUND\n");
    }
    else
    {
        printf("WORD NOT FOUND\n");
    }


    for (int i = 0; i < h.size; i++)
    {
        HashTable_item *item = h.table[i];
        while (item != NULL)
        {
            HashTable_item *temp = item;
            item = item->next;
            free(temp);
        }
    }

    free(h.table);

    return 0;
}
