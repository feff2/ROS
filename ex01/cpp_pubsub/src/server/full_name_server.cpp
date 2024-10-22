#include "rclcpp/rclcpp.hpp"
#include "full_name/srv/full_name_sum_service.hpp"
#include <memory>

void handle_full_name_request(
  const std::shared_ptr<full_name::srv::FullNameSumService::Request> request,
  std::shared_ptr<full_name::srv::FullNameSumService::Response> response)
{
  response->full_name = request->last_name + " " + request->name + " " + request->first_name;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Request: %s %s %s", 
              request->last_name.c_str(), request->name.c_str(), request->first_name.c_str());
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("full_name_server");

  auto service = node->create_service<full_name::srv::FullNameSumService>("full_name_service", handle_full_name_request);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service ready to concatenate full name.");

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
