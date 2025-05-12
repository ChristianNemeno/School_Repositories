#include <iostream>
#include <cassert>
#include <stack>
using namespace std;



// Function prototype
bool isPalindrome(string s){
    
    stack<char> pal;
    int l = s.length();
    int mid = s.length()/2;
    int i;
    for(i=0; i<mid; i++){
        pal.push(s[i]);
    }
// is odd
    if(l % 2 != 0){
        i++;
    }
    
    while(s[i] != '\0'){
        char elem = pal.top();
        pal.pop();

        if(elem != s[i++]){
            return false;
        }


    }

    
    return true;
}

// Test function
void testIsPalindrome() {
    // Test case 1: A basic palindrome
    assert(isPalindrome("madam") == true);

    // Test case 2: A single character (always a palindrome)
    assert(isPalindrome("a") == true);

    // Test case 3: An empty string (considered a palindrome)
    assert(isPalindrome("") == true);

    // Test case 4: A non-palindrome string
    assert(isPalindrome("hello") == false);

    // Test case 5: A numeric palindrome
    assert(isPalindrome("12321") == true);

    // Test case 6: A numeric non-palindrome
    assert(isPalindrome("12345") == false);

    // Test case 7: A palindrome with an even number of characters
    assert(isPalindrome("abba") == true);

    // Test case 8: A non-palindrome with an even number of characters
    assert(isPalindrome("abcd") == false);

    // Test case 9: A string with mixed case (not a palindrome because comparison is case-sensitive)
    assert(isPalindrome("Madam") == false);

    // Test case 10: A palindrome string with spaces (spaces are not ignored by this function)
    assert(isPalindrome("nurses run") == false);

    // Test case 11: A non-palindrome string with special characters
    assert(isPalindrome("!@#") == false);

    // If all test cases pass
    cout << "All test cases passed!" << endl;
}

int main() {
    testIsPalindrome(); // Run the test cases
    return 0;
}
