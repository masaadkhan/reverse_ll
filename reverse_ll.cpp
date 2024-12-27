#include <iostream>

class Node {
  public:
  int val;
  Node* next;

  Node(int idx) {
    this->val = idx;
    // std::cout << "Constructed Node " << this->val << std::endl;
  }

  void print_ll(void) {
    Node* itr = this;

    while (itr != NULL) {
      std::cout << itr->val << ((itr->next != NULL) ? "->" : "");
      itr = itr->next;
    }
    std::cout << std::endl;
  }
};

std::string attempt_print(Node* node) {
  return (node != NULL) ? std::to_string(node->val) : "NULL";
}

int main() {
  Node* root = new Node(0);
  Node* itr = root;

  root->print_ll();

  for (int i = 1; i < 11; i++) {
    itr->next = new Node(i);
    itr->next->val = i;
    itr = itr->next;
    root->print_ll();
  }

  Node* last_node = itr;

  itr = root;
  Node* tmp_prev = NULL;
  Node* tmp_next = itr->next;

  // std::cout << std::endl;

  while (itr != NULL) {
    // std::cout << "itr->next = " << attempt_print(tmp_prev) << std::endl;
    // Reverse
    itr->next = tmp_prev;
    // Setup prev for the next itr
    // std::cout << "tmp_prev = " << attempt_print(itr) << std::endl;
    tmp_prev = itr;
    // Move pointer
    if (tmp_next == NULL) {
      break;
    }
    // std::cout << "itr = " << attempt_print(tmp_next) << std::endl;
    itr = tmp_next;
    // Setup next for next itr
    // std::cout << "tmp_next = " << attempt_print(itr->next) << std::endl;
    tmp_next = itr->next;
    // std::cout << std::endl;
  }

  // std::cout << std::endl;

  last_node->print_ll();
}
