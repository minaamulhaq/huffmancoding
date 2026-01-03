#include "myQueue.h"
#include "HuffmanNode.h"
#include "SimpleMap.h"
#include <string>
using namespace std;
int HuffmanNode::getFrequency()
{
    return root->freq;
}
HuffmanNode::HuffmanNode(unsigned char d, int n)
{

    root = new Node;
    root->data = d;
    root->freq = n;
    root->leftChild = nullptr;
    root->rightChild = nullptr;
}

HuffmanNode::~HuffmanNode()
{
    deleteTree(root);
}

Node *HuffmanNode::getRoot()
{
    return root;
}

HuffmanNode::HuffmanNode(HuffmanNode *left, HuffmanNode *right)
{
    root = new Node;
    root->data = '\0';
    root->freq = left->getFrequency() + right->getFrequency();
    root->leftChild = left->getRoot();
    root->rightChild = right->getRoot();

    left->root = nullptr;
    right->root = nullptr;
    delete left;
    delete right;
}

HuffmanNode *HuffmanNode::buildHuffmanTree(myQueue &q)
{
    while (true)
    {
        HuffmanNode *first = q.dequeue();

        if (q.isEmpty())
        {
            // sirf ek node bachi � ye hi root hai

            return first;
        }

        HuffmanNode *second = q.dequeue();

        // merge two smallest nodes
        HuffmanNode *merged = new HuffmanNode(first, second);

        // wapas queue mein daal do
        q.enqueue(merged);
    }
    return nullptr;
}

void HuffmanNode::generateCodes(
    Node *root,
    unsigned int currentBits,
    int currentLength,
    SimpleMap &map)
{
    if (!root)
        return;

    // Leaf node
    if (root->leftChild == nullptr && root->rightChild == nullptr)
    {
        map.insert(root->data, currentBits, currentLength);
        return;
    }

    // Left → add 0
    generateCodes(
        root->leftChild,
        (currentBits << 1),
        currentLength + 1,
        map);

    // Right → add 1
    generateCodes(
        root->rightChild,
        (currentBits << 1) | 1,
        currentLength + 1,
        map);
}
