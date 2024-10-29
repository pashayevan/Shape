#include <iostream>
#include <string>
#include <vector>

template<typename T>
void Process(const T& form) {
    std::cout<<form.GetCenter()<<"\n";

class Shape {
protected:
    std::pair<int, int> Form;
public:
    Shape(int h, int w): form(h,w){}
    std::pair<int, int> GetForm() const {
        return form;
    }
    virtual std::string rectangle() const=0;
    virtual ~Shape(){}
};

class quadrangle: public Shape {
public:
    quadrangle(const std::string& n): Shape(n){}
    std::string rectangle() const override{
        return "4";
    }
};

int main() {
    std::vector<Shape*> figure;
    figure.push_back(new quadrangle("square"));
    Process(*figure[0]);
    for(Shape* shape: figure) {
        delete shape;
    }
}