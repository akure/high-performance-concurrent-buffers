#include "concurrent_buffer_lock_mutex_deque.hpp"

// If we use any construct which has a same name is std as ours, We use std:: for std names
// ours will be directly used inside or use #define

#define cblm concurrent::buffer:lock::mutex

using namespace concurrent::buffer::lock:mutex 

// constructor 

cblm::deque()
{

}

void cblm::deque<T>::push(T&)
{

}

std::deque<T&> T & cblm::deque<T>::get_buffer()
{

}

void cblm::deque<T>::get_buffer(std::deque<T&>  &buffer_)
{

}

void cblm::deque<T>::swap(std::deque<T&> &buffer_)
{

}

