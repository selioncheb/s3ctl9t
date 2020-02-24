#include "Arr.cpp"

#include"Lists.cpp"
using namespace std;
class Gcalcs {
public:
    //for random
    Gcalcs() {
     
        Arr* ar = new Arr();
        this->ArrCalc(ar);
       
        //print E
        for (int g = 0; g < ar->ei; g++) {
            std::cout << ar->e[g];
        }
        }

    Gcalcs(char* bufA, char* bufB, char* bufC, char* bufD, int twi_key) {
        int i = 0;
        Arr* ar = new Arr(0);
        if (twi_key == 1) { //list
            Slist* sl;
            Slist* ssl;
            Lists* lst = new Lists();
            sl = lst->init(bufA);
            ssl = sl;
            sl = lst->add(sl, bufB);
            sl = lst->add(sl, bufC);
            sl = lst->add(sl, bufD);

            cout << "Entered values:" << endl;
            lst->print(ssl);
            cout << "Erase dublicates in each array?" << endl << "1 - Yes" << endl << "2 - No" << endl << "Selection - ";
            cin >> twi_key;
            if (twi_key == 1) {
               
                    i = i + this->LSCln(sl);
                    i = i + this->LSCln(ssl);
                  
            }
            else if (twi_key == 2) {

            }
            else {
                cout << "Error. Wrong value: " << twi_key << endl;
                exit(1);
            }

            this->ListCalc(ssl, i);
            cout << "Calculated values in E:" << endl;
            lst->print(sl->next, 69);

        }
        else if (twi_key == 2) { // array

            cout << "Erase dublicates in each array?" << endl << "1 - Yes" << endl << "2 - No" << endl << "Selection - ";
            cin >> twi_key;
            if (twi_key == 1) {
                cout << "bufA1 = " << bufA<<endl;
               bufA = this->ArrCln(bufA);
               cout << "bufA1 = " << bufA << endl;
               bufB = this->ArrCln(bufB);
               bufC = this->ArrCln(bufC);
               bufD = this->ArrCln(bufD);
            }
            else if (twi_key == 2) {

            }
            else {
                cout << "Error. Wrong value: " << twi_key << endl;
                exit(1);
            }
            delete ar;
            ar = new Arr(bufA, bufB, bufC, bufD);
            this->ArrCalc(ar);
            ar->printE(ar);
        }
    }
    //calculate E = A / B / C + D in Arrays
	void ArrCalc(Arr *ar) {
        int sel;
        bool ers = false;
        int i;
        int z; //count of equals A / B / C
        i = 0;
        z = 0;
        cout << "Erase duplicates in E?" << endl << "1 - Yes" << endl << "2 - No" << endl << "Selection - ";
        cin >> sel;
        if (sel == 1) {
            ers = true;
        }
        else if (sel == 2) {
            ers = false;
        }
        else {
            cout << "Error. Out of range" << endl;
        }
        // A/B
        for (int a = 0; a < ar->ai; a++) {
            for (int b = 0; b < ar->bi; b++) {
                if ((ar->a[a] == ar->b[b])&(ar->b[b]!=NULL)) {

                    ar->a[a] = NULL;
                    z++;
                }
            }
            // A/C
            for (int c = 0; c < ar->ci; c++) {
                if ((ar->a[a] == ar->c[c]) & (ar->c[c] != NULL)) {
                    ar->a[a] = NULL;
                    z++;
                }
            }
            //buplicates D in A
            if (ers) {
                for (int m = 0; m < ar->di; m++) {
                    if ((ar->a[a] == ar->d[m]) & (ar->d[m] != NULL)) {
                        ar->a[a] = NULL;
                        z++;
                       
                    }
                }
            }
        }
        // E = count A + count D - count of symbols excluded from A
        ar->ei = ar->ai + ar->di - z;
        ar->e = new char[ar->ei];
      
        //   char* E = new char(ar->ai + ar->di-z);
       // E = A* (A* = A/B/C)
        for (int a = 0; a < ar->ai; a++) {
            if (ar->a[a] != NULL) {
                ar->e[i] = ar->a[a];
                i++;
            }
        }
        //E = E + D
        for (int d = 0; d < ar->di; d++) {
            ar->e[i] = ar->d[d];
            i++;
        }
      
        }
    //calculate E = A / B / C + D in Lists
    void ListCalc(Slist* sl, int quot) {
    
        int i;
        int z; //count of equals A / B / C
        i = 0;
        z = 0;

        for (int a = 0; a < sl->len; a++) {
            for (int b = 0; b < sl->next->len; b++) {
                if (sl->val[a] == sl->next->val[b]) {

                    sl->val[a] = NULL;
                    z++;
                }
            }
            // A/C
            for (int c = 0; c < sl->next->next->len; c++) {
                if (sl->val[a] == sl->next->next->val[c]) {
                    sl->val[a] = NULL;
                    z++;
                }
            }
        }
        // E = count A + count D - count of symbols excluded from A
    
       
        Slist* sli = new Slist();
        
        sli->len = sl->len + sl->next->next->next->len - z - quot;
        char* s = new char[sli->len];
       
        sli->next = nullptr;
        sl->next->next->next->next = sli;
        sli->val = new char[sli->len];
      
        //   char* E = new char(ar->ai + ar->di-z);
    // E = A* (A* = A/B/C)
        for (int a = 0; a < sl->len; a++) {
            if (sl->val[a] != NULL) {
             
                sli->val[i] = sl->val[a];
               
                i++;
               
            }
        }
        //E = E + D
        for (int d = 0; d < sl->next->next->next->len; d++) {

            sli->val[i] = sl->next->next->next->val[d];
         
            i++;
           
        }
        sli->val[sli->len] = '\0';
        
    }
    //Clean doubles in Lists
    int LSCln(Slist* sl) {
      
        int num = 0;
        int i = 0;
        int j = 1;
        while (i < sl->len) {
            while (j < sl->len) {
                if (sl->val[i]==sl->val[j]) {
                    sl->val[j] = NULL;
                    num++;

                }
                j++;
            }
            i++;
            j = i + 1;
        }


        return num;
    }
    //clean doubles in Arrays
    char* ArrCln(char* buf) {
       
        char* sum;
        
        int j = 0;
        int k = strlen(buf);
        int i = k-1;
        while ( j < k) {
            
            while ( i > j) {
               
                if (buf[j] == buf[i]) {
                  
                    buf[i] = buf[i+1];
                   
                }
                i--;
            }
            
            j++;
            i = k - 1;
        }
     
        return buf;
    } 

};