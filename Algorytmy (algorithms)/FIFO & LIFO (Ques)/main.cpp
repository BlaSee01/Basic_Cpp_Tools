#include <iostream>

using namespace std;

struct FIFO{

    int x;
    struct FIFO* next;
    struct FIFO* prev;

};

struct LIFO{

    int x;
    struct LIFO* next;
    struct LIFO* prev;

};

void show(struct FIFO *a){

    if(a==NULL){
        cout << "FIFO JEST PUSTA!";
    }else{
        struct FIFO *current = a;
        do{
            if(current->next!=NULL){
            cout << current->x << " <-> ";
            }else{
            cout << current->x;
            }
            current=current->next;
        }while(current!=NULL);
    }
    cout << " [WYJŒCIE Z KOLEJKI]\n";
}

void showLIFO(struct LIFO *a){

    if(a==NULL){
        cout << "LIFO JEST PUSTA!";
    }else{
        cout << "[WYJŒCIE Z KOLEJKI] ";
        struct LIFO *current = a;
        do{
            if(current->next!=NULL){
            cout << current->x << " <-> ";
            }else{
            cout << current->x;
            }
            current=current->next;
        }while(current!=NULL);
    }
    cout << "\n";
}

void add(int x, struct FIFO **a){

    struct FIFO *current = new struct FIFO;
    current->x = x;
    current->prev = NULL;
    current->next = NULL;

    if (*a == NULL){
        *a = current;
    }else{
        current->next = *a;
        (*a)->prev = current;
    }
    *a = current;
    cout << "Dodano: " << x << " do kolejki!\n";
}

void addLIFO(int x, struct LIFO **a){

    struct LIFO *current = new struct LIFO;
    current->x = x;
    current->prev = NULL;
    current->next = NULL;

    if (*a == NULL){
        *a = current;
    }else{
        current->next = *a;
        (*a)->prev = current;
    }
    *a = current;
    cout << "Dodano: " << x << " do kolejki!\n";
}

void search_in_fifo(int x, struct FIFO *a){

    struct FIFO *tmp = a;
    int counter = 0;
    while(x!=(*tmp).x){
        if((tmp->next==NULL) && (tmp->x != x)){
            cout << "Nie ma tej liczby (" << x << ") w kolejce!\n";
            break;
        }
        counter++;
        tmp = tmp->next;
    }
    if((tmp->next==NULL) && (tmp->x != x)){

    }else{
        cout << "Szukana wartoœæ (" << x << ") zosta³a znaleziona na " << counter << " indeksie!\n";
    }
}

void delete_from_fifo(struct FIFO **a){
    struct FIFO *tmp = *a;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    (tmp->prev)->next = NULL;
    tmp = NULL;
}

void delete_from_lifo(struct LIFO **a){
    if(a!=NULL){
    *a = (*a)->next;
    }
}

void delete_exact_value(int x, struct FIFO **a){
     struct FIFO *tmp2 = new struct FIFO;
     struct FIFO *tmp = *a;
     while(x!=tmp->x && tmp != NULL){
        tmp=tmp->next;
     }
     if(tmp->prev==NULL){
         *a = tmp->next;
        (tmp->next)->prev = NULL;
     }else if(tmp->next!=NULL){
        tmp2 = tmp->prev;
        (tmp->next)->prev = tmp2;
        tmp2->next = tmp->next;
     }else if(tmp->next==NULL){
        (tmp->prev)->next = NULL;
     }
    delete tmp;
    delete tmp2;
}

int main()
{
    setlocale(LC_ALL, "");

    FIFO *FIFO1;
    FIFO1 = NULL;

    add(3,&FIFO1); //  DODAWANIE DO LISTY
    add(1,&FIFO1);
    add(2,&FIFO1);
    add(5,&FIFO1);
    add(2,&FIFO1);

    cout << "FIFO po wprowadzeniu danych: ";
    show(FIFO1);   //  POKAZANIE ZAWARTOSCI

    search_in_fifo(5,FIFO1);   // SZUKANIE INDEXU NA KTORYM JEST WARTOSC
    search_in_fifo(7,FIFO1);
    search_in_fifo(2,FIFO1);

    cout << "FIFO po opusczeniu kolejki przez najd³u¿ej czekaj¹cy element: ";
    delete_from_fifo(&FIFO1);   //  OPUSCZENIE KOLEJKI PRZEZ ELEMENT
    show(FIFO1);

    LIFO *LIFO1;
    LIFO1 = NULL;

    addLIFO(3,&LIFO1); //  DODAWANIE DO LISTY
    addLIFO(1,&LIFO1);
    addLIFO(2,&LIFO1);
    addLIFO(5,&LIFO1);
    addLIFO(4,&LIFO1);

    cout << "LIFO po wprowadzeniu danych: ";
    showLIFO(LIFO1);

    delete_from_lifo(&LIFO1);

    cout << "LIFO po usunieciu elementu: ";
    showLIFO(LIFO1);

    return 0;
}
