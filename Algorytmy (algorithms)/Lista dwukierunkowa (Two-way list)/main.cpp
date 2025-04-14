#include <iostream>

using namespace std;

struct lista{

    int x;
    struct lista* next;
    struct lista* prev;

};

void show(struct lista *a){

    if(a==NULL){
        cout << "LISTA JEST PUSTA!";
    }else{
        struct lista *current=a;
        do{
            if(current->next!=NULL){
            cout << current->x << " <-> ";
            }else{
            cout << current->x << "\n";
            }
            current=current->next;
        }while(current!=NULL);
    }

}

void add(int x, struct lista **a){

    struct lista *current = new struct lista;
    current->x = x;
    current->prev = NULL;
    current->next = NULL;

    if (*a == NULL){
        *a = current;
    }else{
        struct lista *tmp = *a;
        while (tmp->next != NULL && tmp->x < x){
            tmp = tmp->next;
        }
        if (tmp->x < x){
            tmp->next = current;
            current->prev = tmp;
            cout << x << "Warunek a" << endl;
        }else{
            cout << x << "Warunek b" << endl;
            current->next = tmp;
            current->prev = tmp->prev;
            tmp->prev = current;
            if (current->prev != NULL){
                current->prev->next = current;
            }else{
                *a = current;
            }
        }
    }
}

void search_in_list(int x, struct lista *a){
    struct lista *tmp = a;
    int counter = 0;
    while(x!=(*tmp).x){
        if((tmp->next==NULL) && (tmp->x != x)){
            cout << "Nie ma tej liczby (" << x << ") na liœcie!\n";
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

void delete_in_list(int x, struct lista **a){
     struct lista *tmp2 = new struct lista;
     struct lista *tmp = *a;
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

    lista *lista1;
    lista1 = NULL;

    add(3,&lista1); //  DODAWANIE DO LISTY
    add(1,&lista1);
    add(2,&lista1);
    add(5,&lista1);
    add(2,&lista1);

    cout << "Lista po wprowadzeniu danych: ";
    show(lista1);   //  POKAZANIE ZAWARTOSCI

    search_in_list(5,lista1);   // SZUKANIE INDEXU NA KTORYM JEST WARTOSC
    search_in_list(7,lista1);
    search_in_list(2,lista1);

    int liczba = 1;
    delete_in_list(liczba,&lista1);  //  USUWANIE INDEXU O ZADANEJ WARTOSCI
    cout << "Lista po usuniêciu (" << liczba << ") elementu: ";
    show(lista1);

    return 0;
}
