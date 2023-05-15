#include <iostream>
#include <fstream>
/*#include <string>*/

template <typename dataType>
class Matrix{
private:
    int Nr;
    int Mc;
    dataType **data;
public:
    Matrix(int rows,int cols,dataType** curData){
        std::cout<<"Constructor \n";
        Nr=rows;
        Mc=cols;
        int curRow=0;
        int curCol=0;
        data=new dataType*[rows];
        for (int i=0;i<Nr;i++){
            data[i]=new dataType[cols];
            for (int j=0;j<Mc;j++){
                data[i][j]=curData[i][j];
            }
        }
    }
    ~Matrix(){
        for (int i=0;i<Nr;i++){
            delete[] data[i];
        }
        delete[] data;
        std::cout<<"Destructor\n";
    }
    Matrix(const Matrix &other){
        Nr=other.Nr;
        Mc=other.Mc;
        data=new dataType*[Nr];
        for (int i=0;i<Nr;i++){
            data[i]=new dataType[Mc];
            for (int j=0;j<Mc;j++){
                data[i][j]=other.data[i][j];
            }
        }
    }
    int GetRows()const {
        return Nr;
    }
    int GetColls()const {
        return Mc;
    }
    dataType** GetData()const {
        return data;
    }


};
template <typename dataType>
std::ostream& operator<<(std::ostream & os,const Matrix<dataType> &m){
        for(int i=0;i<m.GetRows();i++){
            for (int j=0;j<m.GetColls();j++){
                os<<m.GetData()[i][j]<<" ";
            }
            os<<"\n";
        }
        return os;
    }

int main(){
    setlocale(LC_ALL,"RUS");
    int **data;
    int c=0;
    data=new int*[3];
    for (int i=0;i<3;i++){
        data[i]=new int[3];
        for(int j=0;j<3;j++){
            data[i][j]=c;
            c++;
        }
    }
    Matrix<int> m1(3,3,data);
    std::cout<<m1;
    for (int i=0;i<2;i++){
        delete[] data[i];
    }
    delete[] data;
    return 0;
}
