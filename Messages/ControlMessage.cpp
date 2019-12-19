#include "ControlMessage.h"
#define ANGLE_LIMIT 1.5

//angle calculations in radian



ControlMessage::ControlMessage()
{
    m_messageType = MESSAGECONTROL;
    control_message_count++;
    ControlMessage::current_message_count=control_message_count;
};

bool ControlMessage::Process()
{
    Logger::Log("Control message process number: ", ControlMessage::current_message_count);
    double distance = Calculations::CalculateDistance();
    double new_angle = Calculations::CalculateAngleToDestination();
    double current_angle=AutonomousEnvironment::currentStatus.GetCurrentAngle();
    double angle_to_servo = new_angle-current_angle;//calculating the diffrance from current angle to requered angle
    AutonomousEnvironment::currentStatus.SetCurrentAngle(new_angle);//updating current angle of the vehicle
    Logger::Log("current angle is ",new_angle);
    double current_speed = Calculations::CalculateSpeed(distance);
    AutonomousEnvironment::currentStatus.SetCurrentSpeed(current_speed);
    Logger::Log("current speed is ",current_speed);
    /* this block will decide if the angle is too big for current speed so the vehicle doesnt flip
    if(angle_to_servo < ANGLE_LIMIT){//limit small turn to a certain angle
    //PWM_to_speed_servo = SpeedToPWM(current_speed);  //Update PWM outpute to the speed control servo
    //PWM_to_angle_servo = DiffranceInAngleToPWM(angle_to_servo); //Update PWM outpute to the angle control servo
    }
    else
    {
        //in case the angle is too big for the current speed need to slow down or limit the angle
    }
    */
    return true;
}

