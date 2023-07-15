#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-module.h"

using namespace ns3;

int main(int argc, char* argv[]) {
	CommandLine cmd;
	cmd.Parse(argc, argv);

	NodeContainer nodes;
	nodes.Create(6);

	InternetStackHelper internet;
	internet.Install(nodes);

	PointToPointHelper pointToPoint;
	pointToPoint.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
	pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

	NetDeviceContainer s1n1 = pointToPoint.Install(nodes.Get(0), nodes.Get(2));
	NetDeviceContainer s2n1 = pointToPoint.Install(nodes.Get(1), nodes.Get(2));
	NetDeviceContainer c1n2 = pointToPoint.Install(nodes.Get(3), nodes.Get(5));
	NetDeviceContainer c2n2 = pointToPoint.Install(nodes.Get(4), nodes.Get(5));
	NetDeviceContainer n1n2 = pointToPoint.Install(nodes.Get(2), nodes.Get(5));



	Simulator::Run();
	Simulator::Destroy();

//	Ipv4AddressHelper address;
//	address.SetBase("10.0.0.0", "255.255.255.0");

//	Ipv4InterfaceContainer interfaces = address.Assign(devices);


}
