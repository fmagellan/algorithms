// Copyright 2020 Magellan
#ifndef CPP_INCLUDE_AVLTREE_H_
#define CPP_INCLUDE_AVLTREE_H_

#include <iostream>

namespace Magellan {

template <class T>
class AvlTree {
    public:
        template <class NODE = T>
        class Node {
            public:
                NODE m_data;
                Node *m_left{ nullptr };
                Node *m_right{ nullptr };

                Node() = default;
                ~Node();
                int calculateHeight();
                int getHeight() const;

            private:
                int m_height{ 1 };

                void freeNode(Node *pNode);
        };

    private:
        Node<T> *m_root{ nullptr };

    public:
        AvlTree() = default;
        virtual ~AvlTree();

        Node<T>* getRoot() {
            return (m_root);
        }

        void setRoot(Node<T> *root) {
            m_root = root;
        }

        void recursiveInOrderDisplay();
        void recursivePreOrderDisplay();

        int height();
        void insertValue(const T &value);
        void deleteValue(const T &value);

    private:
        void recursiveInOrderTraversal(Node<T> *pNode);
        void recursivePreOrderTraversal(Node<T> *pNode);
        Node<T>* insertValue(Node<T> *pRootNode, const T &value);
        Node<T>* deleteValue(Node<T> *pRootNode, const T &value);
        Node<T>* leftLeftRotation(Node<T> *pRootNode);
        Node<T>* leftRightRotation(Node<T> *pRootNode);
        Node<T>* rightLeftRotation(Node<T> *pRootNode);
        Node<T>* rightRightRotation(Node<T> *pRootNode);
        Node<T>* L1Rotation(Node<T> *pRootNode);
        Node<T>* L0Rotation(Node<T> *pRootNode);
        Node<T>* LM1Rotation(Node<T> *pRootNode);
        Node<T>* R1Rotation(Node<T> *pRootNode);
        Node<T>* R0Rotation(Node<T> *pRootNode);
        Node<T>* RM1Rotation(Node<T> *pRootNode);
};

template <class T>
template <class NODE>
AvlTree<T>::Node<NODE>::~Node<NODE> () {
    if (m_left) {
        freeNode(m_left);
    }
    if (m_right) {
        freeNode(m_right);
    }
}

template <class T>
template <class NODE>
void AvlTree<T>::Node<NODE>::freeNode(Node<NODE> *pNode) {
    if (m_left) {
        delete (m_left);
    }

    if (m_right) {
        delete (m_right);
    }
}

template <class T>
template <class NODE>
int AvlTree<T>::Node<NODE>::getHeight() const {
    return (m_height);
}

template <class T>
template <class NODE>
int AvlTree<T>::Node<NODE>::calculateHeight() {
    int left{}, right{};
    if (m_left) {
        left = m_left->getHeight();
    }
    if (m_right) {
        right = m_right->getHeight();
    }

    if (m_left > m_right) {
        m_height = left + 1;
    } else {
        m_height = right + 1;
    }

    return (m_height);
}

template <class T>
AvlTree<T>::~AvlTree<T> () {
    delete (m_root);
}

template <class T>
void AvlTree<T>::recursiveInOrderDisplay() {
    std::cout << "InOrder display of AvlTree (recursive method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    recursiveInOrderTraversal(m_root);
    std::cout << "\n";
}

template <class T>
void AvlTree<T>::recursiveInOrderTraversal(Node<T> *pNode) {
    if (!pNode) {
        return;
    }

    recursiveInOrderTraversal(pNode->m_left);
    std::cout << pNode->m_data << ' ';
    recursiveInOrderTraversal(pNode->m_right);
}

template <class T>
void AvlTree<T>::recursivePreOrderDisplay() {
    std::cout << "PreOrder display of AvlTree (recursive method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    recursivePreOrderTraversal(m_root);
    std::cout << "\n";
}

template <class T>
void AvlTree<T>::recursivePreOrderTraversal(Node<T> *pNode) {
    if (!pNode) {
        return;
    }

    std::cout << pNode->m_data << ' ';
    recursivePreOrderTraversal(pNode->m_left);
    recursivePreOrderTraversal(pNode->m_right);
}

template <class T>
int AvlTree<T>::height() {
    if (!m_root) {
        return (0);
    }

    return (m_root->m_height());
}

template <class T>
void AvlTree<T>::insertValue(const T &value) {
    m_root = insertValue(m_root, value);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::insertValue(Node<T> *pRootNode, const T &value) {
    if (!pRootNode) {
        pRootNode = new Node<T>;
        pRootNode->m_data = value;
        return (pRootNode);
    }

    if (value == pRootNode->m_data) {
        return (pRootNode);
    }

    if (value < pRootNode->m_data) {
        pRootNode->m_left = insertValue(pRootNode->m_left, value);
    } else if (value > pRootNode->m_data) {
        pRootNode->m_right = insertValue(pRootNode->m_right, value);
    }

    // recalculate the height of the root node.
    pRootNode->calculateHeight();

    // check the balance of the node.
    int leftHeight{}, rightHeight{}, leftLeftHeight{}, leftRightHeight{};
    int rightLeftHeight{}, rightRightHeight{};
    if (pRootNode->m_left) {
        leftHeight = pRootNode->m_left->getHeight();
        if (pRootNode->m_left->m_left) {
            leftLeftHeight = pRootNode->m_left->m_left->getHeight();
        }
        if (pRootNode->m_left->m_right) {
            leftRightHeight = pRootNode->m_left->m_right->getHeight();
        }
    }
    if (pRootNode->m_right) {
        rightHeight = pRootNode->m_right->getHeight();
        if (pRootNode->m_right->m_left) {
            rightLeftHeight = pRootNode->m_right->m_left->getHeight();
        }
        if (pRootNode->m_right->m_right) {
            rightRightHeight = pRootNode->m_right->m_right->getHeight();
        }
    }

    // if if is more than 2, then do rotation.
    int rootBalance{ leftHeight - rightHeight };
    int leftBalance{ leftLeftHeight - leftRightHeight };
    int rightBalance{ rightLeftHeight - rightRightHeight };
    if ((rootBalance == 2) && (leftBalance == 1)) {
        pRootNode = leftLeftRotation(pRootNode);
    } else if ((rootBalance == 2) && (leftBalance == -1)) {
        pRootNode = leftRightRotation(pRootNode);
    } else if ((rootBalance == -2) && (rightBalance == 1)) {
        pRootNode = rightLeftRotation(pRootNode);
    } else if ((rootBalance == -2) && (rightBalance == -1)) {
        pRootNode = rightRightRotation(pRootNode);
    } else {
        return (pRootNode);
    }

    return (pRootNode);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::leftLeftRotation(Node<T> *pRootNode) {
    Node<T> *pLeftNode{ pRootNode->m_left };
    Node<T> *pLeftRightNode{ pLeftNode->m_right };

    pLeftNode->m_right = pRootNode;
    pRootNode->m_left = pLeftRightNode;

    pRootNode->calculateHeight();
    pLeftNode->calculateHeight();

    return (pLeftNode);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::leftRightRotation(Node<T> *pRootNode) {
    Node<T> *pLeftNode{ pRootNode->m_left };
    Node<T> *pLeftRightNode{ pLeftNode->m_right };

    pLeftNode->m_right = pLeftRightNode->m_left;
    pRootNode->m_left = pLeftRightNode->m_right;
    pLeftRightNode->m_left = pLeftNode;
    pLeftRightNode->m_right = pRootNode;

    pLeftNode->calculateHeight();
    pRootNode->calculateHeight();
    pLeftRightNode->calculateHeight();

    return (pLeftRightNode);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::rightLeftRotation(Node<T> *pRootNode) {
    Node<T> *pRightNode{ pRootNode->m_right };
    Node<T> *pRightLeftNode{ pRightNode->m_left };

    pRootNode->m_right = pRightLeftNode->m_left;
    pRightNode->m_left = pRightLeftNode->m_right;
    pRightLeftNode->m_left = pRootNode;
    pRightLeftNode->m_right = pRightNode;

    pRootNode->calculateHeight();
    pRightNode->calculateHeight();
    pRightLeftNode->calculateHeight();

    return (pRightLeftNode);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::rightRightRotation(Node<T> *pRootNode) {
    Node<T> *pRightNode{ pRootNode->m_right };
    Node<T> *pRightLeftNode{ pRightNode->m_left };

    pRightNode->m_left = pRootNode;
    pRootNode->m_right = pRightLeftNode;

    pRootNode->calculateHeight();
    pRightNode->calculateHeight();

    return (pRightNode);
}

template <class T>
void AvlTree<T>::deleteValue(const T &value) {
    m_root = deleteValue(m_root, value);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::deleteValue(Node<T> *pRootNode, const T &value) {
    if (!pRootNode) {
        return (pRootNode);
    }

    if (value < pRootNode->m_data) {
        pRootNode->m_left = deleteValue(pRootNode->m_left, value);
    } else if (value > pRootNode->m_data) {
        pRootNode->m_right = deleteValue(pRootNode->m_right, value);
    } else {
        // The last successor node has to be freed.
        if (!pRootNode->m_left) {
            Node<T> *pTemp = pRootNode->m_right;
            pRootNode->m_right = nullptr;
            delete (pRootNode);
            return (pTemp);
        }
        if (!pRootNode->m_right) {
            Node<T> *pTemp = pRootNode->m_left;
            pRootNode->m_left = nullptr;
            delete (pRootNode);
            return (pTemp);
        }

        // Get inorder successor.
        // Copy the data of it to the current node.
        // Delete the node with that successor value.
        int leftHeight{}, rightHeight{};
        if (pRootNode->m_left) {
            leftHeight = pRootNode->m_left->getHeight();
        }
        if (pRootNode->m_right) {
            rightHeight = pRootNode->m_right->getHeight();
        }

        if (leftHeight > rightHeight) {
            Node<T> *pSuccessorNode{ nullptr }, *pTempNode{ pRootNode->m_left };
            while (pTempNode) {
                pSuccessorNode = pTempNode;
                pTempNode = pTempNode->m_right;
            }

            pRootNode->m_data = pSuccessorNode->m_data;
            pRootNode->m_left = deleteValue(pRootNode->m_left, pSuccessorNode->m_data);
        } else {
            Node<T> *pSuccessorNode{ nullptr }, *pTempNode { pRootNode->m_right };
            while (pTempNode) {
                pSuccessorNode = pTempNode;
                pTempNode = pTempNode->m_left;
            }

            pRootNode->m_data = pSuccessorNode->m_data;
            pRootNode->m_right = deleteValue(pRootNode->m_right, pSuccessorNode->m_data);
        }
    }

    // Calculate the balance of the current node.
    // If it is unbalanced, then perform the necessary rotation.
    pRootNode->calculateHeight();
    int leftHeight{}, rightHeight{};
    int leftLeftHeight{}, leftRightHeight{};
    int rightLeftHeight{}, rightRightHeight{};
    if (pRootNode->m_left) {
        leftHeight = pRootNode->m_left->getHeight();
        if (pRootNode->m_left->m_left) {
            leftLeftHeight = pRootNode->m_left->m_left->getHeight();
        }
        if (pRootNode->m_left->m_right) {
            leftRightHeight = pRootNode->m_left->m_right->getHeight();
        }
    }
    if (pRootNode->m_right) {
        rightHeight = pRootNode->m_right->getHeight();
        if (pRootNode->m_right->m_left) {
            rightLeftHeight = pRootNode->m_right->m_left->getHeight();
        }
        if (pRootNode->m_right->m_right) {
            rightRightHeight = pRootNode->m_right->m_right->getHeight();
        }
    }

    int rootBalance{ leftHeight - rightHeight };
    int leftBalance{ leftLeftHeight - leftRightHeight };
    int rightBalance{ rightLeftHeight - rightRightHeight };
    if ((rootBalance == 2) && (leftBalance = 1)) {
        pRootNode = L1Rotation(pRootNode);
    } else if ((rootBalance == 2) && (leftBalance = -1)) {
        pRootNode = LM1Rotation(pRootNode);
    } else if ((rootBalance == 2) && (leftBalance = 0)) {
        pRootNode = L0Rotation(pRootNode);
    } else if ((rootBalance == -2) && (leftBalance = 1)) {
        pRootNode = R1Rotation(pRootNode);
    } else if ((rootBalance == -2) && (leftBalance = -1)) {
        pRootNode = RM1Rotation(pRootNode);
    } else if ((rootBalance == -2) && (leftBalance = 0)) {
        pRootNode = R0Rotation(pRootNode);
    }

    return (pRootNode);
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::L1Rotation(Node<T> *pRootNode) {
    return (leftLeftRotation(pRootNode));
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::L0Rotation(Node<T> *pRootNode) {
    return (leftLeftRotation(pRootNode));
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::LM1Rotation(Node<T> *pRootNode) {
    return (leftRightRotation(pRootNode));
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::R1Rotation(Node<T> *pRootNode) {
    return (rightLeftRotation(pRootNode));
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::R0Rotation(Node<T> *pRootNode) {
    return (RM1Rotation(pRootNode));
}

template <class T>
AvlTree<T>::Node<T>* AvlTree<T>::RM1Rotation(Node<T> *pRootNode) {
    return (rightRightRotation(pRootNode));
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_AVLTREE_H_
