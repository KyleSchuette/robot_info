#include "robot_info/robot_info.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");

  RobotInfo base_robot;
  base_robot.robot_description = "Cooper100";
  base_robot.serial_number = "567A359";
  base_robot.ip_address = "169.254.5.180";
  base_robot.firmware_version = "3.5.8";

  ros::Rate rate(1);
  while (ros::ok()) {
    base_robot.publish_data();
    ros::spinOnce();
    rate.sleep();
  }
  
  return 0;
}
