#include "ShelterBST.h"
#include <iostream> 
#include <string> 
using namespace std;

//Private Methods: 
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet) {

    //if the tree is empty creates new tree node for the pet
    if (root == nullptr) {
        return new TreeNode(pet); 
    } else if (pet->age > root->pet->age) {
        root->right = insert(root->right, pet);
    } else {
        root->left = insert(root->left, pet); 
    } 
    return root; 
}

ShelterBST::TreeNode* ShelterBST::search(TreeNode *root, int age) {

    if (root == nullptr || root->pet->age == age) {
        return root; 
    }

    if (age < root->pet->age) {
        return search(root->left, age); 
    } else {
        return search(root->right, age); 
    }
}

void ShelterBST::inorder(TreeNode * root) {
    
    if (root == nullptr) {
        return;
    
    } else {
        inorder(root->left); 
        cout << root->pet->name << ", " << root->pet->age << endl; 
        inorder(root->right); 
    }
}

void ShelterBST::preorder(TreeNode * root) {

    if (root == nullptr) {
        return;
    
    } else {
        cout << root->pet->name << ", " << root->pet->age << endl; 
        preorder(root->left); 
        preorder(root->right); 
    }
}

void ShelterBST::postorder(TreeNode * root) {
    
    if (root == nullptr) {
        return;
    
    } else {
        postorder(root->left); 
        postorder(root->right); 
        cout << root->pet->name << ", " << root->pet->age << endl; 
    }
}

//Public Methods: 
ShelterBST::ShelterBST() {
    root = nullptr;
}
        
void ShelterBST::insertPet(string name, int age){
    
    root = insert(root, new Pet(name, age));
    
}
        
void ShelterBST::searchPet(int age){
    
    TreeNode* result = search(root, age);
    if (result) {
        cout << result->pet->name << " was found!" << endl; 
    } else {
        cout << "Pet was not found, sorry" << endl; 
    }
}

void ShelterBST::inorderDisplay(){
    inorder(root);
}
        
void ShelterBST::preorderDisplay(){
    preorder(root);
}

void ShelterBST::postorderDisplay(){
    postorder(root);
}