#ifndef _GRAPHICS_VIEWER_H_
#define _GRAPHICS_VIEWER_H_

#include "viewer/viewer.h"
#include <rules/rules_interface.h>
#include <cstdint>

namespace viewer {

class GraphicsViewer : public Viewer {
public:
    GraphicsViewer(uint8_t pixels_per_cell, RulesInterface& rules);
    virtual ~GraphicsViewer() = default;

    virtual void update() const override;
    virtual void run() override;

private:
    uint8_t _pixels_per_cell;
};

}
#endif