package test;

import org.junit.Before;
import org.junit.Test;
import priorityQueue.PriorityQueue;

import java.util.Comparator;
import java.util.NoSuchElementException;
import static org.junit.Assert.*;

public class PriorityQueueTests {

    private PriorityQueue<Integer> pq;
    private Comparator<Integer> comparator;

    @Before
    public void setUp() {
        comparator = Integer::compare;
        pq = new PriorityQueue<>(comparator);
    }

    @Test
    public void testPushAndTop() {
        pq.push(10);
        pq.push(5);
        pq.push(20);

        assertEquals((Integer) 5, pq.top());
    }

    @Test
    public void testPop() {
        pq.push(10);
        pq.push(5);
        pq.push(20);

        pq.pop();
        assertEquals((Integer) 10, pq.top());
    }

    @Test
    public void testRemove() {
        pq.push(10);
        pq.push(5);
        pq.push(20);

        pq.remove(10);
        assertEquals((Integer) 5, pq.top());
    }

    @Test
    public void testContains() {
        pq.push(10);
        pq.push(5);

        assertTrue(pq.contains(10));
        assertFalse(pq.contains(20));
    }

    @Test
    public void testEmpty() {
        assertTrue(pq.empty());

        pq.push(10);
        assertFalse(pq.empty());

        pq.pop();
        assertTrue(pq.empty());
    }

    @Test
    public void testTopOnEmpty() {
        assertNull(pq.top());
    }

    @Test
    public void testPopOnEmpty() {
        try {
            pq.pop();
            fail("Expected NoSuchElementException");
        } catch (NoSuchElementException e) {
            assertEquals("The priority queue is empty.", e.getMessage());
        }
    }

    @Test
    public void testRemoveNonExistentElement() {
        try {
            pq.remove(10);
            fail("Expected NoSuchElementException");
        } catch (NoSuchElementException e) {
            assertEquals("The element is not in the queue.", e.getMessage());
        }
    }
}
