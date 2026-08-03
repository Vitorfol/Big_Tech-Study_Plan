#include <iostream>
#include <vector>
#include "tree_lib.h"

// Função auxiliar para imprimir vetores
void printVector(const std::string& name, const std::vector<int>& vec) {
    std::cout << name << ": ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

int main() {
    // Construindo uma árvore de 3 níveis (Raiz = Nível 0):
    // Nível 0:            4 (Raiz)
    //                   /   \
    // Nível 1:         2     6
    //                 / \   / \
    // Nível 2:       1   3 5   7
    
    TreeNode* root = new TreeNode(4); // Nível 0
    
    // Nível 1
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    
    // Nível 2
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    std::cout << "=== 1. Travessias na Árvore Original ===\n";
    std::vector<int> res;
    
    res.clear(); preOrder(root, res);  printVector("Pre-order", res);
    res.clear(); inOrder(root, res);   printVector("In-order (BST ordenada)", res);
    res.clear(); postOrder(root, res); printVector("Post-order", res);

    std::cout << "\n=== 2. Teste de Busca na BST ===\n";
    int target = 5;
    TreeNode* found = searchBST(root, target);
    if (found) {
        std::cout << "Valor " << target << " encontrado na árvore!\n";
    } else {
        std::cout << "Valor " << target << " nao encontrado.\n";
    }

    std::cout << "\n=== 3. Inversão da Árvore (Invert Binary Tree) ===\n";
    invertTree(root);
    
    res.clear(); 
    inOrder(root, res); 
    printVector("In-order apos inversão", res);

    return 0;
}
