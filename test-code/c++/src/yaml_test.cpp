// -*- mode: C++; coding: utf-8-unix; -*-

/**
 * @file  yaml_test.cpp
 * @brief
 */

#include <iostream>
#include <fstream>
#include <string>
#include "yaml-cpp/yaml.h"

int main(int argc, char **argv)
{
    std::ifstream ifs(argv[1]);
    if (ifs.is_open()) {
        try {
            YAML::Node spring = YAML::LoadFile(argv[1]);
            std::cerr << spring << std::endl;
            double kp = spring["trampoline"]["kp"].as<double>();
            double kd = spring["trampoline"]["kd"].as<double>();
            std::cerr << "kp is set to " << kp << " and kd is set to " << kd << std::endl;
        } catch (YAML::Exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
