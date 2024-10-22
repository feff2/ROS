#include "rclcpp/rclcpp.hpp"
#include "full_name/srv/full_name_sum_service.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 4) {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Usage: full_name_client last_name name first_name");
    return 1;
  }

  auto node = rclcpp::Node::make_shared("full_name_client");
  auto client = node->create_client<full_name::srv::FullNameSumService>("full_name_service");

  auto request = std::make_shared<full_name::srv::FullNameSumService::Request>();
  request->last_name = argv[1];
  request->name = argv[2];
  request->first_name = argv[3];

  while (!client->wait_for_service(1s)) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for service...");
  }

  auto result = client->async_send_request(request);
  if (rclcpp::spin_until_future_complete(node, result) ==
      rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Full name: %s", result.get()->full_name.c_str());
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
  }

  rclcpp::shutdown();
  return 0;
}
