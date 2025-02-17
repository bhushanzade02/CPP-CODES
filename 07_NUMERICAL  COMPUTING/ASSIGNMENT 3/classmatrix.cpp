#include<iostream>
#include<cmath>

class MatrixWork{
private: 
int rows , cols;
int ** data;

public:
    MatrixWork(int r,int c){
        rows=r;
        cols=c;
        data=new int * [rows];
        for(int i =0; i<rows;i++){
            data[i]=new int [cols];
        }
    }



    void GetInput(){                       // this function for getting values from the user
        cout<<"enter a elements for matrix class:"<<endl;
        for(int i =0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>data[i][j];
            }
        }
    }



    



}