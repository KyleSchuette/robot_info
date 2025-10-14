#include "robot_info/robot_info.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

class AGVRobotInfo : public RobotInfo {
public:
  float maximum_payload;

  AGVRobotInfo() : maximum_payload(0.0f) {}

  void publish_data() override {
    robotinfo_msgs::RobotInfo10Fields msg;

    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "maximum_payload: " + std::to_string(maximum_payload) + " Kg";

    // Fill remaining fields empty
    msg.data_field_06 = "";
    msg.data_field_07 = "";
    msg.data_field_08 = "";
    msg.data_field_09 = "";
    msg.data_field_10 = "";

    info_pub_.publish(msg);

    ROS_INFO_STREAM("[AGVRobotInfo] Published: "
                    << msg.data_field_01 << " | "
                    << msg.data_field_02 << " | "
                    << msg.data_field_03 << " | "
                    << msg.data_field_04 << " | "
                    << msg.data_field_05);
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");

  AGVRobotInfo agv;
  agv.robot_description = "Cooper100";
  agv.serial_number = "567A359";
  agv.ip_address = "169.254.5.180";
  agv.firmware_version = "3.5.8";
  agv.maximum_payload = 100.0f;

  ros::Rate rate(1);
  while (ros::ok()) {
    agv.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
