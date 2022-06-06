#include <iostream>
#include "veri.h"
#include <chrono>

#include <queue> //Kuyruk Veri Yapýsý
#include <stack> //Yýðýn Veri Yapýsý

using namespace std;



typedef IkiliSiralamaAgaci veriYapisi;
veriYapisi bst;
Dugum node;

struct menu {
    int agacSecim;
    int yöntem;
    int deger;
    bool aramaYöntemi(int secim, int deger);
    bool diziSecim();
    void menuYazdir();
}m;

int main()
{
    m.menuYazdir(); //Menü Yazdýrýlýr
    
    auto begin = std::chrono::high_resolution_clock::now();
    if (m.diziSecim() == true)// Dizi Seçimi Gerçekleþtirilir
    {
        std::cout << "Sonuc => Veri Bulundu.\n";
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << "Gecen Süre =>" << elapsed.count() << " mikro-saniye";
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
    std::cin >> m.yöntem;

    if (m.yöntem == 1)
    {
        std::cout << "\nAgac " << m.agacSecim << " uzerinde DFS ile arayacaginiz degeri giriniz:\n";
        std::cin >> m.deger;

    }
    else if(m.yöntem == 2)
    {
        std::cout << "\nAgac " << m.agacSecim << " uzerinde BFS ile arayacaginiz degeri giriniz:\n";
        std::cin >> m.deger;

    }

    
}
 
bool menu::aramaYöntemi(int secim, int deger)
{
    if (secim == 1 )
    {
        return DFS(bst.kok, deger);
        //DFS Seçimi
    }
    else
    {
        return BFS(bst.kok, deger);
        //BFS Seçimi
    }
}

bool menu::diziSecim()
{
    if (m.agacSecim == 1)  //Dizi 1 Seçimi
    {
        for (size_t i = 0; i < UZUNLUK; i++)
        {
            bst.agacKur(bst.kok, &dizi1[i]);
        }
        return m.aramaYöntemi(m.yöntem, m.deger);
    }
    else if (m.agacSecim == 2) //Dizi 2 Seçimi
    {
        for (size_t i = 0; i < UZUNLUK; i++)
        {
            bst.agacKur(bst.kok, &dizi2[i]);
        }
        return m.aramaYöntemi(m.yöntem, m.deger);
    }
    else //Dizi 3 Seçimi
    {
        for (size_t i = 0; i < UZUNLUK; i++)
        {
            bst.agacKur(bst.kok, &dizi3[i]);
        }
        return m.aramaYöntemi(m.yöntem, m.deger);
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

bool BFS(Dugum* agacKok, int deger)  //BFS Arama Methodunda Deger Ara Fonksiyonu Çaðýralacaktýr
{
    queue<Dugum*> q;

    q.push(agacKok);
    q.push(NULL);

    while (!q.empty())
    {
        Dugum* ön = q.front();

        q.pop();

        if (ön == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (ön->sol)
            {
                q.push(ön->sol);
            }

            if (ön->sag)
            {
                q.push(ön->sag);
            }
        }

    } 


    return false;
}
