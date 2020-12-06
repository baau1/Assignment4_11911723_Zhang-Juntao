#pragma once
class Matrix
{
private:
    int column;
    int row;
    float** data;
    int *share_times;
public:
    Matrix();
    Matrix(int row,int column);
    Matrix(int row,int column,float** data);
    Matrix(Matrix &matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& other);
    bool operator==(const Matrix& other)const;
    friend  void operator~(Matrix& other);
    Matrix operator*(float a)const;
    Matrix operator*(const Matrix& other)const;
    Matrix operator+(const Matrix& other)const;
    Matrix operator-(const Matrix& other)const;
    Matrix operator/(float a)const;
    friend  Matrix operator*(float a,const Matrix& other);
    Matrix & operator=(const Matrix& other);

};
