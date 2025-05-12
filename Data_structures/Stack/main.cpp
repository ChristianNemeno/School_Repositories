#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    std::string data;
    Node* next;
    Node(std::string d) : data(d), next(nullptr) {}
};

struct Stack {
    Node* top;
    Stack() : top(nullptr) {}

    void push(std::string data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    std::string pop() {
        if (isEmpty()) {
            return "";
        }
        std::string data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string prefixToInfix(std::string exp) {
    Stack stack;
    std::reverse(exp.begin(), exp.end());

    for (char c : exp) {
        if (isOperator(c)) {
            std::string op1 = stack.pop();
            std::string op2 = stack.pop();
            std::string temp = "(" + op1 + " " + c + " " + op2 + ")";
            stack.push(temp);
        } else {
            stack.push(std::string(1, c));
        }
    }

    return stack.pop();
}

int main() {
    vector<string> testCases = {
        "*+AB-CD",
        "+A*BC",
        "*-A/BC-/AKL",
        "+*-ABC/-DAE",
        "+-A+BC+DE"
    };

    std::cout << "Testing prefix to infix conversion:\n";
    for (const auto& test : testCases) {
        std::cout << "Prefix:  " << test << std::endl;
        std::cout << "Infix:   " << prefixToInfix(test) << std::endl;
        std::cout << std::string(30, '-') << std::endl;
    }

    // Interactive test
    std::string userInput;
    std::cout << "Enter your own prefix expression (or 'q' to quit): ";
    while (std::getline(std::cin, userInput) && userInput != "q") {
        std::cout << "Infix:   " << prefixToInfix(userInput) << std::endl;
        std::cout << "Enter another prefix expression (or 'q' to quit): ";
    }
    return 0;
}