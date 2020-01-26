#include "MessageQueue.h"

Queue<Message, 16> MessageQueue::message_queue;
int MessageQueue::queue_counter=0;
bool MessageQueue::flag_is_empty=true;

void MessageQueue::EnQueue(Message* new_message)
{
    message_queue.put(new_message);
    if(flag_is_empty)
        flag_is_empty=!flag_is_empty;
    queue_counter++;
    Logger::Log("Queue length is  ",queue_counter);
}
Message* MessageQueue::DeQueue()
{
    osEvent evt = message_queue.get();
    if (evt.status == osEventMessage) {
        queue_counter--;
        if(queue_counter==0)
            flag_is_empty=true;
        Logger::Log("Queue length is  ",queue_counter);
        return (Message*)evt.value.p;

    }
    return NULL;
}

