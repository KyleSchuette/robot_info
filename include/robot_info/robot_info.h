#pragma once
#include <ros/ros.h>
#include <string>
#include "robotinfo_msgs/RobotInfo10Fields.h"

class RobotInfo {
protected:
  ros::NodeHandle nh_;
  ros::Publisher info_pub_;

public:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

  RobotInfo();
  virtual ~RobotInfo();
  virtual void publish_data();
};
