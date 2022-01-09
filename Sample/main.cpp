#include <NetService.hpp>

#include <Errors.hpp>

#include <iostream>

static constexpr Bousk::uint16 HostPort = 8888;

int main(int argc, char* argv[])
{
    Bousk::Network::NetService::NetworkType networkType = Bousk::Network::NetService::NetworkType::None;
    for (int i = 0; i < argc; ++i)
    {
        const std::string arg(argv[i]);
        if (arg == "-solo")
        {
            networkType = Bousk::Network::NetService::NetworkType::None;
            break;
        }
        else if (arg == "-client")
        {
            networkType = Bousk::Network::NetService::NetworkType::Client;
            break;
        }
        else if (arg == "-host")
        {
            networkType = Bousk::Network::NetService::NetworkType::Host;
            break;
        }
        else if (arg == "-server")
        {
            networkType = Bousk::Network::NetService::NetworkType::DedicatedServer;
            break;
        }
    }

    // Use a heap allocation to prevent stack size warning since NetService is quite big
    std::unique_ptr<Bousk::Network::NetService> netService = std::make_unique<Bousk::Network::NetService>();
    {
        Bousk::Network::NetService::Parameters netServiceParameters;
        netServiceParameters.networkType = networkType;
        netServiceParameters.localPort = netServiceParameters.isHost() ? HostPort : 0;
        netServiceParameters.hostAddress = Bousk::Network::Address::Loopback(Bousk::Network::Address::Type::IPv4, HostPort);
        if (!netService->init(netServiceParameters))
        {
            std::cout << "NetService initialization error : " << Bousk::Network::Errors::Get();
            return -1;
        }
    }
}