// Rules for Conway's Game of Life
#ifndef _RULES_CONWAY_H_
#define _RULES_CONWAY_H_

#include "rules/rules_interface.h"

namespace conway {

  class ConwaysGOLRules : public RulesInterface {
  public:
    ConwaysGOLRules() = delete;
    explicit ConwaysGOLRules(uint16_t rows, uint16_t cols);

    virtual void apply_rules() override;
  };
}

#endif
