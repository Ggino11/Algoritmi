package test;

import graph.AbstractEdge;
import graph.Graph;
import org.junit.Before;
import org.junit.Test;

import java.util.Collection;

import static org.junit.Assert.*;

public class GraphTests {

    private Graph<String, Integer> directedLabelledGraph;
    private Graph<String, Integer> undirectedUnlabelledGraph;
    private Graph<String, Float> undirectedLabelledGraph;

    @Before
    public void setUp() {
        // Initialize graphs before each test
        directedLabelledGraph = new Graph<>(true, true);
        undirectedUnlabelledGraph = new Graph<>(false, false);
        undirectedLabelledGraph = new Graph<>(true, true);
    }

    @Test
    public void testAddNode() {
        assertTrue(directedLabelledGraph.addNode("A"));
        assertFalse(directedLabelledGraph.addNode("A")); // Node A already exists
        assertTrue(directedLabelledGraph.containsNode("A"));
    }

    @Test
    public void testAddEdgeDirectedLabelled() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        assertTrue(directedLabelledGraph.addEdge("A", "B", 5));
        assertTrue(directedLabelledGraph.containsEdge("A", "B"));
        assertEquals(1, directedLabelledGraph.numEdges());
        assertEquals(Integer.valueOf(5), directedLabelledGraph.getLabel("A", "B"));
    }

    @Test
    public void testAddEdge() {
        undirectedLabelledGraph.addNode("A");
        undirectedLabelledGraph.addNode("B");
        assertTrue(undirectedLabelledGraph.addEdge("A", "B", 10.5f));
        assertTrue(undirectedLabelledGraph.containsEdge("A", "B"));
        assertTrue(undirectedLabelledGraph.containsEdge("B", "A")); // Since it's undirected
        assertEquals(10.5f, undirectedLabelledGraph.getLabel("A", "B"), 0.01);
        assertEquals(1, undirectedLabelledGraph.numEdges());
    }

    @Test
    public void testAddEdgeUndirectedUnlabelled() {
        undirectedUnlabelledGraph.addNode("A");
        undirectedUnlabelledGraph.addNode("B");
        assertTrue(undirectedUnlabelledGraph.addEdge("A", "B", null));
        assertTrue(undirectedUnlabelledGraph.containsEdge("A", "B"));
        assertTrue(undirectedUnlabelledGraph.containsEdge("B", "A")); // Since it's undirected
        assertEquals(1, undirectedUnlabelledGraph.numEdges());
        assertNull(undirectedUnlabelledGraph.getLabel("A", "B"));
    }

    @Test
    public void testRemoveNode() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        directedLabelledGraph.addEdge("A", "B", 5);
        assertTrue(directedLabelledGraph.removeNode("A"));
        assertFalse(directedLabelledGraph.containsNode("A"));
        assertFalse(directedLabelledGraph.containsEdge("A", "B"));
        assertEquals(0, directedLabelledGraph.numEdges());
    }

    @Test
    public void testRemoveEdge() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        directedLabelledGraph.addEdge("A", "B", 5);
        assertTrue(directedLabelledGraph.removeEdge("A", "B"));
        assertFalse(directedLabelledGraph.containsEdge("A", "B"));
        assertEquals(0, directedLabelledGraph.numEdges());
    }

    @Test
    public void testGetNeighbours() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        directedLabelledGraph.addEdge("A", "B", 5);
        Collection<String> neighbours = directedLabelledGraph.getNeighbours("A");
        assertTrue(neighbours.contains("B"));
        assertEquals(1, neighbours.size());
    }

    @Test
    public void testGetNeighboursUndirectedUnlabelled() {
        undirectedUnlabelledGraph.addNode("A");
        undirectedUnlabelledGraph.addNode("B");
        undirectedUnlabelledGraph.addEdge("A", "B", null);
        Collection<String> neighbours = undirectedUnlabelledGraph.getNeighbours("A");
        assertTrue(neighbours.contains("B"));
        assertEquals(1, neighbours.size());
    }


    @Test
    public void testGetNeighboursUndirectedLabelled() {
        // Test di base per una coppia di nodi
        undirectedLabelledGraph.addNode("A");
        undirectedLabelledGraph.addNode("B");
        undirectedLabelledGraph.addEdge("A", "B", 10.5f);
        Collection<String> neighbours = undirectedLabelledGraph.getNeighbours("A");
        assertTrue(neighbours.contains("B"));
        assertEquals(1, neighbours.size());
    }

    @Test
    public void testGetNeighboursNoNeighbours() {
        // Test per un nodo senza vicini
        undirectedLabelledGraph.addNode("C");
        Collection<String> neighbours = undirectedLabelledGraph.getNeighbours("C");
        assertTrue(neighbours.isEmpty());
    }

    @Test
    public void testGetNeighboursMultipleNeighbours() {
        // Test per un nodo con più vicini
        undirectedLabelledGraph.addNode("A");
        undirectedLabelledGraph.addNode("B");
        undirectedLabelledGraph.addNode("C");
        undirectedLabelledGraph.addEdge("A", "B", 10.5f);
        undirectedLabelledGraph.addEdge("A", "C", 20.0f);
        Collection<String> neighbours = undirectedLabelledGraph.getNeighbours("A");
        assertTrue(neighbours.contains("B"));
        assertTrue(neighbours.contains("C"));
        assertEquals(2, neighbours.size());
    }

    @Test
    public void testGetNeighboursAfterRemovingEdge() {
        // Test dopo aver rimosso un arco
        undirectedLabelledGraph.addNode("A");
        undirectedLabelledGraph.addNode("B");
        undirectedLabelledGraph.addEdge("A", "B", 10.5f);
        undirectedLabelledGraph.removeEdge("A", "B");
        Collection<String> neighbours = undirectedLabelledGraph.getNeighbours("A");
        assertFalse(neighbours.contains("B"));
        assertTrue(neighbours.isEmpty());
    }

    @Test
    public void testIsDirected() {
        assertTrue(directedLabelledGraph.isDirected());
        assertFalse(undirectedUnlabelledGraph.isDirected());
    }

    @Test
    public void testIsLabelled() {
        assertTrue(directedLabelledGraph.isLabelled());
        assertFalse(undirectedUnlabelledGraph.isLabelled());
    }

    @Test
    public void testNumNodesAndNumEdges() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        directedLabelledGraph.addEdge("A", "B", 5);
        assertEquals(2, directedLabelledGraph.numNodes());
        assertEquals(1, directedLabelledGraph.numEdges());
    }

    @Test
    public void testGetNodes() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        Collection<String> nodes = directedLabelledGraph.getNodes();
        assertTrue(nodes.contains("A"));
        assertTrue(nodes.contains("B"));
        assertEquals(2, nodes.size());
    }

    @Test
    public void testGetNodesUndirectedUnlabelled() {
        undirectedUnlabelledGraph.addNode("A");
        undirectedUnlabelledGraph.addNode("B");
        Collection<String> nodes = undirectedUnlabelledGraph.getNodes();
        assertTrue(nodes.contains("A"));
        assertTrue(nodes.contains("B"));
        assertEquals(2, nodes.size());
    }

    @Test
    public void testGetNodesUndirectedLabelled() {
        undirectedLabelledGraph.addNode("A");
        undirectedLabelledGraph.addNode("B");
        Collection<String> nodes = undirectedLabelledGraph.getNodes();
        assertTrue(nodes.contains("A"));
        assertTrue(nodes.contains("B"));
        assertEquals(2, nodes.size());
    }

    @Test
    public void testGetEdges() {
        directedLabelledGraph.addNode("A");
        directedLabelledGraph.addNode("B");
        directedLabelledGraph.addEdge("A", "B", 5);
        Collection<? extends AbstractEdge<String, Integer>> edges = directedLabelledGraph.getEdges();
        assertEquals(1, edges.size());
        AbstractEdge<String, Integer> edge = edges.iterator().next();
        assertEquals("A", edge.getStart());
        assertEquals("B", edge.getEnd());
        assertEquals(Integer.valueOf(5), edge.getLabel());
    }
}
