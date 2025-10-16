#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual void add(const T& item) = 0;
    virtual void remove(int index) = 0;
    virtual T get(int index) const = 0;
    virtual int size() const = 0;
    virtual ~List() {}
};

#endif // LIST_H

