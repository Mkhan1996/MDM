#include <iostream>
#include <vector>
#include <string>

class Device {
public:
    std::string device_name;
    std::string model;
    std::string os_version;

    Device(const std::string& name, const std::string& model, const std::string& os_version)
        : device_name(name), model(model), os_version(os_version) {}
};

void menu() {
    std::cout << "MDM Demo Application" << std::endl;
    std::cout << "1. Register your Devices" << std::endl;
    std::cout << "2. List the Devices that you have registered" << std::endl;
    std::cout << "3. Show Device Details" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void register_device(std::vector<Device>& devices) {
    std::string name, model, os_version;

    std::cout << "Put your device name: ";
    std::cin >> name;
    std::cout << "Put your device model: ";
    std::cin >> model;
    std::cout << "OS version: ";
    std::cin >> os_version;

    devices.push_back(Device(name, model, os_version));
    std::cout << "successfully registered !" << std::endl;
}

void list_devices(const std::vector<Device>& devices) {
    if (devices.empty()) {
        std::cout << "No devices registered." << std::endl;
        return;
    }

    for (size_t i = 0; i < devices.size(); ++i) {
        std::cout << (i + 1) << ". " << devices[i].device_name << std::endl;
    }
}

void show_device_details(const std::vector<Device>& devices) {
    if (devices.empty()) {
        std::cout << "No devices registered." << std::endl;
        return;
    }

    size_t index;
    std::cout << "kindly enter device number: ";
    std::cin >> index;

    if (index > devices.size() || index < 1) {
        std::cout << "Invalid device number." << std::endl;
        return;
    }

    const Device& device = devices[index - 1];
    std::cout << "Device Name: " << device.device_name << std::endl;
    std::cout << "Device Model: " << device.model << std::endl;
    std::cout << "Device OS Version: " << device.os_version << std::endl;
}

int main() {
    std::vector<Device> devices;
    int choice;

    while (true) {
        menu();
        std::cout << "to register or show the detail press your choices : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                register_device(devices);
                break;
            case 2:
                list_devices(devices);
                break;
            case 3:
                show_device_details(devices);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. try again." << std::endl;
        }
    }
}
