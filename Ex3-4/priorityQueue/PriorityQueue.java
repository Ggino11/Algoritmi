package priorityQueue;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.NoSuchElementException;


public class PriorityQueue<E> implements AbstractQueue<E> {
    private ArrayList<E> heap;           // ArrayList to implement the heap
    private HashMap<E, Integer> indexMap; // HashMap to keep track of indices for quick access

    private Comparator<E> comparator;

    public PriorityQueue(Comparator<E> comparator) {
        this.comparator = comparator;
        this.heap = new ArrayList<>();
        this.indexMap = new HashMap<>();
    }

    @Override
    public boolean empty() {
        return heap.isEmpty();
    }

    @Override
    public boolean push(E e) {
        if (indexMap.containsKey(e)) return false;// element already present in queue
        heap.add(e);
        int index = heap.size() - 1;
        indexMap.put(e, index);
        siftUp(index);
        return true;
    
    }

    @Override
    public boolean contains(E e) {
        if (e == null) {
            System.out.println("The element is null.");
            return false;
        }
        return indexMap.containsKey(e);
    }

    @Override
    public E top() {
        // Check if the priority queue is empty
        if (empty()) {
            // Print a message indicating the queue is empty
            System.out.println("The priority queue is empty.");
            return null;
    }

    // Return the element at the root of the heap
    return heap.get(0);
}

    @Override
    public void pop() {
        if (empty()) {
            throw new NoSuchElementException("The priority queue is empty.");
        }

        // Get the root element (element with the highest priority)
        E removedElement = top();

        int lastIndex = heap.size() - 1;

        if (lastIndex == 0) { // Special case when there is only one element
            heap.remove(lastIndex); // Remove the single remaining element
            indexMap.remove(removedElement);
            return; // No need to sift down as the heap is now empty
        }

        // Replace the root with the last element in the heap
        E lastElement = heap.get(lastIndex);
        heap.set(0, lastElement);
        indexMap.put(lastElement, 0); // Update the index of the new root

        // Remove the last element from the heap and update the index map
        heap.remove(lastIndex);
        indexMap.remove(removedElement);

        // Restore heap property by sifting down the new root element
        siftDown(0);
    }


    @Override
    public boolean remove(E e) {
        if (e == null) {
            throw new IllegalArgumentException("The element is null.");
        }
        Integer index = indexMap.get(e);
        if (index == null) {
            throw new NoSuchElementException("The element is not in the queue.");
        }
         // Move the last element to the position of the element to remove
         int lastIndex = heap.size() - 1;
         if (index < lastIndex) {
             E lastElement = heap.get(lastIndex);
             heap.set(index, lastElement);
             indexMap.put(lastElement, index);
             siftDown(index);
             siftUp(index);
         }
         heap.remove(lastIndex);
         indexMap.remove(e);
         return true;
        
    }

    private void siftUp(int index) {
        E element = heap.get(index); // Get the element at the index
        while (index > 0) { // Continue while not at the root
            int parentIndex = (index - 1) / 2; // Calculate the parent index
            E parent = heap.get(parentIndex); // Get the parent element
            if (comparator.compare(element, parent) >= 0) {
                break; // If the element is greater or equal to its parent, stop
            }
            heap.set(index, parent); // Move the parent down
            indexMap.put(parent, index); // Update the indexMap
            index = parentIndex; // Move up to the parent's index
        }
        heap.set(index, element); // Place the element in its correct position
        indexMap.put(element, index); // Update the indexMap
    }     

    private void siftDown(int index) {
        E element = heap.get(index); // Get the element at the index
        int size = heap.size(); // Get the size of the heap
        while (true) {
            int leftChildIndex = 2 * index + 1; // Calculate the left child index
            int rightChildIndex = 2 * index + 2; // Calculate the right child index
            // Determine the smallest of the current element and its children
            int smallestIndex = index;
            if (leftChildIndex < size && comparator.compare(heap.get(leftChildIndex), heap.get(smallestIndex)) < 0) {
                smallestIndex = leftChildIndex;
            }
            if (rightChildIndex < size && comparator.compare(heap.get(rightChildIndex), heap.get(smallestIndex)) < 0) {
                smallestIndex = rightChildIndex;
            }
            // If the smallest element is the current element, stop
            if (smallestIndex == index) {
                break;
            }  
            // Swap the element with the smallest child and update the indexMap
            E smallestElement = heap.get(smallestIndex);
            heap.set(index, smallestElement);
            indexMap.put(smallestElement, index);
            // Move down to the smallest child index
            index = smallestIndex;
        }
        // Place the element in its correct position and update the indexMap
        heap.set(index, element);
        indexMap.put(element, index);
    }
    
    
}
