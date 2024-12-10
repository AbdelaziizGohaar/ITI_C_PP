#include <iostream>
#include <vector>
#include <variant>
#include <string>


class MultiTypeList {
public:
    using ValueType = std::variant<int, double, std::string>; // Add all types i want here

    /
    void add(const ValueType& value) {
        items.push_back(value);
    }

    void print() const {
        for (const auto& item : items) {
            std::visit([](const auto& value) {
                std::cout << value << " ";
            }, item);
        }
        std::cout << std::endl;
    }

private:
    std::vector<ValueType> items;
};

int main() {
    MultiTypeList list;

    list.add(42);
    list.add(3.14);
    list.add("Hello, World!");

    list.print();

    return 0;
}
