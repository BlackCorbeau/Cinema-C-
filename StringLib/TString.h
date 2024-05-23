#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>
#include <..\Utilits\MUtilits.h>

class CString {
    char* _data;                  // ��������� ������
    size_t _size;                 // ����� ������
    size_t _capacity;             // ������ ���������
    size_t _max_capacity = -1;    // ����������� ��������� ������ ���������

public:
    CString();
    CString(const CString& str);
    CString(const char* c_str);
    CString(const char* c_str, size_t n);
    CString(size_t n, char c);
    CString(const CString& str, size_t pos, size_t len);

    ~CString();

    void print() const noexcept; 

    bool empty() const noexcept;
    bool full() const noexcept;

    size_t size() const noexcept;
    size_t capacity() const noexcept;
    const char* data() const;

    void swap(CString& str);
    /*size_t copy(char* buf, size_t len, size_t pos = 0) const;*/
    /*CString substr(size_t pos, size_t len) const;*/ //�������� �� ���� ������� �� ���) !!!_CrtIsValidHeapPointer(block)

    CString& assign(const CString& str); 
    CString& assign(const CString& str, size_t pos, size_t len);
    CString& assign(const char* s);
    CString& assign(const char* s, size_t n);
    CString& assign(size_t n, char c);

    int compare(const CString& str) const noexcept;
    int compare(size_t pos, size_t len, const CString& str) const;
    int compare(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen) const;
    int compare(const char* s) const;
    int compare(size_t pos, size_t len, const char* s) const;
    int compare(size_t pos, size_t len, const char* s, size_t n) const;

    void clear() noexcept;                    // ������� ������
    void resize(size_t n);     // ��������� ����� ������
    void reserve(size_t n = 0);// ���������� ���������
    void update(const size_t __size);

    void push_back(char c);                   // ������� ������� (� �����)
    void pop_back();                          // �������� ������� (�� �����)

    CString& erase(size_t pos, size_t len);    // �������� �������

    //������� ������ (� �����)
    CString& append(const CString& str);
    CString& append(const CString& str, size_t subpos, size_t sublen);
    CString& append(const char* s);
    CString& append(const char* s, size_t n);
    CString& append(size_t n, char c);

     /*������� ������ (����� ��������� �������)*/
    CString& insert(size_t pos, const CString& str);
    CString& insert(size_t pos, const CString& str, size_t subpos, size_t sublen);
    CString& insert(size_t pos, const char* s);
    CString& insert(size_t pos, const char* s, size_t n);
    CString& insert(size_t pos, size_t n, char c);

    // ������ ������� �������� �������
    CString& replace(size_t pos, size_t len, const CString& str);
    CString& replace(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen);
    CString& replace(size_t pos, size_t len, const char* s, size_t n);
    CString& replace(size_t pos, size_t len, size_t n, char c);

    // ����� ��������� � ������ ������� � ��������� �������
    size_t find(const CString& str) const;
    size_t find(const char* s) const;
    size_t find(const char* s, size_t pos, size_t n) const;
    size_t find(char c) const;

    // ����� ������ �� ������������� �������� � ������ ������� � ��������� �������
    size_t find_first_of(const CString& str, size_t pos = 0) const;
    size_t find_first_of(const char* s, size_t pos = 0) const;
    size_t find_first_of(const char* s, size_t pos, size_t n) const;
    size_t find_first_of(char c, size_t pos = 0) const;

    // ����� ������ �� �� ������������� �������� � ������ ������� � ��������� �������
    size_t find_first_not_of(const CString& str, size_t pos = 0) const;
    size_t find_first_not_of(const char* s, size_t pos = 0) const;
    size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
    size_t find_first_not_of(char c, size_t pos = 0) const;

    friend std::istream& operator>>(std::istream& input, CString& obj);

    friend std::ostream& operator<<(std::ostream& output, const CString& obj);

    friend bool operator==(const CString& lhs, const CString& rhs);

    CString& operator=(const char* c_str) {
        int __size = 0;
        while (c_str[__size] != '\0')
        {
            __size++;
        }
        // Clear existing data
        clear();
        // Resize the internal array to match the string size
        resize(__size);
        // Copy characters from the C-string to the internal array
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = c_str[i];
        }
        // Update the size
        _size = __size;
        return *this;
    }
};  
