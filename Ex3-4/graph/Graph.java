package graph;

import java.util.*;

public class Graph<V,L>  implements AbstractGraph<V,L> {
    private boolean directed;
    private boolean labelled;
    private Map<V, Map<V, L>> adjacencyMap;
    private int edgeCount;

    public Graph(boolean directed, boolean labelled) {
        this.directed = directed;
        this.labelled = labelled;
        this.adjacencyMap = new HashMap<>();
        this.edgeCount = 0;
    }

    @Override
    public boolean isDirected() {
        return directed;
    }

    @Override
    public boolean isLabelled() {
        return labelled;
    }

    @Override
    public boolean addNode(V a) {
        if (adjacencyMap.containsKey(a)) {
            return false;
        }
        adjacencyMap.put(a, new HashMap<>());
        return true;
    }


    @Override
    public boolean addEdge(V a, V b, L l) {
        // Check if node 'a' exists; if not, add it to the graph.
        if (!adjacencyMap.containsKey(a)) {
            addNode(a);
        }
        // Check if node 'b' exists; if not, add it to the graph.
        if (!adjacencyMap.containsKey(b)) {
            addNode(b);
        }
        // if the graph is unlabelled, force the label to be null
        if (!labelled) {
            l =  null;
        }
        // Check if the edge (a, b) or (b, a) already exists
        if (adjacencyMap.get(a).containsKey(b) || (!directed && adjacencyMap.get(b).containsKey(a))) {
            System.out.println("Edge from " + a + " to " + b + " already exists");
            return false;
        }

        //add edge from a to b with label l
        adjacencyMap.get(a).put(b, l);
        //if the graph is undirected also add edge from b to a
        if (!directed) {
            adjacencyMap.get(b).put(a,l);
        }
        //increment the edge cout and return true to indicate the success of the operation
        edgeCount++;
        return true;
    }

    @Override
    public boolean containsNode(V a) {
        return adjacencyMap.containsKey(a);
    }
    public boolean containsEdge(V a, V b) {
        if (!adjacencyMap.containsKey(a) || !adjacencyMap.containsKey(b)) {
            return false;
        }
        // Check if there is an edge from a to b and from b to a
        boolean hasEdgeAB = adjacencyMap.get(a).containsKey(b);
        boolean hasEdgeBA = adjacencyMap.get(b).containsKey(a);

        return hasEdgeAB || hasEdgeBA;
    }
    @Override
    public boolean removeNode(V a) {
        // check if node 'a' exists
        if (!adjacencyMap.containsKey(a)) {
            System.out.println("Node " + a + " doesn't exists ");
            return false;
        }
        // Remove the node 'a' and retrieve its neighbors (adjacent nodes)
        Map<V,L> neighbors = adjacencyMap.remove(a);
        // Decrease the edge count by the number of edges connected to the removed node.
        edgeCount -= neighbors.size();
        if (!directed) {
            // If the graph is undirected, also remove all edges pointing to 'a'.
            for (V neighbor : neighbors.keySet()) {
                adjacencyMap.get(neighbor).remove(a);
                edgeCount--; // Adjust for undirected edge removal.
            }
        } else {
            // If the graph is directed, remove edges that have 'a' as their destination.
            for (Map<V, L> adjacent : adjacencyMap.values()) {
                if (adjacent.remove(a) != null) {
                    edgeCount--; // Only decrement if an edge was removed.
                }
            }
        }

        return true; // Node 'a' and all related edges were successfully removed.

    }

    @Override
    public boolean removeEdge(V a, V b) {
        // Check if the graph contains both the source node 'a' and the destination node 'b'.
        if (!adjacencyMap.containsKey(a) || !adjacencyMap.containsKey(b)) {
        return false;
        }
        //remove edge from 'a' to 'b'
        adjacencyMap.get(a).remove(b);
        //if the graph is undirected also remove edge from b to a 
        if (!directed) {
            adjacencyMap.get(b).remove(a);
        }
        //decrement edge count to reflect removed edge
        edgeCount--;
        return true; //edge successufylly removed
    }

    @Override
    public int numNodes() {
        return adjacencyMap.size();
    }

    @Override
    public int numEdges() {
        return edgeCount;
    }

    @Override
    public Collection<V> getNodes() {
        // returns all the nodes (keys) of the hashMap
        return adjacencyMap.keySet();
    }

    @Override
    public Collection<? extends AbstractEdge<V, L>> getEdges() {
        // retirieves all edges in the graph using an array list
        List<AbstractEdge<V,L>> allEdges = new ArrayList<>();
        // loop through each node and its adjacency map in the adjacency list
        // Map.Entry to access both the key and the value of each entry in the map.
        // entry in a map where key is type V and value is type Map<V,L>
        // for each node in the
        for (Map.Entry<V, Map<V,L>> nodeEntry : adjacencyMap.entrySet()) {
            V startNode = nodeEntry.getKey(); // current node being examinated
            Map<V,L> neighbors = nodeEntry.getValue();
            for (Map.Entry<V, L> neighborEntry : neighbors.entrySet()) {
                V endNode = neighborEntry.getKey();
                L label = neighborEntry.getValue();
                allEdges.add(new Edge<>(startNode, endNode, label));
            }
        }
        return allEdges;
    }

    @Override
    public Collection<V> getNeighbours(V a) {
        if (!adjacencyMap.containsKey(a)) {
            throw new IllegalArgumentException("Node does not exist: " + a);
        }
        // return all keys for key a --> where key in adjacency map = A return key of map<V,L>
        return adjacencyMap.get(a).keySet();
    }

    @Override
    public L getLabel(V a, V b) {
        if (!adjacencyMap.containsKey(a) || !adjacencyMap.get(a).containsKey(b)) {
            return null; // Edge does not exist
        }
        // .get(a) returns map<>, .get(b) returns value of map which is label
        return adjacencyMap.get(a).get(b);
    }
}
