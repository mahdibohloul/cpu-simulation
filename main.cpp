#include "src/framework/CommandHandler.hpp"

int main() {
  auto command_handler = CommandHandler::get_instance();
  command_handler->handle();
  return 0;
}
