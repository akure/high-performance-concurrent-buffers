#ifndef file__concurrent_buffer_lock_mutex_deque__h__
#define file__concurrent_buffer_lock_mutex_deque__h__

/*
Contribution :
{
Auther : Akure
Date   : 02-Feb-2014
}

Description :
{
Class type: concurrent lock based buffer
Internal data structure: std::deque
Class name : concurrent_lockbased_deque

The buffer is based on the single batch buffer swap by consumer concept.
Que :  What is single buffer swap concept?
Ans : It is about swaping buffer's between the member buffer of concurrent buffer class 
       and  

Usability:
This buffer implementation can be used for SPSC, MPSC, SPMC as well as MPSC.
while the performance differ from case to case and how we use the buffer.
However the buffer is suitable for sufficiently high load system.

Best performance for SPSC and MPSC situations.

Pros and Crons:
Mutex lock to be taken by producer for every push operation, but at the same time less mutex 
taken by consumer

Possible enhancements:
mutex taken by producer for each push operation can be lower down. 

}

Licence:
{

}
Copy Rights:
{

}
*/
namespace concurrent {
namespace buffer {
namespace lock {  // the other will be nolock or free
namespace mutex {
// Below class come under the namespace concurrent::buffer::lockbased::mutex    
template < class T> 
// class concurrent_lockbased_deque
// class cblm_deque //prefix describe the name of the namespace, if we use prefix it means we are not utilizing the benifit of namespace 
class deque
{

public:
deque()
{
}

// producer specific operations

void push(T&);

// consumer specific operations

std::deque<T&> & get_buffer();
void get_buffer(std::deque<T&>  &buffer_);
void swap(std::deque<T&> &buffer_);

private:
// Internal operations

private:

// it has bo be a pointer, Why? We want to swap by reference
// it is a working buffer for producer
std::deque<T&> m_buffer; 
std::mutex m_buffer_mutex;
};
} // mutex
} // lockbased
} // buffer
} // concurrent

#endif 
