package graph;

public class Edge<V,L> implements AbstractEdge<V,L> {
    private final V startNode;
    private final V endNode;
    private final L label;

    public Edge(V startNode, V endNode, L label) {
        this.startNode = startNode;
        this.endNode = endNode;
        this.label = label;

    }

    @Override
    public V getStart() {
        return startNode;
    }

    @Override
    public V getEnd() {
        return endNode;
    }

    @Override
    public L getLabel() {
        return label;
    }
}
