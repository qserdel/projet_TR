#include "Controller-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Controller::Controller(std::string const& name) : TaskContext(name){
  RTT::log(RTT::Info) << "Controller constructed !" <<RTT::endlog();
  this->ports()->addPort("mesure",mesure);
  this->ports()->addPort("cmd",cmd);
  this->addAttribute("des",des);
}

bool Controller::configureHook(){
  RTT::log(RTT::Info) << "Controller configured !" <<RTT::endlog();
  return true;
}

bool Controller::startHook(){
  RTT::log(RTT::Info) << "Controller started !" <<RTT::endlog();
  return true;
}

void Controller::updateHook(){
  RTT::log(RTT::Info) << "Controller executes updateHook !" <<RTT::endlog();
}

void Controller::stopHook() {
  RTT::log(RTT::Info) << "Controller executes stopping !" <<RTT::endlog();
}

void Controller::cleanupHook() {
  RTT::log(RTT::Info) << "Controller cleaning up !" <<RTT::endlog();
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Controller)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT_LIBRARY()
ORO_LIST_COMPONENT_TYPE(Controller)
