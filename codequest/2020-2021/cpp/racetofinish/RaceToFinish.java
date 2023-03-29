package racetofinish;

import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class RaceToFinish {
    private PriorityQueue<Path> openList = new PriorityQueue<>(Comparator.comparing(it -> it.f()));
    private Grid grid = new Grid();

    public static void main(String[] args) {
        RaceToFinish raceToFinish = new RaceToFinish();
        raceToFinish.grid.parse();
        System.out.println(raceToFinish.findPath());
    }


    public Path findPath() {
        Node startNode = grid.getStart();
        List<Node> dest = grid.getDest();
        return dest.stream().map(destNode -> {
            Set<Node> closeList = new HashSet<>();
            // Default speed, {0, 0}.
            openList.add(new Path(destNode, startNode, null, 0, 0, 0));

            do {
                var cur = openList.poll();
                closeList.add(cur.pos());
                for (var neighbour : cur.findNeighbours(grid, closeList)) {
                    if (dest.contains(neighbour.pos())) {
                        return neighbour;
                    }
                    var inOpenList = false;
                    for (var p : openList) {
                        if (p.pos() == neighbour.pos() && p.f() > neighbour.f()) {
                            openList.remove(p);
                            openList.add(neighbour);
                            inOpenList = true;
                            break;
                        }
                    }
                    if (!inOpenList) openList.add(neighbour);
                }
            } while (!openList.isEmpty());
            throw new IllegalArgumentException("Does not exists a path");
        }).min(Comparator.comparing(path -> path.getPath().size())).orElseThrow();
    }
}

class Grid {
    private Node[][] grid;
    private List<Node> dest = new LinkedList<>();
    private Node start;
    private static Scanner scan = new Scanner(System.in);

    public Grid() {
    }

    public Node getNode(int x, int y) {
        return grid[x][y];
    }

    public int getWidth() {
        return grid.length;
    }

    public List<Node> getDest() {
        return dest;
    }

    public Node getStart() {
        return start;
    }

    public int getHeight() {
        return grid[0].length;
    }

    public void parse() {
        int height = scan.nextInt(), width = scan.nextInt();
        scan.nextLine();
        grid = new Node[height][width];
        for (int i = 0; i < height; i++) {
            String line = scan.nextLine();
            for (int j = 0; j < width; j++) {
                var type = NodeType.fromChar(line.charAt(j));
                var node = new Node(i, j, type);
                grid[i][j] = node;
                if (type == NodeType.START) {
                    start = node;
                } else if (type == NodeType.DEST) {
                    dest.add(node);
                }
            }
        }
    }
}

record Path(Node dest, Node pos, Path parent, int g, int speedx, int speedy) {
    public static Set<Function<Integer, Integer>> possibleVelocity = Set.of(
            (x) -> x + 1,
            (x) -> x - 1,
            (x) -> x
    );

    public int f() {
        return g + pos.heuristic(dest);
    }

    public Set<Path> findNeighbours(Grid grid, Set<Node> closeList) {
        return possibleVelocity.stream()
                .flatMap(xFunc -> possibleVelocity.stream().map(yFunc -> List.of(xFunc.apply(speedx), yFunc.apply(speedy)))) // All possible velocities
                .filter(v -> v.stream().allMatch(vC -> vC >= -3 && vC <= 3)) // No pass speed limit
                .filter(v -> {
                    int x = pos.x() + v.get(0), y = pos.y() + v.get(1);
                    return 0 <= x && x < grid.getWidth() && 0 <= y && y < grid.getHeight();
                }) // Don't go out of bounds
                .filter(v -> {
                    int x = pos.x() + v.get(0), y = pos.y() + v.get(1);
                    Node node = grid.getNode(x, y);
                    return node.type() != NodeType.WALL && !closeList.contains(node);
                }) // Don't go through walls and closelist
                .map(v -> new Path(dest, grid.getNode(pos.x() + v.get(0), pos.y() + v.get(1)), this, g + 1, v.get(0), v.get(1))) // Create new path
                .collect(Collectors.toSet());
    }

    public List<Path> getPath() {
        Stack<Path> pathStack = new Stack<>();
        pathStack.add(this);
        var p = parent;
        var count = 0;
        while (p != null) {
            pathStack.push(p);
            p = p.parent;
            count++;
        }
        var res = new ArrayList<Path>(count);
        while (!pathStack.isEmpty()) {
            res.add(pathStack.pop());
        }
        return res;
    }

    @Override
    public String toString() {
        var paths = getPath();
        var res = new StringBuilder(paths.size() << 4);
        int count = 1;
        for (var path : paths) {
            res.append(String.format("%-3d\t(%3d, %3d)\t(%3d, %3d)%n", count++, path.pos.x(), path.pos.y(), path.speedx, path.speedy));
        }
        return res.toString();
    }
}

record Node(int x, int y, NodeType type) {
    public int heuristic(Node dest) {
        return Math.abs(x - dest.x) + Math.abs(y - dest.y);
    }
}

enum NodeType {
    EMPTY,
    WALL,
    START,
    DEST;

    // TODO - HashMap<Character, NodeType>-HashMap<NodeType, Character> for faster lookup
    public static NodeType fromChar(char c) {
        return switch (c) {
            case ' ' -> EMPTY;
            case '#' -> WALL;
            case 'C' -> START;
            case '$' -> DEST;
            default -> throw new IllegalArgumentException("Invalid block type");
        };
    }

    @Override
    public String toString() {
        return switch (this) {
            case EMPTY -> " ";
            case WALL -> "#";
            case START -> "C";
            case DEST -> "$";
        };
    }
}
