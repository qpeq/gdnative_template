#pragma once
#include <Node.hpp>

class Simple : public godot::Node {
    GODOT_SUBCLASS(Simple, godot::Node);

public:
    void _init();
    void _ready();
    void test();
    static void _register_methods();
};
