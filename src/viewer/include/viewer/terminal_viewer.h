#ifndef _TERMINAL_VIEWER_H_
#define _TERMINAL_VIEWER_H_

#include "viewer/viewer.h"
#include <rules/rules_interface.h>

namespace viewer {
    class TerminalViewer : public Viewer {
    public:
        TerminalViewer(RulesInterface& rules);
        virtual ~TerminalViewer() = default;

        virtual void update() const override;
        virtual void run() override;
    };
}

#endif