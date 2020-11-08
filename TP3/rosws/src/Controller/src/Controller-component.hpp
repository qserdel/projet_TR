#ifndef OROCOS_CONTROLLER_COMPONENT_HPP
#define OROCOS_CONTROLLER_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>
#include <std_msgs/Float64.h>
#include <rtt/Component.hpp>
#include <iostream>


namespace Control {
  class Controller : public RTT::TaskContext{
    public:
      Controller(std::string const& name);
      bool configureHook();
      bool startHook();
      void updateHook();
      void stopHook();
      void cleanupHook();
      RTT::InputPort<std_msgs::Float64> mesure;
      RTT::OutputPort<std_msgs::Float64> cmd;
      RTT::InputPort<std_msgs::Float64> event;
      std_msgs::Float64 mesure_msg;
      double des;
      double buf;
      // paramêtres du PID
      double e;
      double se;
      double de;
      double e_prec = 0;
      double Kp;
      double Ki;
      double Ke;
      double dt;
    };

  class Motor : public RTT::TaskContext{
    public:
      Motor(std::string const& name);
      bool configureHook();
      bool startHook();
      void updateHook();
      void stopHook();
      void cleanupHook();
      RTT::InputPort<std_msgs::Float64> in;
      RTT::OutputPort<std_msgs::Float64> out;
      RTT::InputPort<std_msgs::Float64> event;
      std_msgs::Float64 in_msg;
      double buf;
  };
}

#endif
