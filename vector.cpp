#include <iostream>

template <typename T>
class vector{
    
private:
    T *data;
    unsigned int size_, capacity_;

    void increase_capacity(){
        T *new_data = new T[capacity_<<1];
        for (unsigned int i=0 ; i<capacity_ ; ++i)
            new_data[i] = data[i];
        delete []data;
        capacity_<<=1;
        data = new_data;
    }

public:
    vector(){
        // std::cerr << "DEBUG: Construtor chamado\n";
        data = new T[8];
        size_ = 0;
        capacity_ = 8;
    }

    ~vector(){
        // std::cerr << "DEBUG: Destrutor chamado\n";
        delete []data;
    }

    void push_back(T value){
        if (size_==capacity_)
            increase_capacity();
        data[size_] = value;
        size_++;
    }
    unsigned int size(){
        return size_;
    }
    const T get_element_at(unsigned int index) const{
        return data[index];
    }
};

int main(){
    vector<int> v1;
    vector<int> *v2;
    vector<std::string> v3;
    v3.push_back(std::string("Isto é um teste!"));
    v3.push_back(std::string("Isto é outro teste!"));
    v2 = new vector<int>();
    v1.push_back(10);
    v1.push_back(20);
    v2->push_back(101);
    v2->push_back(201);
    std::cout << "Tamanho: " << v1.size() << std::endl;
    for (unsigned int i=0 ; i< v1.size() ; ++i)
        std::cout << v1.get_element_at(i) << " ";
    std::cout << std::endl;
    for (unsigned int i=1 ; i<18 ; ++i)
        v1.push_back(i*3);
    for (unsigned int i=0 ; i< v1.size() ; ++i)
        std::cout << v1.get_element_at(i) << " ";
    std::cout << std::endl;
    for (unsigned int i=0 ; i< v2->size() ; ++i)
        std::cout << v2->get_element_at(i) << " ";
    std::cout << std::endl;
    std::cout << v3.size() << std::endl;
    for (unsigned int i=0 ; i<v3.size() ; ++i){
        auto x = v3.get_element_at(i);
        std::cout << x << "\n";
    }
    std::cout << std::endl;
    delete v2;
    return 0;
}