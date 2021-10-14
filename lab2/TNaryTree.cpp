#include "TNaryTree.h"
#include "TNaryTree_item.h"

TNaryTree::TNaryTree(int n)
{
    this->size = n;
    this->cur_size = 0;
    this->root = nullptr;
}

TreeItem* tree_copy(TreeItem* root)
{
    if (root != nullptr) {
        TreeItem* new_root = new TreeItem;
        new_root->figure = root->figure;
        new_root->son = nullptr;
        new_root->brother = nullptr;
        if (root->son != nullptr) {
            new_root->son = tree_copy(root->son);
        }
        if (root->brother != nullptr) {
            new_root->brother = tree_copy(root->brother);
        }
        return new_root;
    }
    return nullptr;
}

TNaryTree::TNaryTree(const TNaryTree& other)
{
    this->cur_size = 0;
    this->size = other.size;
    this->root = tree_copy(other.root);
}

void TNaryTree::Update(TreeItem** root, octagon polygon, std::string tree_path)
{
    if (tree_path == "") {
        if (this->size == 0) {
            throw std::out_of_range("Tree is overflow\n");
            return;
        }
        if (*root == nullptr) {
        *root = new TreeItem;
        (*root)->figure = polygon;
        (*root)->brother = nullptr;
        (*root)->son = nullptr;
        this->cur_size++;
        } else {
            (*root)->figure = polygon;
        }
        return;
    }
    TreeItem* cur = *root;
    if (cur == NULL) {
        throw std::invalid_argument("Vertex doesn't exist in the path\n");
        return;
    }
    for (int i = 0; i < tree_path.size() - 1; i++) {
        if (tree_path[i] == 'c') {
            cur = cur->son; 
        } else {
            cur = cur->brother;
        }
        if (cur == nullptr && i < tree_path.size() - 1) {
            throw std::invalid_argument("Vertex doesn't exist in the path\n");
            return;
        }
    }
    if (tree_path[tree_path.size() - 1] == 'c' && cur->son == nullptr) {
        if (this->cur_size + 1 > this->size) {
            throw std::out_of_range("Tree is overflow\n");
            return;
        }
        if (cur->son == nullptr) {
            cur->son = new TreeItem;
            cur->son->figure = polygon;
            cur->son->son = nullptr;
            cur->son->brother = nullptr;
            this->cur_size++;
        } else {
            cur->son->figure = polygon;
        }
    } else if (tree_path[tree_path.size() - 1] == 'b' && cur->brother == nullptr) {
        if (this->cur_size + 1 > this->size) {
            throw std::out_of_range("Tree is overflow\n");
            return;
        }
        if (cur->brother == nullptr) {
            cur->brother = new TreeItem;
            cur->brother->figure = polygon;
            cur->brother->son = nullptr;
            cur->brother->brother = nullptr;
            this->cur_size++;
        } else {
            cur->brother->figure = polygon;
        }
    }
}

void delete_tree(TreeItem** root)
{
    if ((*root)->son != nullptr) {
        delete_tree(&((*root)->son));
    }
    if ((*root)->brother != nullptr) {
        delete_tree(&((*root)->brother));
    }
    *root = nullptr;
    delete *root;
}

void delete_undertree(TreeItem** root, char c)
{
    if (*root == nullptr) {
        return;
    }
    if (c == 'b') {
        if ((*root)->brother != nullptr) {
            TreeItem* cur = (*root)->brother;
            if ((*root)->brother->brother != nullptr) {
                (*root)->brother = (*root)->brother->brother;
                cur->brother = nullptr;
                delete_tree(&cur);
            } else {
                delete_tree(&((*root)->brother));
            }
        }
    } else if (c == 'c') {
        TreeItem* cur = (*root)->son;
        if ((*root)->son->brother != nullptr) { 
            (*root)->son = (*root)->son->brother;
        } else {
            delete_tree(&((*root)->son));
        }
        if (cur->son != nullptr) {
            std::cout << cur->figure;
            delete_tree(&(cur->son));
            delete cur;
            cur = nullptr;
        }
    }
}

void TNaryTree::Clear(std::string &&tree_path)
{
    if (tree_path == "") {
        TreeItem** iter = &(this->root);
        delete_tree(iter);
        return;
    }
    TreeItem* cur = this->root;
    for (int i = 0; i < tree_path.size() - 1; i++) {
        if (tree_path[i] == 'c') {
            cur = cur->son;
        } else if (tree_path[i] == 'b') {
            cur = cur->brother;
        }
    }
    if (tree_path[tree_path.size() - 1] == 'c') {
        delete_undertree(&cur, 'c');
    } else if (tree_path[tree_path.size() - 1] == 'b') {
        delete_undertree(&cur, 'b');
    }
    return;
}

void TNaryTree::Clear(std::string &tree_path)
{
    if (tree_path == "") {
        TreeItem** iter = &(this->root);
        delete_tree(iter);
        return;
    }
    TreeItem* cur = this->root;
    for (int i = 0; i < tree_path.size() - 1; i++) {
        if (tree_path[i] == 'c') {
            cur = cur->son;
        } else if (tree_path[i] == 'b') {
            cur = cur->brother;
        }
    }
    if (cur == nullptr) {
        std::cout << "а вот и сегментация!";
    }
    if (tree_path[tree_path.size() - 1] == 'c') {
        delete_undertree(&cur, 'c');
    } else if (tree_path[tree_path.size() - 1] == 'b') {
        delete_undertree(&cur, 'b');
    }
    return;
}

bool TNaryTree::Empty()
{
    if (!this->cur_size) {return true;}
    return false;
}

double TNaryTree::Area(std::string &&tree_path)
{
    if (tree_path == "") {
        return this->root->figure.Area();
    }
    TreeItem* cur = this->root;
    double square = 0;  
    for (int i = 0; i < tree_path.size(); i++) {
        if (tree_path[i] == 'c') {
            cur = cur->son;
        } else {
            cur = cur->brother;
        } square += cur->figure.Area();
    }
    return square + this->root->figure.Area();
}

double TNaryTree::Area(std::string &tree_path)
{
    if (tree_path == "") {
        return this->root->figure.Area();
    }
    TreeItem* cur = this->root;
    double square = 0;  
    for (int i = 0; i < tree_path.size(); i++) {
        if (tree_path[i] == 'c') {
            cur = cur->son;
        } else {
            cur = cur->brother;
        } square += cur->figure.Area();
    }
    return square + this->root->figure.Area();
}

void Print(std::ostream& os, TreeItem* vertex)
{
    if (vertex != nullptr) {
        std::cout << vertex->figure.Area();
        if (vertex->son != nullptr) {
            std::cout << ": " << "[";
            Print(os, vertex->son);
            if (vertex->son->brother == nullptr && vertex->brother != nullptr) {
                std::cout << "]";
            }
        }
        if (vertex->brother != nullptr) {
            std::cout << ", ";
            Print(os, vertex->brother);
            std::cout << "]";
        }
    } else {
        return;
    }
}

std::ostream& operator<<(std::ostream& os, const TNaryTree& tree)
{   
    Print(os, tree.root); os << "\n";
    return os;
}

TNaryTree::~TNaryTree()
{
    this->Clear("");
}
