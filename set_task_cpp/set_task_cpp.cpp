#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
class Set {
public:
    Set() = default;

    void add(const T& item) {
        if (!contains(item)) {
            elements.push_back(item);
        }
    }

    void remove(const T& item) {
        elements.erase(std::remove(elements.begin(), elements.end(), item), elements.end());
    }

    bool contains(const T& item) const {
        return std::find(elements.begin(), elements.end(), item) != elements.end();
    }

    Set operator+(const Set& other) const {
        Set result(*this);
        for (const T& item : other.elements) {
            result.add(item);
        }
        return result;
    }

    Set operator-(const Set& other) const {
        Set result(*this);
        for (const T& item : other.elements) {
            result.remove(item);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Set& set) {
        os << "{ ";
        for (const auto& item : set.elements) {
            os << item << " ";
        }
        os << "}";
        return os;
    }

private:
    std::vector<T> elements;
};

int main() {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set<int> set2;
    set2.add(3);
    set2.add(4);
    set2.add(5);

    Set<int> unionSet = set1 + set2;
    std::cout << "Union of sets: " << unionSet << std::endl;

    Set<int> differenceSet = set1 - set2;
    std::cout << "Difference of sets: " << differenceSet << std::endl;

    Set<std::string> setStr1;
    setStr1.add("apple");
    setStr1.add("banana");

    Set<std::string> setStr2;
    setStr2.add("banana");
    setStr2.add("cherry");

    Set<std::string> unionSetStr = setStr1 + setStr2;
    std::cout << "Union of string sets: " << unionSetStr << std::endl;

    Set<std::string> differenceSetStr = setStr1 - setStr2;
    std::cout << "Difference of string sets: " << differenceSetStr << std::endl;

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}