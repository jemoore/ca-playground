#ifndef _RULES_INTERFACE_H_
#define _RULES_INTERFACE_H_

#include <cstdint>
#include <vector>

class RulesInterface {
public:
    explicit RulesInterface(uint16_t rows, uint16_t cols);

    virtual uint16_t number_of_rows() const;
    virtual uint16_t number_of_cols() const;

    virtual bool is_alive(uint16_t row, uint16_t col) const;
    virtual void set_alive(uint16_t row, uint16_t col, bool alive = true);
    virtual void apply_rules() = 0;

    // Call only once at the beginning of the simulation, before applying any rules
    void randomize();

protected:
    uint16_t _rows = 0;
    uint16_t _cols = 0;

    bool _initializing = true;
    std::vector<bool> _board[2];
    size_t _display = 0;
};

#endif