#include <iostream>
#include "MyBinaryTree.h" // Assuming BST is defined in BST.h

void showMenu() {
    std::cout << "\n--- Binary Search Tree Menu ---\n";
    std::cout << "1. Insert a Node\n";
    std::cout << "2. Delete a Node\n";
    std::cout << "3. Display In-Order Traversal\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BST* tree = new BST();
    int choice, value;

    do {
        
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                tree->insert(value);
                std::cout << "Inserted " << value << " into the BST.\n";
                break;
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                tree->deleteNode(value);
                std::cout << "Deleted " << value << " from the BST (if it existed).\n";
                break;
            case 3:
                tree->inorder();
                break;
            
            case 4:
                
                break;
            
            case 9:
                std::cout << "Exiting program. Goodbye!\n";
                break;

            
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
