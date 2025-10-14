#include "robot_info/robot_info.h"

RobotInfo::RobotInfo() {
  info_pub_ = nh_.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
}

RobotInfo::~RobotInfo() {}

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;

  // Extra fields
  msg.data_field_05 = "";
  msg.data_field_06 = "";
  msg.data_field_07 = "";
  msg.data_field_08 = "";
  msg.data_field_09 = "";
  msg.data_field_10 = "";

  info_pub_.publish(msg);

  ROS_INFO_STREAM("[RobotInfo] Published: "
                  << msg.data_field_01 << " | "
                  << msg.data_field_02 << " | "
                  << msg.data_field_03 << " | "
                  << msg.data_field_04);
}
