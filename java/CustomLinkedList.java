//import javax.swing.plaf.nimbus.NimbusLookAndFeel;

public class CustomLinkedList {
    static class Node{
        Node next; int data;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    static Node head;

    static void addFirst(int data)
    {
        Node temp = new Node(data);
        if (head == null){
          head = temp;
          temp = head;
        }
        temp.next = head;
        head = temp;
    }

    static void addMiddle(int data, Node prev)
    {
        Node temp = new Node(data);
        if (head == null)
        {
            return;
        }

        temp.next = prev.next.next;
        prev.next = temp;
    }

    static void addLast(int data){
        Node temp = head;
        Node newNode = new Node(data);
        while (temp.next != null)
        {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    static int sizeOfList(Node head){
        Node temp = head;
        int size = 0;
        while (temp != null){
            temp = temp.next;
            size++;
        }
        return size;
    }

    static void delFirst(){
        Node temp = head;
        temp.next = head;
        head = temp.next;
    }

    static void delLast(Node prev){
        if (head == null){
            return;
        }
        Node tmp = head;
        while (tmp.next.next != null){
            tmp = tmp.next;
        }
        tmp.next = null;
    }


    static void printList(Node head){
        Node temp = head;
        while (temp != null){
            System.out.println(temp.data + "->");
            temp = temp.next;
        }
    }
}
