#pragma once
#include <iostream>
#include <stdexcept>
#include <..\Utilits\MUtilits.h>

template <typename T>
class TArchive {
    T* _data;                  // динамический массив данных
    archive_State* _archive_States;            // состояния ячеек
    size_t _capacity;          // реальный размер массива
    size_t _size;              // количество хранимых данных
    size_t _deleted;           // количество "удалённых" позиций
public:
    TArchive();
    TArchive(const TArchive& archive);
    TArchive(const T* arr, size_t n);
    TArchive(size_t n, T value);
    TArchive(const TArchive& archive, size_t pos, size_t len);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    size_t size() const;
    size_t capacity() const;
    const T* data();

    void swap(TArchive& archive);

    void clear();
    void reserve(size_t n);
    void resize(size_t n, T value);
    void repack();

    TArchive& assign(const TArchive& archive);


    void push_back(T value);             // вставка элемента (в конец)
    void pop_back();                     // удаление элемента (из конца)
    void push_front(T value);            // вставка элемента (в начало)
    void pop_front();                    // удаление элемента (из начала)

    TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    TArchive& replace(size_t pos, T new_value);

    TArchive& remove_by_index(size_t pos);
    TArchive& erase(size_t pos, size_t n);
    TArchive& remove_all(T value);
    TArchive& remove_first(T value);
    TArchive& remove_last(T value);

    size_t* find_all(T value, size_t& count) const noexcept;
    size_t find_first(T value);
    size_t find_last(T value);

    TArchive& operator=(const TArchive& vec) {
        clear();
        reserve(vec._size);
        for (size_t i = 0; i < vec._size; ++i) {
            _data[i] = vec._data[i];
            _archive_States[i] = archive_State::Busy;
        }
        _size = vec._size;
        _deleted = 0;
        return *this;
    }

    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        if (_archive_States[index] == archive_State::Deleted) {
            throw std::runtime_error("Index is deleted");
        }
        return _data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        if (_archive_States[index] == archive_State::Deleted) {
            throw std::runtime_error("Index is deleted");
        }
        return _data[index];
    }
private:
    //size_t count_value(T value);
};

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _archive_States = new archive_State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _archive_States[i] = archive_State::empty;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive)
{
    _capacity = archive._capacity;
    _size = archive._size;
    _deleted = archive._deleted;
    _archive_States = new archive_State[_capacity];
    _data = new T[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _archive_States[i] = archive._archive_States[i];
    }
    for (int i = 0; i < _size; i++)
    {
        _data[i] = archive._data[i];
    }
}

template <typename T>
TArchive<T>::TArchive(const T* arr, size_t n)
{
    _size = n;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _archive_States = new archive_State[_capacity];
    _data = new T[_capacity];
    _deleted = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _archive_States[i] = archive_State::empty;
    }
    for (int i = 0; i < n; i++)
    {
        _data[i] = arr[i];
    }
    for (size_t i = 0; i < n; i++) {
        _archive_States[i] = archive_State::busy;
    }
}

template <typename T>
TArchive<T>::TArchive(size_t n, T value)
{
    _size = n;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _archive_States = new archive_State[_capacity];
    _data = new T[_capacity];
    _deleted = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _archive_States[i] = archive_State::empty;
    }
    for (int i = 0; i < n; i++)
    {
        _data[i] = value;
    }
    for (size_t i = 0; i < n; i++) {
        _archive_States[i] = archive_State::busy;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive, size_t pos, size_t len)
{
    _size = len;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _deleted = 0;
    _archive_States = new archive_State[_capacity];
    _data = new T[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _archive_States[i] = archive_State::empty;
    }
    for (size_t i = 0; i < _size; i++) {
        _archive_States[i] = archive_State::busy;
    }
    for (int i = 0; i < _size; i++)
    {
        _data[i] = archive._data[i + pos];
    }
}

