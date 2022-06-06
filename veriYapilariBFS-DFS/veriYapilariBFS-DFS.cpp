#include <iostream>
#include "veri.h"
#include <chrono>

#include <queue> //Kuyruk Veri Yap�s�
#include <stack> //Y���n Veri Yap�s�

using namespace std;



typedef IkiliSiralamaAgaci veriYapisi;
veriYapisi bst;
Dugum node;

struct menu {
    int agacSecim;
    int y�ntem;
    int deger;
    bool aramaY�ntemi(int secim, int deger);
    bool diziSecim();
    void menuYazdir();
}m;

int main()
{
    m.menuYazdir(); //Men� Yazd�r�l�r
    
    auto begin = std::chrono::high_resolution_clock::now();
    if (m.diziSecim() == true)// Dizi Se�imi Ger�ekle�tirilir
    {
        std::cout << "Sonuc => Veri Bulundu.\n";
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << "Gecen S�re =>" << elapsed.count() << " mikro-saniye";
    } 
    else
    {
        std::cout << "Sonuc => Veri Bulunamadi\n.";
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << "Gecen Sure =>" << elapsed.count() << " mikro-saniye";
    }
    
    bst.agacKapat(bst.kok);
    
    
}

void menu::menuYazdir() {
    system("CLS");

    
    std::cout << "Arama yapacaginiz agaci seciniz (1,2,3):\n";
    std::cin >> m.agacSecim;


    std::cout << "\nAgac " << m.agacSecim << " icin arama yontemini seciniz (DFS:1, BFS:2):\n";
    std::cin >> m.y�ntem;

    if (m.y�ntem == 1)
    {
        std::cout << "\nAgac " << m.agacSecim << " uzerinde DFS ile arayacaginiz degeri giriniz:\n";
        std::cin >> m.deger;

    }
    else if(m.y�ntem == 2)
    {
        std::cout << "\nAgac " << m.agacSecim << " uzerinde BFS ile arayacaginiz degeri giriniz:\n";
        std::cin >> m.deger;

    }

    
}
 
bool menu::aramaY�ntemi(int secim, int deger)
{
    if (secim == 1 )
    {
        return DFS(bst.kok, deger);
        //DFS Se�imi
    }
    else
    {
        return BFS(bst.kok, deger);
        //BFS Se�imi
    }
}

bool menu::diziSecim()
{
    if (m.agacSecim == 1)  //Dizi 1 Se�imi
    {
        for (size_t i = 0; i < UZUNLUK; i++)
        {
            bst.agacKur(bst.kok, &dizi1[i]);
        }
        return m.aramaY�ntemi(m.y�ntem, m.deger);
    }
    else if (m.agacSecim == 2) //Dizi 2 Se�imi
    {
        for (size_t i = 0; i < UZUNLUK; i++)
        {
            bst.agacKur(bst.kok, &dizi2[i]);
        }
        return m.aramaY�ntemi(m.y�ntem, m.deger);
    }
    else //Dizi 3 Se�imi
    {
        for (size_t i = 0; i < UZUNLUK; i++)
        {
            bst.agacKur(bst.kok, &dizi3[i]);
        }
        return m.aramaY�ntemi(m.y�ntem, m.deger);
    }
}

Dugum* IkiliSiralamaAgaci::agacOlustur(int deger)
{
    bst.kok = (struct Dugum*)malloc(sizeof(struct Dugum));
    kok->veri = deger;
    kok->sol = NULL;
    kok->sag = NULL;

    return kok;

}

Dugum* IkiliSiralamaAgaci::agacKur(Dugum* root,int *deger)
{
    if (root == NULL)
    {
        return  agacOlustur(*deger);
    }
    else if (*deger <=root->veri)
    {
        root->sol = agacKur(root->sol, deger);
    }
    else
    {
        root->sag = agacKur(root->sol, deger);
    }

    return root;
}


void IkiliSiralamaAgaci::agacKapat(Dugum* temp)
{
    if (temp)
    {
        if (temp->sol != NULL)
        {
            agacKapat(temp->sol);
            temp->sol = NULL;
        }
        
        if (temp->sag !=NULL)
        {
            agacKapat(temp->sag);
            temp->sag = NULL;
        }
    }
    delete temp;
    std::cout << "\nAgac Bellekten Silindi";
}

Dugum* IkiliSiralamaAgaci::degerAra(Dugum* kok, int deger)
{
    if (kok == NULL || kok->veri == deger)
    {
        return kok;
    }

    if (kok->veri <deger)
    {
        return degerAra(kok->sag, deger);
    }

    return degerAra(kok->sol, deger);
}


bool DFS(Dugum* agacKok, int deger)
{
    return false;
}

bool BFS(Dugum* agacKok, int deger)  //BFS Arama Methodunda Deger Ara Fonksiyonu �a��ralacakt�r
{
    queue<Dugum*> q;

    q.push(agacKok);
    q.push(NULL);

    while (!q.empty())
    {
        Dugum* �n = q.front();

        q.pop();

        if (�n == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (�n->sol)
            {
                q.push(�n->sol);
            }

            if (�n->sag)
            {
                q.push(�n->sag);
            }
        }

    } 


    return false;
}
