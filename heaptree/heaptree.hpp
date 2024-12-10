
#ifndef HEAPTREE_HPP

#define HEAPTREE_HPP

// #include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
    int key_;
    T value_;
    Node<T> *left_ = nullptr;
    Node<T> *right_ = nullptr;

    Node() = default;
    Node(int key, T value)
        : key_(key), value_(value) {}
    ~Node() = default;
};

template <class T>
class HeapTree
{
public:
    HeapTree() = default;

    ~HeapTree()
    {
        delete_(root_);
    };

    void Insert(const int key, const T value)
    {
        insert_(root_, key, value);
    };

    void Remove(const int key)
    {
        root_ = remove_(root_, key);
    };

    T Search(const int key)
    {
        return search_(root_, key);
    };

    void Print()
    {
        print_(root_);
        std::cout << std::endl;
    }

    // std::ostream &WriteTo(std::ostream &ostrm, HeapTree<T> &rhs) const noexcept;

private:
    Node<T> *root_ = nullptr;

    void insert_(Node<T> *node, int key, const T value)
    {
        if (node == nullptr)
        {
            root_ = new Node<T>(key, value);
        }
        else if (key < node->key_)
        {
            if (node->left_ == nullptr)
                node->left_ = new Node<T>(key, value);
            else
                insert_(node->left_, key, value);
        }
        else if (key > node->key_)
        {
            if (node->right_ == nullptr)
                node->right_ = new Node<T>(key, value);
            else
                insert_(node->right_, key, value);
        }
        else if (key == node->key_)
        {
            throw std::runtime_error("Inserting a duplicate key is not possible!");
        }
    }

    T search_(Node<T> *node, int key)
    {
        if (node == nullptr)
        {
            throw std::runtime_error("You cannot search for data in an empty tree!");
        }
        if (key == node->key_)
        {
            return node->value_;
        }
        else if (key < node->key_)
        {
            return search_(node->left_, key);
        }
        else
        {
            return search_(node->right_, key);
        }
    }

    Node<T> *get_max_(Node<T> *node)
    {
        if (node == nullptr)
            throw std::runtime_error("You cannot get the maximum key in an empty tree!");
        if (node->right_ == nullptr)
            return node;
        return get_max_(node->right_);
    }

    Node<T> *remove_(Node<T> *node, int key)
    {
        if (node == nullptr)
            return nullptr;
        else if (key < node->key_)
            node->left_ = remove_(node->left_, key);
        else if (key > node->key_)
            node->right_ = remove_(node->right_, key);
        else
        {
            if (node->left_ == nullptr || node->right_ == nullptr)
            {
                Node<T> *temp = node;
                if (node->left_ == nullptr)
                    node = node->right_;
                else
                    node = node->left_;
                delete temp;
            }
            else
            {
                Node<T> *max_in_left = get_max_(node->left_);
                node->key_ = max_in_left->key_;
                node->value_ = max_in_left->value_;
                node->left_ = remove_(node->left_, max_in_left->key_);
            }
        }
        return node;
    }

    void print_(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        print_(node->left_);
        std::cout << node->key_ << "-" << node->value_ << " ";
        print_(node->right_);
    }

    void delete_(Node<T> *node)
    {
        if (node != nullptr)
        {
            if (node->left_ != nullptr)
            {
                delete_(node->left_);
            }
            if (node->right_ != nullptr)
            {
                delete_(node->right_);
            }
            delete node;
        }
        return;
    }
};

#endif // !HEAPTREE_HPP