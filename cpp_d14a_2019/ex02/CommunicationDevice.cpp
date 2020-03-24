
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output) try : _api(input, output)
{}
catch (std::runtime_error &e){
    std::cerr << "Error: " << e.what() << std::endl;
}

CommunicationDevice::~CommunicationDevice()
{}

void CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    try{
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    } catch (std::logic_error &log){
        std::cerr << "LogicError: " << log.what() << std::endl;
    } catch (std::runtime_error &re){
        std::cerr << "RuntimeError: " << re.what() <<std::endl;
    } catch (std::exception &ex){
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

void CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try{
        _api.sendMessage(user, message);
    } catch (std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    } catch (std::runtime_error &e){
        std::cerr << e.what() << std::endl;
    }
}

void CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try{
        _api.receiveMessage(user, message);
    } catch (std::invalid_argument &e){
        std::cerr << "INVALID MESSAGE" << std::endl;
    } catch (std::runtime_error &e){
        std::cerr << "INVALID MESSAGE" << std::endl;
    }
}
