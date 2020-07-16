#include <stdio.h>
#include <time.h>
#include <cstdlib>

typedef struct BSTnode{
    int val;
    struct BSTnode* right;
    struct BSTnode* left;
    struct BSTnode* parent;
} BSTnode;

void add_node(BSTnode* &root, int value){
    ??
}

void free_BST(BSTnode* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        free_BST(root->left);
    }
    if(root->right != NULL){
        free_BST(root->right);
    }
    delete root;
    return;
}

BSTnode* min(BSTnode* root){
    ??
}

BSTnode* max(BSTnode* root){
    ??
}

BSTnode* succ(BSTnode* node){
    if(node->right != NULL){
        return ??
    }else{
        ??
    }
}

BSTnode* search(BSTnode* root, int val){
    // Base Cases: root is null or key is present at root
    if(root == NULL || root->val == val){
       return ??;
    }
    // Key is greater than root's key
    if(root->val < val){
        return ??;
    }
    // Key is smaller than root's key
    return ??;
}

int sum_in_range(BSTnode* node, int min_value, int max_value){
    BSTnode* left = // search min_value node
    BSTnode* right = // search max_value node
    int sum = 0;
    while(left != right){
        // iterate from left to right and sum
    }
    sum += right->val; //suming the last element
    return sum;
}

int main(){
    /*
     * test data:
     * Z - number of test cases
     * N, MIN, MAX - number of insert values, min range, max range
     * N values to insert
     * Output:
     * sum
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for(int i = 0 ; i < Z ; i++){
        int N, MI, MA;
        scanf("%d %d %d", &N, &MI, &MA);

        BSTnode* tree = NULL;

        int x;
        // insert
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &x);
            add_node(tree, x);
        }

        int sum = sum_in_range(tree, MI, MA);
        printf("%d\n", sum);

        // cleanup
        free_BST(tree);
    }
}
