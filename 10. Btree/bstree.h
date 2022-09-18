#ifndef BSTREE_H
#define BSTREE_H


//*************************************
//
// bstree.h
// CSCI 241 Assignment 11
//
// by Ryan Park z1940877
//
//*************************************


#include <iostream>
#include <iomanip>


using namespace std;

template<class K, class V>
class bstree;


template <class K, class V>
struct node
{
    K key;
    V value;
    node<K, V>* left;
    node<K, V>* right;

    node(const K& key = K(), const V& value = V(), node<K, V>* left = nullptr, node<K, V>* right = nullptr)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

template<class K, class V>
class bstree
{
private:

    node<K, V>* root;
    size_t t_size;

    // Private recursion functions
    void preorder(node<K, V>*) const;
    void inorder(node<K, V>*) const;
    void postorder(node<K, V>*) const;
    void level_order(node<K, V>*) const;
    size_t height(node<K, V>*) const;

public:

    // Constructor / Destructor / Copy / Assignment
    bstree();
    ~bstree();
    bstree(const bstree<K, V>&);
    bstree<K, V>& operator=(const bstree<K, V>&);

    // Utility
    node<K, V>* clone(node<K, V>*);
    void destroy(node<K, V>*);
    void clear();
    size_t size() const;
    bool empty() const;

    // Grabbers
    size_t height() const;
    const K& min() const;
    const K& max() const;
    void print_level(node<K, V>*, int) const;

    // Insert , remove , find
    bool insert(const K& key, const V& value);
    bool remove(const K& key);
    const node<K, V>* find(const K& key) const;

    // Traverse
    void preorder() const;
    void inorder() const;
    void postorder() const;
    void level_order() const;

};

/* Default constructor
 *
 *@param none
 *@return none
 ***********************/
template <class K, class V>
bstree<K, V>::bstree()
{
    this->root = nullptr;
    this->t_size = 0;
}


/* Destructor
 *
 *@param none
 *@return none
 **********************/
template <class K, class V>
bstree<K, V>::~bstree()
{
    if (!empty())
    {
        clear();
    }
}

/* Copy constructor
 *
 *@param refrence to const bstree object
 *@return none
 **********************/
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x)
{
    t_size = x.t_size;

    root = clone(x.root);
}

/* Copy Assignment 
 *
 *@param refrence to const bstree object
 *@return refence to bstree object
 *********************/
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x)
{
    if (this != &x)
    {
        clear();
        t_size = x.t_size;
        root = clone(x.root);
    }
    return *this;
}


/* Clones nodes of bstree object
 *
 *@param pointer to a node 
 *@return pointer to node or nullptr
 *************************/
template <class K, class V>
node<K, V>* bstree<K, V>::clone(node<K, V>* p)
{
    if (p != nullptr)
    {
        node<K, V>* new_node = new node<K, V>();

        new_node->key = p->key;
        new_node->value = p->value;

        new_node->left = clone(p->left);
        new_node->right = clone(p->right);

        return new_node;
    }
    else
        return nullptr;
}

/* Deletes nodes of bstree object
 *
 *@param pointer to a node in the tree
 *@return none
 *************************/
template<class K, class V>
void bstree<K, V>::destroy(node<K, V>* p)
{
    if (p!= nullptr)
    {
        destroy(p->left);
        destroy(p->right);

        delete p;
    }
}

/*  Returns tree to empty state
 *
 *@param none
 *@return none
 **************************/
template <class K, class V>
void bstree<K, V>::clear()
{
    destroy(root);
    root = nullptr;
    t_size = 0;
}

/* Returns tree size
 *
 *@param none
 *@return size_t of tree size
 **************************/

template <class K, class V>
size_t bstree<K, V>::size() const
{
    return t_size;
}





/* Public call to private recursion
 *
 *@param none
 *@return none
 ******************/
template <class K, class V>
size_t bstree<K, V>::height() const
{
    return height(root);
}

/* Returns height of tree
 *
 *@param none
 *@return size_t height
 ************************/
template <class K, class V>
size_t bstree<K, V>::height(node<K, V>* p) const
{
    size_t l_height;
    size_t r_height;

    if (p == nullptr)
        return 0;

    l_height = height(p->left);
    r_height = height(p->right);

    if (l_height > r_height)
        return l_height + 1;
    else
        return r_height + 1;
}


/* Returns min element in the tree
 *
 *@param none
 *@return refrence to K value
 *************************/
template <class K, class V>
const K& bstree<K, V>::min() const
{
    node<K, V>* p = root;

    while (p->left != nullptr)
    {
        p = p->left;
    }

    return(p->key);
}


/* Returns max element in the tree
 *
 *@param none
 *@return refrence to K value
 *************************/
