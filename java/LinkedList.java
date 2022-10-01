import java.io.Serializable;
import java.util.NoSuchElementException;

public class SinglyLinkedList<T> implements Serializable{

    private Node<T> head;

    private static class Node<E> {
        private final E data;
        private Node<E> next;

        public Node(E data){
            this.data = data;
            this.next = null;
        }
    }

    /**
     *Constructs an empty singly linked list.
     */
    public SinglyLinkedList() {}

    /**
     * Inserts the new node at the beginning of the linked list.
     * The new node is created as per the given value.
     *
     * @param val value of the node to be inserted
     * @throws NullPointerException if the specified value is null
     */
    public void insertFirst(T val) {
        if (val == null) throw new NullPointerException("value cannot be null");
        Node<T> newNode = new Node<>(val);
        newNode.next = head;
        head = newNode;
    }

    /**
     * Inserts the new node at the end of the linked list.
     * The new node is created as per the given value.
     *
     * @param val value of the node to be inserted
     * @throws NullPointerException if the specified value is null
     */
    public void insertLast(T val) {
        if (val == null) throw new NullPointerException("value cannot be null");
        Node<T> newNode = new Node<>(val);
        if (head == null) {
            head = newNode;
            return;
        }
        Node<T> current = head;
        while (current.next != null) current = current.next;
        current.next = newNode;
    }

    /**
     * Insert a new node at a specified index in this linked list.
     *
     * @param val value of the node to be inserted
     * @param position index for inserting new node (starts from 0)
     *
     * @throws NullPointerException if the specified value is null
     * @throws IndexOutOfBoundsException if the specified index is not valid
     */
    public void insert(T val, int position) {
        if (val == null) throw new NullPointerException("value cannot be null");
        if (position > size() || position < 0) throw new IndexOutOfBoundsException("Size = " + size() + ", Index = " + position);
        Node<T> newNode = new Node<>(val);
        if (position == 0) insertFirst(val);
        else {
            Node<T> prev = head;
            int count = 0;
            while (count < position-1) {
                prev = prev.next;
                count++;
            }
            Node<T> current = prev.next;
            prev.next = newNode;
            newNode.next = current;
        }
    }

    /**
     * Insert a new node at the end of the list.
     *
     * @param val value of the node to be inserted
     * @throws NullPointerException if the specified value is null
     */
    public void insert(T val) {
        insertLast(val);
    }

    /**
     * Removes and returns the head(first element) of this list.
     *
     * @return head of this list
     * @throws NoSuchElementException if the list is empty
     */
    public T deleteFirst() {
        if (head == null) throw new NoSuchElementException("list is empty");
        Node<T> tmp = head;
        head = tmp.next;
        tmp.next = null;
        return tmp.data;
    }

    /**
     * Removes and returns the last element of this list.
     *
     * @return last element of this list
     * @throws NoSuchElementException if the list is empty
     */
    public T deleteLast() {
        if (head == null) throw new NoSuchElementException("list is empty");
        if (head.next == null) return deleteFirst();
        Node<T> current = head;
        Node<T> prev = null;
        while (current.next != null) {
            prev = current;
            current = current.next;
        }
        prev.next = null;
        return current.data;
    }

    /**
     * Removes and return the first element(head) of this list.
     *
     * @return head of this list
     * @throws NoSuchElementException if the list is empty
     */
    public T delete() {
        return deleteFirst();
    }

    /**
     * Removes and return element at specified index.
     *
     * @param index index of the element to be removed
     * @return element at specified index in this list
     *
     * @throws IndexOutOfBoundsException if specified index is not valid
     * @throws NoSuchElementException if the list is empty
     */
    public T delete(int index) {
        if (index < 0 || index > size()-1) throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size());
        if (index == 0) return deleteFirst();
        else if (index == size()-1) return deleteLast();
        else {
            Node<T> prev = head;
            int count = 0;
            while (count < index-1) {
                prev = prev.next;
                count++;
            }
            Node<T> current = prev.next;
            prev.next = current.next;
            return current.data;
        }
    }

    /**
     * Removes the first occurrence of specified object from this list, if present.
     * If the element is not present this list remains unchanged.
     *
     * @param o element required to be removed from this list
     * @return true if the element is present in this list
     * @throws NullPointerException if the specified object is null
     */
    public boolean delete(Object o) {
        if (o == null) throw new NullPointerException("object cannot be null");
        if (o.equals(head.data)) {
            deleteFirst();
            return true;
        }
        else {
            Node<T> prev = head;
            while (prev.next != null) {
                if (o.equals(prev.next.data)) {
                    Node<T> current = prev.next;
                    prev.next = current.next;
                    return true;
                }
                prev = prev.next;
            }
        }
        return false;
    }

    /**
     * Removes the first occurrence of specified object from this list, if present.
     * If the element is not present this list remains unchanged.
     *
     * @param o element required to be removed from this list
     * @return true if the element is present in this list
     * @throws NullPointerException if the specified object is null
     */
    public boolean deleteFirstOccurrence(Object o) {
        return delete(o);
    }

    /**
     * Returns the element at the specified position in this list.
     *
     * @param index index of the element to return
     * @return element at the specified index
     * @throws IndexOutOfBoundsException if the index is out of range
     */
    public T get(int index) {
        if (index < 0 || index > size()-1) throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size());
        Node<T> current = head;
        int count = 0;
        while (count < index) {
            count++;
            current = current.next;
        }
        return current.data;
    }

    /**
     * Returns the first element(head) of this list.
     *
     * @return head(first element) of this list
     * @throws NoSuchElementException if the list is empty
     */
    public T getFirst() {
        if (head == null) throw new NoSuchElementException("list is empty");
        return head.data;
    }

    /**
     * Returns the last element of this list.
     *
     * @return last element of this list
     * @throws NoSuchElementException if the list is empty
     */
    public T getLast() {
        if (head == null) throw new NoSuchElementException("list is empty");
        Node<T> current = head;
        while (current.next != null) {
            current = current.next;
        }
        return current.data;
    }

    /**
     * Returns the size of the linked list.
     *
     * @return number of elements in this linked list
     */
    public int size() {
        if (head == null) return 0;
        int count = 0;
        Node<T> current = head;
        while(current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    /**
     * Reverse this list.
     * The first element will be the last element and similarly the last element will become the head(first element) of this list.
     */
    public void reverse() {
        if (head == null) return;
        Node<T> current = head;
        Node<T> prev = null;
        Node<T> next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    /**
     * Return the string representation of this linked list.
     * The string representation consists of a list of the elements enclosed in square brackets ("[]").
     *
     * @return string representation of the linked list
     */
    @Override
    public String toString() {
        Node<T> current = head;
        StringBuilder str = new StringBuilder("[");
        while (current != null) {
            str.append(current.data).append(",");
            current = current.next;
        }
        if (head != null) str.deleteCharAt(str.length()-1);
        str.append("]");
        return str.toString();
    }

    /**
     * Returns the string representing the singly linked list visual with help of arrows. This gives simplified representation.
     *
     * @return simplified string representation of this list
     */
    public String toVisualRepresentation() {
        Node<T> current = head;
        StringBuilder str = new StringBuilder("[");
        while (current != null) {
            str.append(current.data).append(" --> ");
            current = current.next;
        }
        if(head != null) str.append("NULL");
        str.append("]");
        return str.toString();
    }
}