#ifndef OROCOS_CONTROLLER_COMPONENT_HPP
#define OROCOS_CONTROLLER_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>

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
    double des;
};
#endif