template <class K, class V>
const K& bstree<K, V>::max() const
{
    node<K, V>* p = root;

    while (p->right != nullptr)
    {
        p = p->right;
    }

    return(p->key);
}



/* Checks if tree is empty
 *
 *@param none
 *@return bool true/false on case
 **************************/
template <class K, class V>
bool bstree<K, V>::empty() const
{
    if (t_size == 0)
        return true;
    else
        return false;
}




/* Inserts node into binary tree
 *
 *@param const K& key const V& value of template
 *@return bool true/false on case
 *************************/
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value)
{
    node<K, V>* p;
    node<K, V>* parent;

    p = root;
    parent = nullptr;

    // Duplicate check
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
            p = p->left;
        else
            p = p->right;
    }

    // Return false if duplicate is found
    if (p != nullptr)
        return false;

    node<K, V>* new_node = new node<K, V>(key,value);


    if (parent == nullptr)
    {
        root = new_node;
    }
    else
    {
        if (new_node->key < parent->key)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }
   
    t_size = t_size + 1;
    return true;
}


/* Removes key from binary tree
 *
 *@param const K& key
 *@return bool true/false on case
 *****************************/
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
    node<K, V>* p;
    node<K, V>* parent;
    node<K, V>* replace;
    node<K, V>* replace_parent;

    p = root;
    parent = nullptr;

    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // If the node to delete was not found return false
    if (p == nullptr)
    {
        return false;
    }

    // Case 1
    if (p->left == nullptr)
    {
        replace = p->right;
    }
    // Case 2
    else if (p->right == nullptr)
    {
        replace = p->left;
    }
    // Case 3
    else
    {
        replace_parent = p;
        replace = p->left;

        while (replace->right != nullptr)
        {
            replace_parent = replace;
            replace = replace->right;
        }
        
        if (replace_parent != p)
        {
            replace_parent->right = replace->left;
            replace->left = p->left;
        }
        replace->right = p->right;
    }

    // Connect replacement to parent node of p
    if (parent == nullptr)
    {
        root = replace;
    }
    else
    {
        if (p->key < parent->key)
            parent->left = replace;
        else
            parent->right = replace;
    }

    delete p;
    t_size = t_size - 1;
    return true;
}


/* Finds an element in the 
 *
 *@param const K refrence key
 *@retur either nullptr if not found
 *    or pointer to the node if found
 *************************************/
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const
{
    node<K, V>* p;

    p = root;

    while (p != nullptr && key != p->key)
    {
        if (key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

/* Public call to private recusrive function
 *
 * @param none
 *@return none
 *******************************************/
template <class K, class V>
void bstree<K, V>::preorder() const
{
    preorder(root);
}

/* Traverses Preorder left to right
 *  prints key and value
 *
 *@param none
 *@return none
 *****************************/
template <class K, class V>
void bstree<K, V>::preorder(node<K, V>* p) const
{
    if (p != nullptr)
    {
        cout << p->key << ": " << setprecision(2) << p->value << endl;
        preorder(p->left);
        preorder(p->right);
    }
}

/* Public call to private recusrive function
 *
 * @param none
 *@return none
 *******************************************/
template <class K, class V>
void bstree<K, V>::inorder() const
{
    inorder(root);
}

/* Traverses inorder left to right
 *  prints key and value
 *
 *@param none
 *@return none
 **************************/
template <class K, class V>
void bstree<K, V>::inorder(node<K, V>* p) const
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->key << ": " << setprecision(2) << p->value << endl;
        inorder(p->right);
    }
}


/* Public call to private recusrive function
 *
 * @param none
 *@return none
 *******************************************/
template <class K, class V>
void bstree<K, V>::postorder() const
{
    postorder(root);
}

/* Traverse postoder left to right
 *  prints key and value
 *
 *@param none
 *@return none
 ****************************/
template <class K, class V>
void bstree<K, V>::postorder(node<K, V>* p) const
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->key << ": " << setprecision(2) << p->value << endl;
    }
}


/* Traverse the binary tree in level order
 *
 *@param none
 *@return none
 *********************/
template <class K, class V>
void bstree<K, V>::level_order() const
{
    size_t h = height(root);

    size_t i = 1;

    while (i <= h)
    {
        print_level(root, i);
        i = i + 1;
    }
}



/* Used to visit node in level order
 *
 *@param node pointer and integer level 
 *@returns nothing
 **********************/
template <class K, class V>
void bstree<K, V>::print_level(node<K, V>* p, int level) const
{
    if (p == nullptr)
        return;

    if (level == 1)
        cout << p->key << ": " << setprecision(2) << p->value << endl;
    else if (level > 1)
    {
        print_level(p->left, level - 1);
        print_level(p->right, level - 1);
    }
}




#endif