template <typename T>
TArchive<T>::~TArchive()
{
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template<typename T>
size_t TArchive<T>::size() const
{
    return _size;
}
template<typename T>
size_t TArchive<T>::capacity() const
{
    return _capacity;
}

template<typename T>
const T* TArchive<T>::data()
{
    return _data;
}

template<typename T>
void TArchive<T>::swap(TArchive& archive)
{
    for (int i = 0; i < algorithms::Max(_size, archive._size); i++)
    {
        algorithms::swap(_data[i], archive._data[i]);
    }
}


template<typename T>
void TArchive<T>::clear() // Подумать как доделать (после работы видно мусор)
{
    delete[] _data;
    delete[] _archive_States;
    _size = 0;
    _capacity = STEP_CAPACITY;
}

template<typename T>
void TArchive<T>::reserve(size_t n)
{
    if (_capacity == -1)
    {
        std::cout << "Переполнение, добавление большего количества элементов в этот архив невозможно, пожалуйста создайте новый архив или удалите часть элементов." << '\n';
        return;
    }
    else
    {
        _capacity = ((_size + n) / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    }
    T* new_data;
    archive_State* new_archive_States;
    new_data = new T[_capacity];
    new_archive_States = new archive_State[_capacity];
    for (int i = 0; i < _size; i++)
    {
        new_data[i] = _data[i];
        new_archive_States[i] = _archive_States[i];
    }
    for (int i = _size; i < _capacity; i++)
    {
        new_archive_States[i] = archive_State::empty;
    }
    delete[] _data;
    delete[] _archive_States;
    _data = new_data;
    _archive_States = new_archive_States;
}

template<typename T>
void TArchive<T>::resize(size_t n, T value)
{
    n -= 1;
    this->reserve(n);
    for (int i = _size - 1; i < _size + n; i++)
    {
        _data[i] = value;
    }
    for (int i = _size - 1; i < _size + n; i++)
    {
        _archive_States[i] = archive_State::busy;
    }
    _size += n;
}

template<typename T>
void TArchive<T>::repack() // подумать или спросить)
{
    int j = 0;
    for (int i = 0; i < _size; i++) {
        if (_archive_States[i] != archive_State::deleted) {
            _data[j] = _data[i];
            _archive_States[j] = _archive_States[i];
            j++;
        }
    }
    _size = j;
}

template<typename T>
TArchive<T>& TArchive<T>::assign(const TArchive& archive)
{
    this->reserve(archive._size);
    for (int i = 0; i < archive._size; i++)
    {
        _data[i] = archive._data[i];
        _archive_States[i] = archive_State::busy;
    }
    for (int i = archive._size; i < _capacity; i++)
    {
        _archive_States[i] = archive_State::empty;
    }
    _size = archive._size;
    return *this;
}

template<typename T>
void TArchive<T>::push_back(T value)
{
    this->reserve(1);
    _data[_size] = value;
    _size += 1;
}

template<typename T>
void TArchive<T>::pop_back()
{
    _archive_States[_size - 1] = archive_State::deleted;
}

template<typename T>
void TArchive<T>::push_front(T value)
{
    this->reserve(1);
    for (int i = _size; i >= 0; i--)
    {
        _data[i + 1] = _data[i];
    }
    _data[0] = value;
    _size += 1;
}

template<typename T>
void TArchive<T>::pop_front()
{
    _archive_States[0] = archive_State::deleted;
}


template<typename T>
TArchive<T>& TArchive<T>::remove_by_index(size_t pos)
{
    _archive_States[pos] = archive_State::Deleted;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    }

    // действия при переполнении
    this->reserve(1);

    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = value;
    _archive_States[pos] = archive_State::busy;
    _size++;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(const T* arr, size_t n, size_t pos) // не работает при pos = 0
{
    this->reserve(n);
    for (int i = _size - 1; i >= pos; i--)
    {
        _data[i + n] = _data[i];
    }
    for (int i = pos, j = 0; i < n + pos; i++, j++)
    {
        _data[i] = arr[j];
    }
    _size += n;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::replace(size_t pos, T new_value)
{
    _data[pos] = new_value;
    return *this;
}

template <typename T>
void TArchive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_archive_States[i] != archive_State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}

template <typename T>
TArchive<T>& TArchive<T>::erase(size_t pos, size_t n)
{
    for (int i = pos; i < pos + n; i++)
    {
        _archive_States[i] = archive_State::deleted;
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_all(T value)
{
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            _archive_States[i] = archive_State::deleted;
        }
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_first(T value)
{
    for (int i = 0; i < value; i++)
    {
        _archive_States[i] = archive_State::deleted;
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_last(T value)
{
    for (int i = _size - 1, j = 0; j < value; i--, j++)
    {
        _archive_States[i] = archive_State::deleted;
    }
    return *this;
}

template <typename T>
size_t* TArchive<T>::find_all(T value, size_t& count) const noexcept
{
    size_t* find_values;
    size_t _count = 0;
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            _count++;
        }
    }
    find_values = new size_t[_count];
    count = _count;
    _count = 0;
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            find_values[_count] = i;
            _count++;
        }
    }
    return find_values;
}

template <typename T>
size_t TArchive<T>::find_first(T value)
{
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
size_t TArchive<T>::find_last(T value)
{
    for (int i = _size; i >= 0; i--)
    {
        if (_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}