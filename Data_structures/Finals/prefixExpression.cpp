#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;



double evaluatePrefix(string expression){

    int endPointer = expression.length();
    stack<double> myStack;

    double op1;
    double op2;

    for(int i = endPointer-1; i>=0; i--){
        
        if(isdigit(expression[i])){
            // means operand siya
            myStack.push(expression[i] - '0');
        }else{
            // operator
            op1 = myStack.top();
            myStack.pop();
            op2 = myStack.top();
            myStack.pop();
            
            switch(expression[i]){
                case '+':
                    myStack.push(op1 + op2);
                break;

                case '-':
                    myStack.push(op1 - op2);
                break;
                
                case '/':
                    myStack.push(op1 / op2);
                break;

                case '*':
                    myStack.push(op1 * op2);
                break;
            }

        }

        
    }
    return myStack.top();

}
void runTest(string expression, double expected) {
    double result = evaluatePrefix(expression);
    cout << "Expression: " << expression << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "Got: " << result << "\n";
    cout << (abs(result - expected) < 0.0001 ? "PASSED" : "FAILED") << "\n\n";
}
int main() {
    // Test Case 1: Simple addition
    runTest("+23", 5);  // 2 + 3 = 5

    // Test Case 2: Simple multiplication
    runTest("*45", 20); // 4 * 5 = 20

    // Test Case 3: Simple subtraction
    runTest("-72", 5);  // 7 - 2 = 5

    // Test Case 4: Simple division
    runTest("/84", 2);  // 8 / 4 = 2

    // Test Case 5: Two operations
    runTest("+9*26", 21); // 9 + (2 * 6) = 21

    // Test Case 6: Three operations
    runTest("*+234", 20); // (2 + 3) * 4 = 20

    // Test Case 7: Complex expression with multiplication and addition
    runTest("+*23*45", 26); // (2 * 3) + (4 * 5) = 26

    // Test Case 8: Complex expression with division
    runTest("*+2/63-51", 28); // (2 + (6 / 3)) * (5 - 1) = 28

    // Test Case 9: Expression with multiple operations
    runTest("-*+234/82", 16); // ((2 + 3) * 4) - (8 / 2) = 16

    // Test Case 10: Complex expression with all operations
    runTest("+*-321/84", 3); // ((3 - 2) * 1) + (8 / 4) = 3

    return 0;
}