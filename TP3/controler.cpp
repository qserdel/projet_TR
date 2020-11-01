#include <rtt/TaskContext.hpp>
#include <rtt/Component.hpp>
using namespace RTT;
class MyTask : public TaskContext
{
public:
  ATask(const std::string& name) : public TaskContext(name) {}
}; 
