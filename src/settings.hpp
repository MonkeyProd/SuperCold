#pragma once
#include <map>
#include <string>

struct Settings {
  std::map<std::string, float> player_settings = {
      {"speed", 150},
      {"run_speed", 350},
  };
};