#include <iostream>
#include "matrix.h"

Matrix::Matrix():row(3),column(3)
{
    share_times=new int[1];
    share_times[0]=0;
    data = new float* [row];
    for (int i = 0; i < row; i++)
    {
        data[i] = new float[column];
        for (int j = 0; j < column; j++)
        {
            data[i][j] = 1;
        }
    }
}
Matrix::Matrix(int a, int b):row(a),column(b)
{
    share_times=new int[1];
    share_times[0]=0;
    data = new float* [row];
    for (int i = 0; i < row; i++)
    {
        data[i] = new float[column];
        for (int j = 0; j < column; j++)
        {
            data[i][j] = 1;
        }
    }
}
Matrix::Matrix(int a, int b,float** c):row(a),column(b)
{
    share_times=new int[1];
    share_times[0]=0;
    data=c;
}
Matrix::Matrix(Matrix &matrix){
    share_times=matrix.share_times;
    share_times[0]++;
    row=matrix.row;
    column=matrix.column;
    data=matrix.data;
}
std::ostream& operator<<(std::ostream& os, const Matrix& other)
{
    for(int i=0;i<other.row;i++)
    {
        for(int j=0;j<other.column;j++)
        {
            os<<other.data[i][j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}
void operator~(Matrix&other)
{
    if(other.share_times[0]==0)
    {
        delete [] other.data;
    }
    else
    {
        other.share_times[0]--;
        other.data=nullptr;
    }
    std::cout<<"This Matrix's data has been deleted\n";
}
Matrix Matrix::operator*(float a)const
{
    auto **ans= new float* [row];
    for (int i = 0; i < row; i++)
    {
        ans[i] = new float[column];
        for (int j = 0; j < column; j++)
        {
            ans[i][j] =data[i][j]*a;
        }
    }
    Matrix d(row,column,ans);
    return d;
}
Matrix Matrix::operator*(const Matrix& other)const
{
    auto **ans= new float* [this->row];
    for (int i = 0; i <this->row; i++)
    {
        ans[i] = new float[other.column];
        for(int k=0;k<this->column;k++)
        {
            float s=this->data[i][k];
            for(int j=0;j<other.column;j++)
            {
                ans[i][j]+=s*other.data[k][j];
            }
        }
    }
    Matrix d(this->row,other.column,ans);
    return d;
}
Matrix Matrix::operator/(float a)const
{
    auto **ans= new float* [row];
    for (int i = 0; i < row; i++)
    {
        ans[i] = new float[column];
        for (int j = 0; j < column; j++)
        {
            ans[i][j] =data[i][j]/a;
        }
    }
    Matrix d(row,column,ans);
    return d;
}
bool Matrix::operator==(const Matrix&other) const
{
    bool judge= true;bool goon= true;
    if(this->column ==other.column&&this->row==other.row)
    {
        for(int i=0;i<this->row;i++)
        {
          for(int j=0;j<this->column;j++)
          {
              if(this->data[i][j]!=other.data[i][j])
              {
                  goon= false;judge= false;break;
              }
          }
          if(!goon){break;}
        }
    } else{judge=false;}
    if(judge)
    {
        std::cout<<"they are the same\n";
    }else
    {
        std::cout<<"they are not the same\n";
    }
    return judge;
}
Matrix operator*(float a,const Matrix&other)
{
    auto **ans= new float* [other.row];
    for (int i = 0; i < other.row; i++)
    {
        ans[i] = new float[other.column];
        for (int j = 0; j < other.column; j++)
        {
            ans[i][j] =other.data[i][j]*a;
        }
    }
    Matrix d(other.row,other.column,ans);
    return d;
}
Matrix & Matrix::operator=(const Matrix& other){
     if(this==&other)
     {
         return *this;
     }else{
         if(share_times[0]==0)
         {
             delete []this->data;
         }else
         {
             share_times[0]--;
         }
         this->row=other.row;
         this->column=other.column;
         share_times=other.share_times;
         share_times[0]++;
         data=other.data;
         return *this;
     }
}
Matrix Matrix::operator+(const Matrix& other)const
{
    auto **ans=new float*[row];
    for(int i=0;i<row;i++)
    {
        ans[i] = new float[column];
        for (int j = 0; j < column; j++)
        {
            ans[i][j] =data[i][j]+other.data[i][j];
        }
    }
    Matrix d(other.row,other.column,ans);
    return d;
}
Matrix Matrix::operator-(const Matrix& other)const
{
    auto **ans=new float*[row];
    for(int i=0;i<row;i++)
    {
        ans[i] = new float[column];
        for (int j = 0; j < column; j++)
        {
            ans[i][j] =data[i][j]-other.data[i][j];
        }
    }
    Matrix d(other.row,other.column,ans);
    return d;
}