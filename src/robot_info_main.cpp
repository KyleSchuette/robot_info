#include "robot_info/robot_info.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");

  RobotInfo base_robot;
  base_robot.robot_description = "RB1 General Model";
  base_robot.serial_number = "RB1-2025-001";
  base_robot.ip_address = "192.168.1.42";
  base_robot.firmware_version = "v2.3.7";

  ros::Rate rate(1);
  while (ros::ok()) {
    base_robot.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
