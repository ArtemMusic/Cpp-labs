#include <iostream>
#include <string>

using namespace std;
 
class COne {
    protected:
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
            S.clear();
        };
 
        const long getValue() const {
            return L;
        }
 
        const string getString() const
        {
            return S;
        }
 
        size_t len() const {
            return S.size();
        }
 
        void print() {
            cout << "\nCOne: " << L << ", "<< S ;
        }
 
        friend class CTwo;
};
 
class CTwo {
    protected:
        string S;
        COne *P; 
    public:
    
    CTwo(string s = "", string ps = "", int number = 0) : S(move(s)){
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
 
    // Деструктор
    ~CTwo() {
        // delete P;
        // S.clear();
    }
 
    const COne *getCOne() {
        return P;
    }
 
    const string getString() {
        return S;
    }
 
    size_t len() {
        return S.size();
    }
 
    void print() {
        cout <<"CTwo: ";
        if (P){
            cout << '\"' << S << "\", ";
            P->print();
        } else { cout << "undefined"; }
    }
};

int main() {
    int n;
    string *s1=new string;
    cout<<"Введите ваш возраст: "; 
    cin>>n;  
    cout<<endl;
    string *s2= new string;
    cout<<"Введите ваши данные\n ";
    
    cout<<"Имя: ";
    cin>>*s1;
    cout<<"Фамилия: ";
    cin>>*s2;
    
    cout<<"\n_______________________\n"<<endl;
    cout<<"\t[Результат работы программы]\n"<<endl;

    CTwo second(*s1,*s2,n);
    cout << "\nСодержимое объекта класса\n ",second.print(),cout << endl;
    
    cout<<"\n_______________________\n"<<endl;
  
    cout << "Имя и Фамилия: " << second.getString() << ' ' << second.getCOne()->getString() << endl;
    
    cout << "Возраст: " << second.getCOne()->getValue() << endl;
    
    // cout<<"\n-В строке объекта CTwo (имя) "<<second.len()/2<<" символов"<<endl;
    // cout<<"-В строке объекта COne (фамилия)"<< second.getCOne()->len()/2<<" символов"<<endl;
    
    
    cout<<"\n_______________________"<<endl;
    cout<<""<<endl;

    // Копирование конструктором
    cout << "[Осуществив копирование с помощью конструктора, создадим новый объект класса]\n" << endl;
    CTwo third(second);
    cout << "second: ", second.print(), cout << endl;
    cout << "third: ", third.print(), cout << endl;
 
    // Копирование присваиванием
    cout << "\n_______________________" << endl;
    cout << "[Осуществив копирование с помощью присваивания, создадим новый объект класса]\n" << endl;
    third = second;
    cout << "second: ", second.print(), cout << endl;
    cout << "third: ", third.print(), cout << endl;
 
    return 0;
}