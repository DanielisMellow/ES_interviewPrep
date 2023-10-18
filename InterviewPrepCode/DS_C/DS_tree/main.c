#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define BLANK -1

node *createNode(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

node *manualCreateTree(node *root) {
  node *tempRoot, *tempChild;
  int nodeValue = 0;
  queue nodeQueue;
  createQueue(&nodeQueue, 100);

  printf("Enter root value: ");
  scanf("%d", &nodeValue);
  root = createNode(nodeValue);
  enqueue(&nodeQueue, root);

  while (!isEmpty(&nodeQueue)) {
    tempRoot = dequeue(&nodeQueue);
    printf("Enter Left Child Value of %d: ", tempRoot->data);
    scanf("%d", &nodeValue);
    if (nodeValue != BLANK) {
      tempChild = createNode(nodeValue);
      tempRoot->left = tempChild;
      enqueue(&nodeQueue, tempChild);
    }
    printf("Enter Right Child Value of %d: ", tempRoot->data);
    scanf("%d", &nodeValue);
    if (nodeValue != BLANK) {
      tempChild = createNode(nodeValue);
      tempRoot->right = tempChild;
      enqueue(&nodeQueue, tempChild);
    }
  }
  freeQueue(&nodeQueue);
  return root;
}

node *insert(node *root, int key) {
  if (root == NULL) {
    return createNode(key);
  }

  // Traverse the tree with recursion
  if (key < root->data) {
    root->left = insert(root->left, key);
  } else if (key > root->data) {
    root->right = insert(root->right, key);
  }

  return root;
}

node *search(node *root, int key) {
  if (root == NULL || root->data == key)
    return root;

  if (key < root->data) {
    return search(root->left, key);
  }

  return search(root->right, key);
}

// Delete a Node from a Binary Search Tree

// Function to find the minimum value node in the BST
node *minValueNode(node *node_ref) {
  node *current = node_ref;
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current;
}

// Delete a specific node in a BST
node *delete(node *root, int data) {
  if (root == NULL) {
    return root;
  }
  // If the data to be deleted is smaller than the root's data,
  // then it lies in the left subtree
  if (data < root->data) {
    root->left = delete (root->left, data);
  }
  // If the data to be deleted is larger than the root's data,
  // then it lies in the right subtree
  else if (data > root->data) {
    root->right = delete (root->right, data);
  } else {
    // Node with only one child or no child
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children: get the inorder successor
    // (smallest in the right subtree)
    node *temp = minValueNode(root->right);

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = delete (root->right, temp->data);
  }
  return root;
}

void preOrder(node *root_ref) {
  if (root_ref != NULL) {
    printf("%d ", root_ref->data);
    preOrder(root_ref->left);
    preOrder(root_ref->right);
  }
}

void inOrder(node *root_ref) {
  if (root_ref != NULL) {
    inOrder(root_ref->left);
    printf("%d ", root_ref->data);
    inOrder(root_ref->right);
  }
}

void postOrder(node *root_ref) {
  if (root_ref != NULL) {
    postOrder(root_ref->left);
    postOrder(root_ref->right);
    printf("%d ", root_ref->data);
  }
}

void levelOrder(node *root_ref) {
  queue nodeQueue;
  createQueue(&nodeQueue, 100);

  printf("%d ", root_ref->data);
  enqueue(&nodeQueue, root_ref);

  while (!isEmpty(&nodeQueue)) {
    root_ref = dequeue(&nodeQueue);
    if (root_ref->left != NULL) {
      printf("%d ", root_ref->left->data);
      enqueue(&nodeQueue, root_ref->left);
    }
    if (root_ref->right != NULL) {
      printf("%d ", root_ref->right->data);
      enqueue(&nodeQueue, root_ref->right);
    }
  }
  freeQueue(&nodeQueue);
}

int countNodes(node *root_ref) {
  if (root_ref == NULL) {
    return 0;
  }

  return countNodes(root_ref->left) + countNodes(root_ref->right) + 1;
}

int height(node *root_ref) {
  int leftHeight = 0;
  int rightHeight = 0;

  if (root_ref == NULL) {
    return -1;
  }

  leftHeight = height(root_ref->left);
  rightHeight = height(root_ref->right);

  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countLeafNodes(node *root_ref) {
  if (root_ref == NULL) {
    return 0;
  }

  // If node doesn't have left or right child, its a leaf
  if (root_ref->left == NULL && root_ref->right == NULL) {
    return 1;
  }
  return countLeafNodes(root_ref->left) + countLeafNodes(root_ref->right);
}

void freeTree(node *root) {
  if (root == NULL)
    return;

  // Free Left and Right children
  freeTree(root->left);
  freeTree(root->right);

  // Then Free Root
  free(root);
}

int main(int argc, char *argv[]) {

  node *root = NULL;
  int keyArr[] = {16, 4, 64, 2, 8, 32, 128};
  int size = sizeof(keyArr) / sizeof(keyArr[0]);
  // root = manualCreateTree(root);

  for (int i = 0; i < size; i++) {
    root = insert(root, keyArr[i]);
  }
  // delete (root, 16);
  printf("Pre-Order:   ");
  preOrder(root);

  printf("\nIn-Order:    ");
  inOrder(root);

  printf("\nPost-Order:  ");
  postOrder(root);

  printf("\nLevel-Order: ");
  levelOrder(root);
  printf("\n");

  printf("\n\nThe Number of nodes in the tree: %d\n", countNodes(root));
  printf("The Height of the tree: %d\n", height(root));
  printf("The Number of leaf nodes in the tree: %d\n", countLeafNodes(root));

  freeTree(root);
  return EXIT_SUCCESS;
}
