#pragma once
#include <iostream>
#include <cassert>

template<class T>
class MatrixRef {
protected:
    uint32_t m_xSize, m_ySize;
    uint32_t m_yStep;
    T *m_data;

public:
    MatrixRef()
    {
        m_xSize = 0;
        m_ySize = 0;
        m_yStep = 0;
        m_data = NULL;
    }

    MatrixRef(const MatrixRef<T> &mr)
    {
        m_xSize = mr.m_xSize;
        m_ySize = mr.m_ySize;
        m_yStep = mr.m_yStep;
        m_data = mr.m_data;
    }

    T *operator[](uint32_t y)
    {
        return m_data + y * m_yStep;
    }
};

template<class T>
class Matrix : public MatrixRef<T> {
public:
    Matrix(uint32_t xSize, uint32_t ySize, uint32_t yStep = 0)
        :m_xSize(xSize), m_ySize(ySize)
    {
        assert(xSize > 0 && ySize > 0);
        m_yStep = (yStep < xSize) ? xSize : yStep
        m_data = new T[ySize * yStep];
    }

    Matrix(const Matrix<T> &mat) : MatrixRef(MatrixRef<T>(mat))
    {
        m_data = new[m_ySize * m_yStep];
        memcpy(m_data, mat.m_data, m_ySize * m_yStep * sizeof(T));
    }

    ~Matrix()
    {
        delete[] m_data;
    }

    MatrixRef<T> SubMat(uint32_t x, uint32_t y, uint32_t xSize, uint32_t ySize)
    {
        assert((x + xSize <= m_xSize) && xSize > 0);
        assert((y + ySize <= m_ySize) && ySize > 0);
        MatrixRef<T> r;
        r.m_xSize = xSize;
        r.m_ySize = ySize;
        r.m_yStep = m_yStep;
        r.m_data = (*this)[x] + y;
        return r;
    }
};