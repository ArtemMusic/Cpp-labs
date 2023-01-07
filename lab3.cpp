#include <iostream>
#include <string>

using namespace std;
 
class COne {
    public:
        long L;
        string S;
    public:

    COne(){};

    COne(string input = "", long L = 0) : S(move(input)), L(L) {}
    
    COne(const COne &arg) {
        L = arg.L;
        S = arg.S;
    }
 
    COne &operator=(const COne &arg) {
        this->L = arg.L;
        this->S = arg.S;
        return *this;
    }
 
    ~COne() {
        // S.clear();
    };
 
    long getValue() const {
        return L;
    }
 
    string getString() const{
        return S;
    }
 
    size_t len() const {
        return S.size();
    }

    void print() const {
        cout << "\nCOne: " << L << ", "<< S ;
    }
 
    friend class CTwo;
};
 
class CTwo {
    protected:
        string S;
        COne *P;
    public:

    CTwo(){}
    
    CTwo(string s = "", string ps = "", int number = 0) : S(move(s)) {
        P = new COne(move(ps), number);
    }
 
    CTwo(const CTwo &arg) {
        P = new COne(*arg.P);
        S = arg.S;
    }
 
    CTwo &operator=(const CTwo &arg) {
        CTwo temp(arg);
        swap(P, temp.P);
        swap(S, temp.S);
        return *this;
    }
 
    ~CTwo() {
        delete P;
        S.clear();
    }
 
    const COne *getCOne() const {
        return P;
    }
 
    const string getString() {
        return S;
    }
 
    size_t len() const {
        return S.size();
    }
 
    virtual void print() const {
        cout <<"CTwo: ";
        if (P) {
            cout << '\"' << S << "\", ";
            P->print();
        } else { cout << "undefined"; }
    }
};

class CThree : public CTwo { // ОТНОШЕНИЕ НАСЛЕДОВАНИЯ
    public:
        char *a;
 
    public:
 
    CThree(string s, string ps, int number = 0) : CTwo(move(s), move(ps), number) {
        if (number > 0) {
            a = new char[number] {0};
        } else { cout << "undefined"; }
    }
 
    CThree(const CThree &arg) : CThree(arg.S, arg.P->S, arg.P->L) {
        copy(arg.a, arg.a + P->L, a);
    }
 
    CThree &operator=(const CThree &arg) {
        CThree temp(arg);
        swap(*this, temp);
        return *this;
    }
    
    ~CThree() {
        delete[] a;
    }
 
    char &operator[](size_t idx) {
        return a[idx];
    }

    void print() const override {
        cout << "CThree: ";
        
        if (a) {
            cout << "[";
            for (size_t i = 0; i < 11; i++) {
                cout << a[i];
            }
            cout << "]\n";
        }
        CTwo::print();
    }
};

int main() {
    int n,N=11;
    string *s1= new string;
    string *s2= new string;
    
    cout<<"Введите ваши данные\n ";
    cout<<"Имя: ";
    cin>>*s1;
    cout<<"Фамилия: ";
    cin>>*s2;
    cout<<"Возраст: "; cin>>n;
    CThree third(*s1,*s2,n);
    cout<<"Номер телефона: ";

        for (size_t i = 0; i < N; ++i) cin>>third[i];
    
    cout<<"\n_______________________\n"<<endl;
    cout<<"\t[Результат работы программы]\n"<<endl;
    cout << "\nСодержимое объекта класса\n ",third.print(),cout<< endl;
    cout<<"\n_______________________\n"<<endl;
  
    cout << "Имя и Фамилия: " << third.getString() << ' ' << third.getCOne()->getString() << endl;
    cout << "Возраст: " << third.getCOne()->getValue() << endl;
    cout << "Телефон: " << third.a << endl;
    
    // Копирование конструктором
    cout << "\n[Осуществив копирование с помощью конструктора, создадим новый объект класса]\n" << endl;
    CThree forth(third);
    cout << "third: ", third.print(), cout << endl <<endl;
    cout << "forth: ", forth.print(), cout << endl;
    return 0;
}
