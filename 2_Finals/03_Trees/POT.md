Characteristics of POT
- similar to bst, 2 children
- height is a minimum for the number of nodes
- at the lowest level, required that all missing leaves are
to the right of all the leaves present in the lowest level
- priority of the parent is less than or equal to the priority
of the children (Parent <= Child)

Steps in INSERT() Operation

1. Place new element x at the lowest level to the right of the leaves present OR to the next level if current level is full.

2. while(x is not the root, and POT property is not satisfied)
2.a SWAP(Parent, x);

Steps in DeleteMin() Operation
1. min = root node;
2. Replace root node with the element x found at the lowest level, rightmost leaf.
3. While ((x is not a leaf) and POT property is not satisfied)
3.a SChild = smallerChild of x;
3.b Swap(X, SChild);
4. return min;

Runtime
- For both operations is O(log2 N).
- Maximum path of the tree is 1 + log2 N nodes.

Implementation of POT
Heap: Array Implementation of POT.

HeapSort
Step 1: Given a List, Insert all elements in an initially empty POT or Heapify the list
Step 2: Perform Deletemin until the heap becomes empty.
