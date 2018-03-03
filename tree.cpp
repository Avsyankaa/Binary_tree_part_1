#include <iostream>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
  Node *parent;
};
class Tree {
 public:
  Node *root;
  bool working = true;
  Tree() { root = nullptr; }
  void Add(Node *&root, int data, Node *&parent) {
    if (root == nullptr) {
      root = new Node{data, nullptr, nullptr, root};
    } else {
      if (data < root->data) Add(root->left, data, root);
      if (data > root->data) Add(root->right, data, root);
      if (data == root->data) {
        cout << "error!!! repeated elements!!!" << endl;
        working = false;
        return;
      }
    }
  }
  void Add_item(int data) { Add(root, data, root); }
  ~Tree() {}
};
void Menu(Tree *&tree) {
  if (tree->working == false)
    return;
  else {
    string exit;
    int choise;
    while ((exit != "y") && (exit != "yes") && (exit != "Y") &&
           (exit != "Yes") && (exit != "YES")) {
      cout << "Select one of the operations:" << endl;
      cout << "1.Print the tree on the screen" << endl;
      cout << "2.List the nodes of the tree" << endl;
      cout << "3.Add a node to the tree" << endl;
      cout << "4.Remove the node from the tree" << endl;
      cout << "5.Save tree to a file" << endl;
      cout << "6.Load the tree from a file" << endl;
      cout << "7.Check node availability" << endl;
      cout << "8.Complete the program" << endl;
      cin >> choise;
      switch (choise) {
        case 8:
          cout << "Do you want to leave program? ( yes, no )" << endl;
          cin >> exit;
          if ((exit == "y") || (exit == "yes") || (exit == "Y") ||
              (exit == "Yes") || (exit == "YES"))
            cout << "Good by!";
          break;
      }
    }
  }
}
int main(int argc, char *argv[]) {
  Tree *tree = new Tree;
  for (int i = 1; i < argc; i++) {
    tree->Add_item(atoi(argv[i]));
  };
  Menu(tree);
  delete tree;
}
