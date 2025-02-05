#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// تعريف هيكل العقدة في شجرة البحث الثنائية
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// دالة لإنشاء عقدة جديدة
TreeNode* createNode(int value, TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("Error of memory\n");
        return NULL;
    }
    node->val = value;
    node->left = left;
    node->right = right;
    return node;
}

// دالة لإضافة قيمة إلى شجرة البحث الثنائية
void addNode(TreeNode **root, int value) {
    if (*root == NULL) {
        *root = createNode(value, NULL, NULL);
    } else if (value < (*root)->val) {
        addNode(&(*root)->left, value);
    } else {
        addNode(&(*root)->right, value);
    }
}

// دالة لملء الأشجار الفارغة
void fillEmptyTrees(TreeNode **trees, int n) {
    srand(time(NULL));  // تخصيص العشوائية
    for (int i = 0; i < n; i++) {
        if (trees[i] == NULL) {
            int numNodes = rand() % n + 1; // عدد عشوائي من العقد بين 1 و n
            for (int j = 0; j < numNodes; j++) {
                addNode(&trees[i], rand() % 1000); // إدخال قيم عشوائية
            }
        }
    }
}

// دالة لترتيب المصفوفة باستخدام ترتيب الفقاعات
void bubbleSort(TreeNode **trees, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (trees[j]->val > trees[j + 1]->val) {
                TreeNode *temp = trees[j];
                trees[j] = trees[j + 1];
                trees[j + 1] = temp;
            }
        }
    }
}

// دالة لعرض شجرة باستخدام الترتيب المسبق (Pre-order)
void printPreOrder(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// دالة للبحث عن قيمة في شجرة معينة
int search(TreeNode *root, int value) {
    while (root != NULL) {
        if (root->val == value) {
            return 1; // القيمة موجودة
        } else if (value < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0; // القيمة غير موجودة
}

int main() {
    int n, value, choice;

    printf("Enter the size of array (n): ");
    scanf("%d", &n);

    TreeNode **trees = (TreeNode **)malloc(n * sizeof(TreeNode *));
    for (int i = 0; i < n; i++) {
        trees[i] = NULL;
    }

    // إضافة قيم إلى الأشجار
    for (int i = 0; i < n; i++) {
        printf("Enter value for tree %d: ", i + 1);
        scanf("%d", &value);
        addNode(&trees[i], value);
    }

    // ملء الخانات الفارغة تلقائيًا
    fillEmptyTrees(trees, n);

    // عرض الأشجار
    for (int i = 0; i < n; i++) {
        printf("Tree %d: ", i + 1);
        printPreOrder(trees[i]);
        printf("\n");
    }

    // إظهار قائمة العمليات
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a value to a tree\n");
        printf("2. Sort trees by root value\n");
        printf("3. Search a value in a tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            free(trees);
            break;
        }

        int index;
        switch (choice) {
            case 1:
                printf("Enter tree index and value: ");
                scanf("%d %d", &index, &value);
                addNode(&trees[index - 1], value);
                break;
            case 2:
                bubbleSort(trees, n);
                printf("Trees sorted by root value.\n");
                break;
            case 3:
                printf("Enter tree index and value to search: ");
                scanf("%d %d", &index, &value);
                if (search(trees[index - 1], value)) {
                    printf("Value found in tree %d\n", index);
                } else {
                    printf("Value not found in tree %d\n", index);
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
