#include <iostream>
#include <thread>
#include <vector>

void calculate(char* A, int p, int k, std::vector<int> &tab);

int main(){
    std::vector<int> tab(5,0);
    int a1;
    std::cout << "Podaj dlugosc sekwencji dna: " << std::endl;
    std::cin >> a1;
    char *A=new char(a1);
    std::cout << "Podaj sekwencje dna: " << std::endl;
    for(int i=0; i<a1; i++)
    {
        std::cin >> A[i];
    }
    std::vector<std::thread> threads;
    threads.emplace_back(calculate, A, 0, a1/4, std::ref(tab));
    threads.emplace_back(calculate, A, a1/4, (a1/4)*2, std::ref(tab));
    threads.emplace_back(calculate, A, (a1/4)*2, (a1/4)*3, std::ref(tab));
    threads.emplace_back(calculate, A, (a1/4)*3, a1, std::ref(tab));

    for(std::thread &thread:threads) thread.join();
    std::cout<<"A: "<<tab[0]<<" G: "<<tab[1]<<" C: "<<tab[2]<<" T: "<<tab[3]<< " Errors in sequence(not A, G, C, T): " <<tab[4] <<std::endl;
}


void calculate(char* A, int p, int k, std::vector<int> &tab){
    for(int i = p; i<k;i++){
       if(A[i]=='A' || A[i]=='a')
            tab[0]++;
        else if(A[i]=='G' || A[i]=='g')
            tab[1]++;
        else if(A[i]=='C'|| A[i]=='c')
            tab[2]++;
        else if(A[i]=='T'|| A[i]=='t')
            tab[3]++;
        else
            tab[4]++;
    }
}
