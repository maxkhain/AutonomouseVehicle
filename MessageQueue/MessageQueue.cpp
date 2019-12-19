#include "MessageQueue.h"

Queue<Message, 16> MessageQueue::message_queue;
int MessageQueue::queue_counter=0;

void MessageQueue::EnQueue(Message* new_message)
{
    message_queue.put(new_message);
    queue_counter++;
    //Logger::Log(" Queue length is  ",queue_counter);
}
Message* MessageQueue::DeQueue()
{
    osEvent evt = message_queue.get();    
    if (evt.status == osEventMessage) {
        queue_counter--;
        Logger::Log(" Queue length is  ",queue_counter);
        return (Message*)evt.value.p;
        
    }
    return NULL;
}

