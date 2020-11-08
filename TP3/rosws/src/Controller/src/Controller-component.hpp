#ifndef OROCOS_CONTROLLER_COMPONENT_HPP
#define OROCOS_CONTROLLER_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>


namespace Control {
  class Controller : public RTT::TaskContext{
    public:
      Controller(std::string const& name);
      bool configureHook();
      bool startHook();
      void updateHook();
      void stopHook();
      void cleanupHook();
      RTT::InputPort<double> mesure;
      RTT::OutputPort<double> cmd;
      RTT::InputPort<double> event;
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
      RTT::InputPort<double> in;
      RTT::OutputPort<double> out;
      RTT::InputPort<double> event;
      double buf;
  };
}

#endif
