#include "states.h"

static const StateInfo state_infos[3] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {OFF::setup, OFF::enter, OFF::exit, OFF::loop, OFF::event},
  {MOTIONMACHINE::setup, MOTIONMACHINE::enter, MOTIONMACHINE::exit, MOTIONMACHINE::loop, MOTIONMACHINE::event}
};

static const WireValue wire_values[0] = {
  
};

MasterManager<State, 3, 0> manager(0xa4663eee, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace OFF {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace MOTIONMACHINE {


void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::upRamp();
    break;
  case 1:
    events::upStairs();
    break;
  case 2:
    events::moveServo();
    break;
  default:
    break;
  }
}


}

