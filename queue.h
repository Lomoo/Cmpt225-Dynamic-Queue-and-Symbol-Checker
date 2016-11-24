/* File: queue.h       

  Header file for a very basic linked-list based dynamic Queue class.
  (Version for Assignment 2)

*/

class Queue
{
  public:

    Queue(); // Constructs a new empty queue.
    Queue( const Queue& q );// Copy constructor.
    ~Queue();// Destructor.
    void enqueue( int item ); // Enqueues <item>.
    int dequeue();  // Dequeues the front item.
    int front();  // Returns the front item without dequeuing it.
    bool empty();  // Returns true iff the queue contains no items.
    int size();  // Returns the current number of items in the queue.
    int delay(int item); // 
      // (Revised to match the description in the instructions.)
      // Moves all occurrences of <item> (if there are any) to the 
      // rear end of the queue;  The relative order of all other items 
      // is unchanged.  The return value is the number of occurrences 
      // of item in the queue. 
      // If there are no occurrences of <item>, the queue is unchanged.

  private:
    class node  // node type for the linked list 
    {
       public:
           node(int new_data, node * next_node ){
              data = new_data ;
              next = next_node ;
           }
           int data ;
           node * next ;
    };

    node * front_p ; // pointer to the (node containing the) next item 
              //  which to be dequeud, or NULL if the queue is empty.

    node * rear_p ; // pointer to the (node containing the) last item 
              // which was enqueued, or NULL if the queue is empty.

    int current_size ; // current number of elements in the queue.
};