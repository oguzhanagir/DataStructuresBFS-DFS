#include <iostream>
#include "veri.h"

void menu();
typedef IkiliSiralamaAgaci veriYapisi;
veriYapisi bst;
Dugum node;

int main()
{
    //menu();
   

    for (size_t i = 0; i < UZUNLUK; i++)
    {
        
        bst.kok = bst.agacKur(bst.kok,&dizi1[i]);
    }

}

void menu() {
    system("CLS");

    int agacSecim;
    int yöntem;
    int deger;
    std::cout << "Arama yapacaginiz agaci seciniz (1,2,3):\n";
    std::cin >> agacSecim;
    std::cout << "\nAgac " << agacSecim << " icin arama yontemini seciniz (DFS:1, BFS:2):\n";
    std::cin >> yöntem;

    if (yöntem == 1)
    {
        std::cout << "\nAgac " << agacSecim << " uzerinde DFS ile arayacaginiz degeri giriniz:\n";
        std::cin >> deger;

    }
    else if(yöntem == 2)
    {
        std::cout << "\nAgac " << agacSecim << " uzerinde BFS ile arayacaginiz degeri giriniz:\n";
        std::cin >> deger;

    }

    std::cout << "\nSONUC => ";
    std::cout << "\nGECEN SURE => ";
}
   


Dugum* IkiliSiralamaAgaci::agacOlustur(int deger)
{
    bst.kok = (struct Dugum*)malloc(sizeof(struct Dugum));
    bst.kok->veri = deger;
    bst.kok->sol = NULL;
    bst.kok->sag = NULL;

    return kok;

}



Dugum* IkiliSiralamaAgaci::agacKur(Dugum* root, int* deger)
{
    if (kok == NULL)
    {
        return agacOlustur(*deger);
    }

    if (*deger < root->veri)
    {
        root->sol = agacKur(root->sol,deger);
    }
    else
    {
        root->sag = agacKur(root->sag, deger);
    }
    
    return root;
}

void IkiliSiralamaAgaci::agacKapat()
{

}

bool DFS(Dugum* agacKok, int deger)
{
    return false;
}

bool BFS(Dugum* agacKok, int deger)
{
    return false;
}
