#include "robot_info/robot_info.h"

class AGVRobotInfo : public RobotInfo {
public:
  float maximum_payload;

  AGVRobotInfo() : maximum_payload(0.0f) {}

  void publish_data() override {
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = robot_description + " (AGV)";
    msg.data_field_02 = serial_number;
    msg.data_field_03 = ip_address;
    msg.data_field_04 = firmware_version;
    msg.data_field_05 = std::to_string(maximum_payload) + " kg";

    info_pub_.publish(msg);

    ROS_INFO_STREAM("[AGVRobotInfo] Published AGV info:"
                    << " Description=" << robot_description
                    << " | Serial=" << serial_number
                    << " | IP=" << ip_address
                    << " | Firmware=" << firmware_version
                    << " | Payload=" << maximum_payload << " kg");
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");

  AGVRobotInfo agv;
  agv.robot_description = "RB1 AGV";
  agv.serial_number = "RB1-AGV-007";
  agv.ip_address = "192.168.0.42";
  agv.firmware_version = "v3.0.0";
  agv.maximum_payload = 120.0f;

  ros::Rate rate(1);
  while (ros::ok()) {
    agv.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
