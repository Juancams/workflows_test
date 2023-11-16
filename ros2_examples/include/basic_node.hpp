#ifndef BASIC_NODE_HPP_
#define BASIC_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class BasicNode : public rclcpp::Node {
public:
  BasicNode();
  void step();

private:
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  int number_;
};

#endif // BASIC_NODE_HPP_
