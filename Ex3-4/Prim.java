import graph.AbstractEdge;
import graph.Edge;
import graph.Graph;
import priorityQueue.PriorityQueue;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Prim {
    public static class EdgeWeightComparator<V, L extends Number> implements Comparator<Edge<V, L>> {
        @Override
        public int compare(Edge<V, L> edge1, Edge<V, L> edge2) {
            if (edge1 == null && edge2 == null) return 0;
            if (edge1 == null) return -1;
            if (edge2 == null) return 1;

            //if (edge1.getLabel() == null && edge2.getLabel() == null) return 0;
            //if (edge1.getLabel() == null ) return -1;
            //if (edge2.getLabel() == null) return 1;

            // use .doubleValue() to convert to double because L extends number which could represent any subclass (Integer,Float,Double)
            double labelFirstEdge = edge1.getLabel().doubleValue();
            double labelSecondEdge = edge2.getLabel().doubleValue();
            return Double.compare(labelFirstEdge,labelSecondEdge);
        }
    }
    // prim's alghoritm to find minimum spanning forest
    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        // Calculate the minimum spanning forest using Prim's algorithm
        // Returns the collection of edges that form the forest
        // Use set interface to track visited nodes since 'Set' can't have duplicates
        Set<V> visitedNodes = new HashSet<>();
        // List to store edges of the minimum spanning forest
        List<Edge<V, L>> edgesMsf = new ArrayList<>();
        PriorityQueue<Edge<V, L>> pq = new PriorityQueue<>(new EdgeWeightComparator<>());

        // Iterate through all nodes to handle disconnected forests
        for (V startNode : graph.getNodes()) {
            // If the node has not been visited yet, visit it
            if (!visitedNodes.contains(startNode)) {
                // Start from an unvisited node and explore graph
                visitGraph(graph, startNode, visitedNodes, pq);

                // Process priority queue
                while (!pq.empty()) {
                    Edge<V, L> edge = pq.top();
                    pq.pop();
                    V startingNode = edge.getStart();
                    V endNode = edge.getEnd();
                    // Check if nodes are already visited, if yes skip the elaboration
                    if (visitedNodes.contains(startingNode) && visitedNodes.contains(endNode)) {
                        continue;
                    }
                    // Add edge to list and visited node to the set
                    edgesMsf.add(edge);

                    if (!visitedNodes.contains(endNode)) {
                        visitedNodes.add(endNode);
                        visitGraph(graph, endNode, visitedNodes, pq);
                    }
                }
            }
        }
        return edgesMsf;
    }


    public static <V, L extends Number> void visitGraph(Graph<V,L> graph,V currentNode, Set<V> visitedNode, PriorityQueue<Edge<V,L>> pq){
        // add current node to visited to keep track of visited nodes
        visitedNode.add(currentNode);
        for(V neighbor : graph.getNeighbours(currentNode)) {
            if (!visitedNode.contains(neighbor)) {
                L edgeWeight = graph.getLabel(currentNode, neighbor);
                pq.push(new Edge<>(currentNode, neighbor, edgeWeight));
            }

        }
    }
    public static void main(String[] args) {
        // leggi i dati CSV del grafo dal percorso in args[1]
        // calcola la minima foresta ricoprente con minimumSpanningForest
        // scrivi su standard output solo la descrizione della foresta calcolata come CSV con formato analogo a quello in input
        // su standard error si possono scrivere ulteriori informazioni, come il numero di nodi e archi nella foresta calcolata,
        // o il peso totale della foresta
        if (args.length < 1) {
            System.err.println(" Wrong path for csv file ");
            return;
        }
        // create undirected graph and labelled
        Graph<String, Float> italian_dist_graph = new Graph<>(false, true);

        try(BufferedReader bufferedReader = new BufferedReader(new FileReader(args[0]))) {
            // line in csv file
            String csv_line;
            int lineCount = 0;
            // read each line in csv file
            while ((csv_line = bufferedReader.readLine()) != null ){
                String[] columns = csv_line.split(",");
                if (columns.length !=3 )
                    continue;

                //declare variables for fields in csv
                String place1 = columns[0].trim();
                String place2 = columns[1].trim();
                float distance = Float.parseFloat(columns[2].trim());

                // add nodes and edge to graph
                // Add nodes and edge to graph
                italian_dist_graph.addNode(place1);
                italian_dist_graph.addNode(place2);

                // Check if the edge already exists to avoid duplication
                if (!italian_dist_graph.containsEdge(place1, place2) && !italian_dist_graph.containsEdge(place2, place1)) {
                    italian_dist_graph.addEdge(place1, place2, distance);
                }
                lineCount++;
            }
            System.out.println(lineCount);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // Compute the minimum spanning forest using Prim's algorithm
        Collection<? extends AbstractEdge<String, Float>> msf = minimumSpanningForest(italian_dist_graph);

        //for each edge in msf
        double totalDistance = 0;

        // Print the edges of the minimum spanning forest
        System.out.println("Minimum Spanning Forest Edges:");

        System.out.println("=============================");
        System.out.printf("%-20s %-20s %10s\n", "Start Place", "End Place", "Distance (Km)");
        for (AbstractEdge<String, Float> edge : msf) {
            System.out.printf("%-20s %-20s %10.2f\n", edge.getStart(), edge.getEnd(), edge.getLabel() / 1000); // Convert to Km for display
             totalDistance += edge.getLabel();
        }

        // Print additional information to standard error
        System.err.println("\nForest Information\n");

        System.err.printf("Total distance of the forest: %.2f Km\n", totalDistance / 1000);
        System.err.printf("Number of places (nodes): %d\n", italian_dist_graph.numNodes());
        System.err.printf("Number of edges in the forest ): %d\n", msf.size());
    }


}
