/* Command line parsing
   Copyright 2017 The NeoPG developers

   NeoPG is released under the Simplified BSD License (see license.txt)
*/

#pragma once

#include <CLI11.hpp>

namespace NeoPG {
namespace CLI {

using ::CLI::App;

class Command {
 public:
  App& m_app;
  App& m_cmd;

  virtual void run() = 0;

  Command(App& app, const std::string& flag, const std::string& description,
          const std::string& group_name = "");
  virtual ~Command() {}
};

class LegacyCommand : public Command {
 public:
  using main_fnc_t = std::function<int(int argc, char** argv)>;

 private:
  const main_fnc_t m_main_fnc;

 public:
  void run() override;
  LegacyCommand(App& app, const main_fnc_t& main_fnc, const std::string& flag,
                const std::string& description,
                const std::string& group_name = "");
  virtual ~LegacyCommand() {}
};

}  // Namespace CLI
}  // Namespace NeoPG
