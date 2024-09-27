package priorityQueue;

import java.util.Comparator;
import java.util.NoSuchElementException;

public class Main_ex3 {
    public static void main(String[] args) {
        // Comparator for Integer to create a min-heap
        Comparator<Integer> comparator = Integer::compareTo;

        // Create a PriorityQueue with the comparator
        PriorityQueue<Integer> pq = new PriorityQueue<>(comparator);

        // Test push and top methods
        System.out.println("Pushing elements 10, 20, and 15.");
        pq.push(10);
        pq.push(20);
        pq.push(15);

        // Check the top element
        System.out.println("Top element: " + pq.top()); // Should be 10

        // Test contains method
        System.out.println("Contains 20: " + pq.contains(20)); // Should be true
        System.out.println("Contains 25: " + pq.contains(25)); // Should be false

        // Test pop method
        System.out.println("Popping the top element.");
        pq.pop();
        System.out.println("Top element after pop: " + pq.top()); // Should be 15

        // Test remove method
        System.out.println("Removing element 15.");
        pq.remove(15);
        System.out.println("Contains 15: " + pq.contains(15)); // Should be false
        try {
            System.out.println("Top element after removing 15: " + pq.top()); // Should be 20
        } catch (NoSuchElementException e) {
            System.out.println(e.getMessage());
        }

        // Test edge case for empty queue
        System.out.println("Popping the last element.");
        pq.pop();
        try {
            System.out.println("Top element after popping all: " + pq.top()); // Should throw exception
        } catch (NoSuchElementException e) {
            System.out.println(e.getMessage()); // Expected exception
        }
    }
}
