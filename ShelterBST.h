#include <string> 
#ifndef SHELTERBST_H
#define SHELTERBST_H 
using namespace std; 

class ShelterBST {
    
    private:
    struct Pet {
        string name; 
        int age;
        Pet(string name, int age) {
            this->name = name;
            this->age = age; 
        }
    };

    struct TreeNode {
        Pet* pet; // you must use a Pet pointer
        TreeNode* left;
        TreeNode* right;
        TreeNode(Pet* pet) {
            this->pet = pet;
            left = nullptr; 
            right = nullptr; 
        }
    };

    TreeNode* root;
    TreeNode* insert(TreeNode * root, Pet* pet);
    TreeNode* search(TreeNode *root, int age);
    void inorder(TreeNode * root);
    void preorder(TreeNode * root);
    void postorder(TreeNode * root);

    public:
    ShelterBST();
    void insertPet(string name, int age);
    void searchPet(int age);
    void inorderDisplay();
    void preorderDisplay();
    void postorderDisplay();
};

#endif //ShelterBST_h
