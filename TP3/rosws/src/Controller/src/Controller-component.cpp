#include "Controller-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

namespace Control {
  Controller::Controller(std::string const& name) : TaskContext(name){
    RTT::log(RTT::Info) << "Controller constructed !" <<RTT::endlog();
    this->ports()->addPort("mesure",mesure).doc("mesure en entrée du controleur");
    this->ports()->addPort("cmd",cmd).doc("commande en sortie du controleur");
    this->ports()->addEventPort("event",event);
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
    if(mesure<des){
      cmd.write(mesure+1);
    }
    RTT::log(RTT::Info) << "Command = %d !",cmd <<RTT::endlog();
  }

  void Controller::stopHook() {
    RTT::log(RTT::Info) << "Controller executes stopping !" <<RTT::endlog();
  }

  void Controller::cleanupHook() {
    RTT::log(RTT::Info) << "Controller cleaning up !" <<RTT::endlog();
  }

  Motor::Motor(std::string const& name) : TaskContext(name){
    RTT::log(RTT::Info) << "Motor constructed !" <<RTT::endlog();
    this->ports()->addPort("in",in).doc("entrée du système");
    this->ports()->addPort("out",out).doc("sortie du système");
    this->ports()->addEventPort("event",event);
  }

  bool Motor::configureHook(){
    RTT::log(RTT::Info) << "Motor configured !" <<RTT::endlog();
    return true;
  }

  bool Motor::startHook(){
    RTT::log(RTT::Info) << "Motor started !" <<RTT::endlog();
    return true;
  }

  void Motor::updateHook(){
    RTT::log(RTT::Info) << "Motor executes updateHook !" <<RTT::endlog();
    double* var;
    in.read(var);
    out.write(var);
  }

  void Motor::stopHook() {
    RTT::log(RTT::Info) << "Motor executes stopping !" <<RTT::endlog();
  }

  void Motor::cleanupHook() {
    RTT::log(RTT::Info) << "Motor cleaning up !" <<RTT::endlog();
  }
}

ORO_CREATE_COMPONENT_LIBRARY()
ORO_LIST_COMPONENT_TYPE(Control::Controller)
ORO_LIST_COMPONENT_TYPE(Control::Motor)
