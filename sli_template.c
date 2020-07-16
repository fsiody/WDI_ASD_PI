

int main(int argc, char** argv) {
    /*
     * test data:
     * Z - number of test cases
     * h, I - max height of single node (h), number of values to insert (I)
     * I values to insert
     * Output:
     * I lines, subsequent values stored in list
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for (int i=0; i<Z; i++) {
        int h, I;
        scanf("%d", &h);
        scanf("%d", &I);

        SkipList* list = newSkipList(h);
        int x;
        // insert
        for(int j=0; j<I; j++) {
            scanf("%d", &x);
            insert(list, newNode(x, h));
        }
        // print all values
        Node* iter = list->start, tmp;
        while(/*...*/) {
            printf("%d\n", iter->next[0]->val);
            iter = iter->next[0];
        }
        
        // cleanup
        
    }
}