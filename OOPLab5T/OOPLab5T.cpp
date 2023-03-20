#include <iostream>
#include<queue>
#include <string>

class Quadrilateral {
public:
    virtual void print() = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Quadrilateral() {}
};

class Square : public Quadrilateral {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void print() override {
        std::cout << "Square with side " << side << "\n";
    }
    double area() override {
        return side * side;
    }
    double perimeter() override {
        return 4 * side;
    }
};

class Rectangle : public Quadrilateral {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void print() override {
        std::cout << "Rectangle with length " << length << " and width " << width << "\n";
    }
    double area() override {
        return length * width;
    }
    double perimeter() override {
        return 2 * (length + width);
    }
};

void task1() {
    Square sq(6);
    Rectangle rect(2, 4);

    std::cout << "Square area: " << sq.area() << "\n";
    std::cout << "Square perimeter: " << sq.perimeter() << "\n";
    std::cout << "Rectangle area: " << rect.area() << "\n";
    std::cout << "Rectangle perimeter: " << rect.perimeter() << "\n";
}


class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
    ~Node() {}
};

class BinaryTree {
public:
    Node* root;// Вказівник на корінь дерева
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {}

    void insert(int v) {// Додавання елемента до дерева
        Node* node = new Node(v);// Створення нового вузла
        if (root == nullptr) {
            root = node;
            return;
        }
        Node* curr = root;
        while (true) {// Додаємо вузол
            if (v < curr->value) {
                if (curr->left == nullptr) {
                    curr->left = node;
                    break;
                }
                curr = curr->left;
            }
            else if (v > curr->value) {
                if (curr->right == nullptr) {
                    curr->right = node;
                    break;
                }
                curr = curr->right;
            }
            else {
                std::cout << "Value already in tree\n";
                delete node;
                break;
            }
        }
    }

    void breadth_first_traversal() {
        if (root == nullptr) {
            std::cout << "Empty tree\n";
            return;
        }
        std::queue<Node*> q; // Створення черги
        q.push(root); // Додаємо корінь до черги;
        while (!q.empty()) {
            Node* curr = q.front();// Беремо перший елемент з черги
            q.pop();// Видаляємо
            std::cout << curr->value << " ";
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        std::cout << "\n";
    }

    void post_order_traversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        std::cout << node->value << " ";
    }
};

void task2() {
    BinaryTree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    std::cout << "Breadth-first traversal:\n";
    tree.breadth_first_traversal();

    std::cout << "Post-order traversal:\n";
    tree.post_order_traversal(tree.root);
    std::cout << "\n";
}


class String {
protected:
    std::string str;
public:
    String() : str("") {}

    String(std::string s) : str(s) {}

    virtual ~String() {}

    // Перевантаження оператора виведення потоку
    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.str;
        return os;
    }

    // Введення від перевантаження оператора потоку
    friend std::istream& operator>>(std::istream& is, String& s) {
        is >> s.str;
        return is;
    }

    // Перевантаження оператора присвоювання
    String& operator=(const String& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

    String(const String& other) : str(other.str) {}
};

class NumberString : public String {
public:
    NumberString() : String("") {}

    NumberString(std::string s) : String(s) {}

    ~NumberString() {}

    // Перевантаження оператора виведення потоку
    friend std::ostream& operator<<(std::ostream& os, const NumberString& s) {
        os << s.str;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, NumberString& s) {
        is >> s.str;
        // Перевірка цифр
        for (char c : s.str) {
            if (!isdigit(c)) {
                throw std::invalid_argument("Input string is not a number.");
            }
        }
        return is;
    }

    // Перевантаження оператора присвоювання
    NumberString& operator=(const NumberString& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

    // Конструктор копіювання
    NumberString(const NumberString& other) : String(other.str) {}
};

int task3() {
    String s("Hello");
    std::cout << s << std::endl;
    String s2;
    std::cin >> s2;
    std::cout << s2 << std::endl;

    NumberString ns("123");
    std::cout << ns << std::endl;
    NumberString ns2;
    std::cin >> ns2;
    std::cout << ns2 << std::endl;

    return 0;
}


int main() {
    int choice;

    do {
        std::cout << "Select task:\n";
        std::cout << "1. Task 1: Quadrilaterals\n";
        std::cout << "2. Task 2: Binary Tree\n";
        std::cout << "3. Task 3: Strings\n";
        std::cout << "0. Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
