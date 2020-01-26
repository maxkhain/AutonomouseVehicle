#include "ControlQueue.h"

Queue<Message, 16> ControlQueue::control_queue;
int ControlQueue::queue_counter=0;
bool ControlQueue::flag_is_empty=true;

void ControlQueue::EnQueue(Message* new_message)
{
    control_queue.put(new_message);
    if(flag_is_empty)
        flag_is_empty=!flag_is_empty;
    queue_counter++;
    Logger::Log(" Queue length is  ",queue_counter);
}

Message* ControlQueue::DeQueue()
{
    osEvent evt = control_queue.get();
    if (evt.status == osEventMessage) {
        queue_counter--;
        if(queue_counter==0)
            flag_is_empty=true;
        Logger::Log(" Queue length is  ",queue_counter);
        return (Message*)evt.value.p;

    }
    return NULL;
}

