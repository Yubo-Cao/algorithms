# Graph and Search

## Storage of Tree & Graph

## Depth-first Search (DFS)

- It will always come down to the leaf node, as much as possible.
- Use a `stack` to implement. It will only remember all the nodes in the path, using $O(N)$ spaces.
- It may not find the shortest path to reach a node.

## Breadth-first Search (BFS)

- It will check each node, layer by layer.
- Use a `queue` to implement. It will remember each layer's nodes. Hence, using $O(2^h)$ spaces, where $h$ is the height of the tree.
- It will always find the shortest path to reach a node.


## Depth-first & Breath-first Iteration

## Topological sort
