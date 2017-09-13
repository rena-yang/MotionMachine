
var IDLE = {
  id: 0,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_IDLE = 0;
var OFF = {
  id: 1,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_OFF = 1;
var MOTIONMACHINE = {
  id: 2,
  master: {
    values: {
      
    },
    events: {
      upRamp: function upRamp() { manager.sendEvent(0, 2); },
      upStairs: function upStairs() { manager.sendEvent(1, 2); },
      moveServo: function moveServo() { manager.sendEvent(2, 2); }
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_MOTIONMACHINE = 2;

var STATES = {
  IDLE: IDLE,
  OFF: OFF,
  MOTIONMACHINE: MOTIONMACHINE
};
var manager = new Manager([IDLE, OFF, MOTIONMACHINE]);
