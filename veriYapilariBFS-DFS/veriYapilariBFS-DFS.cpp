#include <iostream>
#include "veri.h"

void menu();


int main()
{
    //menu();

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
    

void IkiliSiralamaAgaci::agacKur(int*)
{

}

void IkiliSiralamaAgaci::agacKapat()
{

}

bool DFS(Dugum*, int)
{
    return false;
}

bool BFS(Dugum*, int)
{
    return false;
}
