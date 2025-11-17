Trees
- collection of elems
- NODES
- one of the nodes = ROOT
- hierarchy of nodes
- parenthood

- every node is considered a tree, it is also a root (recursive defintition)

- suppose N is a node, T1, T2, T3... TN, are all trees with roots 
N1, N2, N3 respectively. we can make a new tree by making N a parent of nodes 
N1, N2, and N3 (tree-ception)
- there N1, N2, and N3, become children of node N

Path
- the path from node N1 to node NK is a sequence of nodes in a tree such that N
is the parent of Ni+1 for 1 <= i < k (iterate through the parent of each node)
- length of the path is one less than the number of nodes in the path
- a path of length zero exists as the path of every node to itself

Ancestor and Descendant 
- if there is a path from node A to node B, then A is an ancestor of B, and B is a
descendant of A
- a node is both an ancestor/descendant
- PROPER ancestor - ancestor to a node other than itself
- PROPER descendant - descendant to a node other than itself
- the root is the only node without a PROPER ancestor

Leaf, Null Tree, Subtree
- a LEAF is a node with no PROPER descendants
- a NULL TREE is a tree with no nodes
- a SUBTREE of a tree is a node, together with all of its descendants

Height and Depth
- height = node -> leaf 
- depth = root -> node

Order of Nodes
- the children of a node is ordered from left -> right

Order of Siblings
- the left -> right order of siblings can be extended to compare any two nodes that are not
  related by ancestor-descendant relationship
- if A and B are siblings, ad A is to the left of B, then all of the descendant of A are to the left of all the descendants of B

  Ordering of Nodes (traversal)
  - Preorder (first to last)
    -> the root of T
    -> nodes of T1 in pre-order
    -> nodes of T2 in pre-order and so on..
    
  - Postorder (last to first)
    -> the nodes of T1 in postorder
    -> nodes of T2 in postorder
    -> and so on..
    -> root of T

  - Inorder
    -> the nodes of T1 in order
    -> the root of T
    -> the nodes of T2 in order
    -> and so on..
    
