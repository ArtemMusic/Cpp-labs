#include <iostream>
#include <cmath>
using namespace std;

class Vector{
    private:
        static int size;

    public:
        int x[2]; 
        int y[2];
        int z[2]; // x = {x,y}

    // конструктор
    Vector (){

        if(Vector::size == 2){
            z[0]=0;z[1]=0;
            cout<<"Введите координаты x и y вектора A\n"<<"x = ";
            cin>>x[0];
            cout<<"y = ";
            cin>>y[0];
            cout<<"Введите координаты x и y вектора B\n"<<"x = ";
            cin>>x[1];
            cout<<"y = ";
            cin>>y[1];
            cout<<"____________________________\n";
            cout << "" << endl;
 
           summ();
           diff();
           sclr();
        } 
        
        else if(Vector::size == 3){
            cout<<"Введите координаты x, y, z вектора A\n"<<"x = ";
            cin>>x[0];
            cout<<"y = ";
            cin>>y[0];
            cout<<"z = ";
            cin>>z[0];
            cout<<"Введите координаты x, y, z вектора B\n"<<"x = ";
            cin>>x[1];
            cout<<"y = ";
            cin>>y[1];
            cout<<"z = ";
            cin>>z[1];
            cout<<"____________________________\n";
            cout << "" << endl;
 
           summ();
           diff();
           sclr();
        } 

        else {
            cout<<"Размер указан не верно\n" ;
            exit(0);
        };
    }

    int summ(){
        int x = this -> x[0] + this -> x[1];
        int y = this -> x[0] + this -> x[1];
        int z = this -> z[0] + this -> z[1];

        if(Vector::size == 2){
            cout<<"Координаты суммы векторов А и B {" <<x<<","<<y<<"}"<<endl;
        } else cout<<"Координаты суммы векторов А и B {" <<x<<","<<y<<","<<z<<"}"<<endl;
        return 0;
    }

    int diff(){
        int x = this -> x[0] - this -> x[1];
        int y = this -> x[0] - this -> x[1];
        int z = this -> z[0] - this -> z[1];

        if(Vector::size == 2){
            cout<<"Координаты разности векторов А и B {" <<x<<","<<y<<"}"<<endl;
        } else cout<<"Координаты разности векторов А и B {" <<x<<","<<y<<","<<z<<"}"<<endl;
        return 0;
    }

    float sclr(){
        int x = this -> x[0] * this -> x[1];
        int y = this -> x[0] * this -> x[1];
        int z = this -> z[0] * this -> z[1];

        float AB = x+y+z;

        cout<<"Сколярные произведение векторов А и B = {"<<AB<<"} "<<endl;
        return 0;
    }

    static int setSize(int _size){
        Vector::size = _size;
        return size;
    }

    //деструктор класса
    ~Vector(){};
};

int Vector::size = 0;

class Complex{
    public:
        float real[2],im[2];

   //Конструктор по умолчанию
   Complex(){
        cout<<"Введите действительную часть комплексного числа: ";
        cin >> real[0];
        cout<<"Введите мнимую часть комплексного числа: ";
        cin >> im[0];

        if(im[0]>=0) cout<<"Введенное число: "<<real[0]<<"+"<<im[0]<<"i"<<endl;
        else cout<<"Введенное число: "<<real[0]<<im[0]<<"i"<<endl; 

        cout<<"Модуль комплексного числа = |"<<(sqrt((pow(real[0],2))+(pow(im[0],2))))<<"|"<<endl;
       
        cout<<endl<<"\t [Введите 2-ое комплексное число для проведения арифметических операций]:"<<endl;
        cout<<"\nДействительная часть: ";
        cin >> real[1];
        cout<<"Мнимая часть: ";
        cin >> im[1];

        if(im[1]>=0) cout<<"Введенное число: "<<real[1]<<"+"<<im[1]<<"i"<<endl;
        else cout<<"Введенное число: "<<real[1]<<im[1]<<"i"<<endl;

        cout<<"Модуль комплексного числа = |"<<(sqrt((pow(real[1],2))+(pow(im[1],2))))<<"|"<<endl;
       
        cout<<endl<<"\t [Результаты]"<<endl<<endl;
        summ(real,im);
        dif(real,im);
        mult(real,im);
        div(real,im);
        cout<<endl;
       
};
   
    int summ (float*real,float*im){
        cout<<"Сумма введенных чисел = "<< real[0]+real[1]<<"+("<<(im[0]+im[1])<<")i"<<endl;
        return 0;
    }
   
    int dif (float*real,float*im){
       cout<<"Разность введенных чисел = "<< real[0]-real[1]<<"+("<<(im[0]-im[1])<<")i"<<endl;
       return 0;
    }
   
    int mult (float*real,float*im){
       cout<<"Произведение введенных чисел = "<< (real[0]*real[1]-im[0]*im[1])<<"+("<<im[0]*real[1]+real[0]*im[1]<<")i"<<endl;
       return 0;
    }

    int div (float*real,float*im){
       cout<<"Частное введенных чисел = "<< (real[0]*real[1]+im[0]*im[1])/(real[1]*real[1]+im[1]*im[1])<<"+("<<(im[0]*real[1]-real[0]*im[1])/(real[1]*real[1]+im[1]*im[1])<<")i"<<endl;
       return 0;
    }

    //Диструктор
    ~Complex(){};
};

int main(){
    int size; // для 1 задачи
    int inf = 1, choise = 0;
   
    while(inf!=0){

       cout<<"\nВведите номер задачи: \n" << endl;
       cout<<"1 - Векторы \n"<<"16 - Комплексные числа\n"<<"0 - выход из программы\n"<<"\nВвод: ";
       cin>>choise;
       
        switch(choise) {
            case 1:{
                cout << "Введите размерность вектора: " << endl;
                cin >> size;

                Vector::setSize(size);
                Vector* vector = new Vector;

                cout << "" << endl;
                return 0;
            }
            case 16: {
                Complex first; //создание объекта класса
                return 0;
            }
            case 0: {
                return 0;
            }
        }
    }
    return 0;
}