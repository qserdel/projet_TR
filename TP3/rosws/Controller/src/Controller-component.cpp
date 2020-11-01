#include "Controller-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Controller::Controller(std::string const& name) : TaskContext(name){
  std::cout << "Controller constructed !" <<std::endl;
}

bool Controller::configureHook(){
  std::cout << "Controller configured !" <<std::endl;
  return true;
}

bool Controller::startHook(){
  std::cout << "Controller started !" <<std::endl;
  return true;
}

void Controller::updateHook(){
  std::cout << "Controller executes updateHook !" <<std::endl;
}

void Controller::stopHook() {
  std::cout << "Controller executes stopping !" <<std::endl;
}

void Controller::cleanupHook() {
  std::cout << "Controller cleaning up !" <<std::endl;
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
ORO_CREATE_COMPONENT(Controller)
