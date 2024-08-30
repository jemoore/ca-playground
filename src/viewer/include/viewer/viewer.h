#ifndef _VIEWER_H_
#define _VIEWER_H_

#include <rules/rules_interface.h>

namespace viewer {

class Viewer {
public:
    Viewer(RulesInterface& rules);
    virtual ~Viewer() = default;

    virtual void update() const = 0;
    virtual void run() = 0;

protected:
    RulesInterface& _rules;
};

}
#endif