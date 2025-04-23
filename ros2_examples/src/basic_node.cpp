#include "basic_node.hpp"

BasicNode::BasicNode()
: Node("basic_node"), number_(0)
{
  pub_ = this->create_publisher<std_msgs::msg::Int32>("number", 10);

  auto timer_callback = [this]() -> void {
      step();
    };

  timer_ = this->create_wall_timer(std::chrono::seconds(1), timer_callback);
}

void BasicNode::step()
{
  auto msg = std_msgs::msg::Int32();
  msg.data = number_;
  pub_->publish(msg);
  RCLCPP_INFO(this->get_logger(), "Number: %d ---", number_);

  number_++;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<BasicNode>();

  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}
