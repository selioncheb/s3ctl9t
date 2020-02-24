#include <iostream>
#include <time.h>
#include<math.h>
#include <stdlib.h>
#include <ctime>

class Arr {
public:
    char* a;
    char* b;
    char* c;
    char* d;
    char* e;
    int ai;
    int bi;
    int ci;
    int di;
    int ei;

    //for random
    Arr() {

       
            //A
            //counts of symbols in each array
            int i = 0;
            std::cout << "Select values in range 1 ... 24" << std::endl;
            std::cout << "enter count symbols in A: ";
            std::cin >> this->ai;
            if ((this->ai < 1) || (this->ai > 24)) {
                std::cout << "value is forbidden: out of range " << std::endl;
                exit(1);
            }
            this->a = new char[this->ai];
            //B

            std::cout << "enter count symbols in B: ";
            std::cin >> this->bi;
            if ((this->bi < 1) || (this->bi > 24)) {
                std::cout << "value is forbidden: out of range " << std::endl;
                exit(1);
            }
            this->b = new char[this->bi];
            //C

            std::cout << "enter count symbols in C: ";
            std::cin >> this->ci;
            if ((this->ci < 1) || (this->ci > 24)) {
                std::cout << "value is forbidden: out of range " << std::endl;
                exit(1);
            }
            this->c = new char[this->ci];
            //D

            std::cout << "enter count symbols in D: ";
            std::cin >> this->di;
            if ((this->di < 1) || (this->di > 24)) {
                std::cout << "value is forbidden: out of range " << std::endl;
                exit(1);
            }
            this->d = new char[this->di];

            
            //while we typing. clock is changing. then seed of rand() too
            //A
            for (int y = 0; y < this->ai; y++) {

                this->sym(this, time(0) + y + clock(), 1, y);

            }
            //B

            for (int y = 0; y < this->bi; y++) {

                this->sym(this, time(0) + this->ai + y + clock(), 2, y);

            }
            //C
            for (int y = 0; y < this->ci; y++) {

                this->sym(this, time(0) + this->ai + this->bi + y + clock(), 3, y);

            }
            //D
            for (int y = 0; y < this->di; y++) {

                this->sym(this, time(0) + this->ai + this->bi + this->ci + y + clock(), 4, y);

            }
            this->printA(this);
            this->printB(this);
            this->printC(this);
            this->printD(this);
        }
    //for keyboard
    Arr(char* A, char* B, char* C, char* D) {
         this->ai = strlen(A);
 
        this->a = A;
        this->bi = strlen(B);
  
        this->b = B;
        this->ci = strlen(C);
  
        this->c = C;
        this->di = strlen(D);
    
        this->d = D;
        
        
        
        this->printA(this);
        this->printB(this);
        this->printC(this);
        this->printD(this);
    
    }
    //empty
    Arr(int o) {
   
    }
    //first time generate of values A, B, C, D
    void sym(Arr *ar, int var, int arm, int cnt) {
        //a - 97
      //z - 122
        
       int i = 0;
        
        srand(var+rand());
        i = abs(rand()) % 25;
        i = i + 97;
        //a = 1, b = 2, c = 3, d = 4
        if (arm == 1) { 
            ar->Agen(ar, i, var, cnt);
        }
        else if (arm == 2) {
            ar->Bgen(ar, i, var, cnt);
        }
        else if (arm == 3) {
            ar->Cgen(ar, i, var, cnt);
        }
        else if (arm == 4) {
            ar->Dgen(ar, i, var, cnt);
        }
        
    }
    //search equals int value of A, B, C, D and regenerate.
    void Agen(Arr *ar, int i, int var, int cnt) {
        if (cnt != 0) {
        for (int h = 0; h < cnt; h++) {
            
            if (i != (int)ar->a[h]) {
                ar->a[cnt] = (char)i;
            }
            else {
                ar->sym(ar, var + i, 1, cnt);
                break;
            }
           
        }
        }
        else {
            ar->a[cnt] = (char)i;
        }
    
    }
    void Bgen(Arr *ar, int i, int var, int cnt) {
        if (cnt != 0) {
        for (int h = 0; h < cnt; h++) {
          
            if (i != (int)ar->b[h]) {
                ar->b[cnt] = (char)i;
            }
            else {
                ar->sym(ar, var + i, 2, cnt);
                break;
            }
           
        }
        }
        else {
            ar->b[cnt] = (char)i;
        }

    }
    void Cgen(Arr *ar, int i, int var, int cnt) {
        if (cnt != 0) {
        for (int h = 0; h < cnt; h++) {
          
            if (i != (int)ar->c[h]) {
                ar->c[cnt] = (char)i;
            }
            else {
                ar->sym(ar, var + i, 3, cnt);
                break;
            }
           
        }
        }
        else {
            ar->c[cnt] = (char)i;
        }

    }
    void Dgen(Arr *ar, int i, int var, int cnt) {
        if (cnt != 0) {
        for (int h = 0; h < cnt; h++) {
          
            if (i != (int)ar->d[h]) {
                ar->d[cnt] = (char)i;
            }
            else {
                ar->sym(ar, var + i, 4, cnt);
                break;
            }
           
        }
        }
        else {
            ar->d[cnt] = (char)i;
        }

    }
    //Print A, B, C, D, E
    void printA(Arr *ar) {
        std::cout << "A[]={";
        for (int i = 0; i < ar->ai; i++) {
            std::cout << ar->a[i];
            if (i<ar->ai-1) {
                std::cout << ", ";
            }
        }
        std::cout << "}"<<std::endl;
    }
    void printB(Arr* ar) {
        std::cout << "B[]={";
        for (int i = 0; i < ar->bi; i++) {
            std::cout << ar->b[i];
            if (i < ar->bi - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
    void printC(Arr* ar) {
        std::cout << "C[]={";
        for (int i = 0; i < ar->ci; i++) {
            std::cout << ar->c[i];
            if (i < ar->ci - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
    void printD(Arr* ar) {
        std::cout << "D[]={";
        for (int i = 0; i < ar->di; i++) {
            std::cout << ar->d[i];
            if (i < ar->di - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
    void printE(Arr* ar) {
        std::cout << "E[]={";
        for (int i = 0; i < ar->ei; i++) {
            std::cout << ar->e[i];
            if (i < ar->ei - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
};
   