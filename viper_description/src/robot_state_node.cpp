
#include "industrial_robot_client/robot_state_interface.h"
#include "industrial_utils/param_utils.h"

using industrial_robot_client::robot_state_interface::RobotStateInterface;
using industrial_robot_client::joint_relay_handler::JointRelayHandler;

class ADEPT_JointRelayHandler : public JointRelayHandler
{

public:
  ADEPT_JointRelayHandler() : JointRelayHandler()
  {
  }
};

int main(int argc, char** argv)
{
  // initialize node
  ros::init(argc, argv, "state_interface");

  // launch the default Robot State Interface connection/handlers
  RobotStateInterface rsi;
  rsi.init();

  // replace the JointRelayHandler with Adept-version
  ADEPT_JointRelayHandler jointHandler;  // for joint-linkage correction
  std::vector<std::string> joint_names = rsi.get_joint_names();
  jointHandler.init(rsi.get_connection(), joint_names);
  rsi.add_handler(&jointHandler);

  // run the node
  rsi.run();

  return 0;
}
