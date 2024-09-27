import graph.AbstractEdge;
import graph.Edge;
import graph.Graph;
import java.util.Collection;

public class PrimTest {

    public static void main(String[] args) {
        // Creazione di un grafo fittizio
        Graph<String, Float> testGraph = new Graph<>(false, true); // Grafo non diretto e con etichette float per i pesi degli archi

        // Aggiungere nodi
        testGraph.addNode("A");
        testGraph.addNode("B");
        testGraph.addNode("C");
        testGraph.addNode("D");

        // Aggiungere archi con pesi
        testGraph.addEdge("A", "B", 10.0f);
        testGraph.addEdge("A", "C", 15.0f);
        testGraph.addEdge("B", "D", 12.0f);
        testGraph.addEdge("C", "D", 8.0f);
        testGraph.addEdge("A", "D", 5.0f);  // Peso più basso tra A e D

        // Esegui Prim's algorithm
        Collection<? extends AbstractEdge<String, Float>> msf = Prim.minimumSpanningForest(testGraph);

        // Stampa i risultati della foresta ricoprente minima
        float totalDistance = 0;
        System.out.println("Minimum Spanning Forest Edges:");
        System.out.println("=============================");
        System.out.printf("%-20s %-20s %10s\n", "Start Place", "End Place", "Distance (Km)");

        for (AbstractEdge<String, Float> edge : msf) {
            System.out.printf("%-20s %-20s %10.2f\n", edge.getStart(), edge.getEnd(), edge.getLabel() / 1000); // Convert to Km
            totalDistance += edge.getLabel();
        }

        // Informazioni aggiuntive
        System.err.println("\nForest Information\n");
        System.err.printf("Total distance of the forest: %.2f Km\n", totalDistance / 1000);
        System.err.printf("Number of nodes in the graph: %d\n", testGraph.numNodes());
        System.err.printf("Number of edges in the forest: %d\n", msf.size());
    }
}
