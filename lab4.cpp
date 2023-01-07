#include <iostream>
#include <string>

using namespace std;
 
class COne {
    public:
        long L;
        string S;

    public:

    COne(){
        this->L = 0;
        this->S = "0";
    };
    
    COne(string input , long L) : S(move(input)), L(L) {}
    
    COne(const COne &arg) {
        L = arg.L;
        S = arg.S;
    }
 
    COne &operator=(const COne &arg) {
        COne temp(arg);
        swap(L, temp.L);
        swap(S, temp.S);
        return *this;
    }

    ~COne() {
        S.clear();
    };
 
    long getValue() const {
        return L;
    }
 
    string getString() const
    {
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
        COne *P; // ОТНОШЕНИЕ ВКЛЮЧЕНИЯ

    public:

    CTwo(){
        S = "0";
        P = new COne();
    }
    
    CTwo(string _s, string _ps, int _number) {
        S=_s;
        P = new COne(move(_ps), _number);
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
 
    COne *getCOne() const {
        return P;
    }
 
    string getString() const {
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

    CThree():CTwo(){
        a = "0";
    }

    CThree(string s, string ps, int number) : CTwo(move(s), move(ps), number) {
        if (number > 0) {
            a = new char[number] {'8','9','6','2','1','2','1','6','0','9','0'};
        } else { cout << "undefined"; }
    }
 
    CThree(const CThree &arg) : CThree(arg.S, arg.P->S, arg.P->L) {
        std::copy(arg.a, arg.a + P->L, a);
    }
 
    CThree &operator=(const CThree &arg) {
        CThree temp(arg);
        swap(*this, temp);
        return *this;
    }
 
    char &operator[](size_t idx) {
        return a[idx];
    }

    void print() const override{
        cout << "CThree: ";
            cout << "[";
            for (int i = 0; i < 11; i++) {
                cout << a[i];
            }
            cout << "]\n";
        CTwo::print();
    }
 };

class CFour : public CThree { // ОТНОШЕНИЕ НАСЛЕДОВАНИЯ
    protected:
        int pol;

    public:

    CFour():CThree(){
        pol = 10;
    }


    CFour(string s, string ps, string cps, int number, int pol) : CThree(move(s), move(ps), number) {
        this->pol = pol;
    }
 
    CFour(const CFour &arg) : CThree(arg) {
        this->pol = arg.pol;
    }
 
   void setPol(int pol){
        this-> pol= pol;
    }
    
    float getPol(){
        return this->pol;
    }

    CFour &operator=(const CFour &arg) {
        CFour temp(arg);
        swap(*this, temp);
        return *this;
    }
    
    void print() const override {
        cout << "CFour: " << pol << "\n";
       
        CThree::print();
    }

    ~CFour(){}
};

void printAll(CTwo **t, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        (t[i]->print()), cout << endl;
    }
}

void test() {
    CTwo *Array[3];
    Array[0] = new CTwo("Артем", "Музычук", 19);
    Array[1] = new CThree("Артем", "Музычук", 19);
    Array[2] = new CFour("Артем", "Музычук", "89621216090", 19, 1);
    printAll(Array, 3);
    delete Array[0];
    delete Array[1];
    delete Array[2];
}


int main() {
    int n,N=11;
    int pol = 0;
    string *s1= new string;
    string *s2= new string;
    string *cps= new string;
    

    cout<<"Введите ваши данные\n ";
    cout<<"Имя: ";
    cin>>*s1;
    cout<<"Фамилия: ";
    cin>>*s2;
    cout<<"Возраст: "; cin>>n;
    cout<<"Пол(1 или 0): "; cin>>pol;
    CFour third(*s1,*s2,*cps,n,pol);
    
    cout<<"\n_______________________\n"<<endl;
    cout<<"\t[Результат работы программы]\n"<<endl;
    cout << "\nСодержимое объекта класса\n ",third.print(),cout<< endl;
    cout<<"\n_______________________\n"<<endl;
  
    cout << "Имя и Фамилия: " << third.getString() << ' ' << third.getCOne()->getString() << endl;
    cout << "Возраст: " << third.getCOne()->getValue() << endl;
    cout << "Телефон: " << third.a << endl;
    cout << "Пол: " << third.getPol() << endl;
   
    
    // Копирование конструктором
    cout << "\n[Осуществив копирование с помощью конструктора, создадим новый объект класса]\n" << endl;
    CFour forth(third);
    cout << "third: ", third.print(), cout << endl <<endl;
    cout << "forth: ", forth.print(), cout << endl;

        // Тест
        cout << "\n PRINT ALL:\n";
        test();

    return 0;
}
