#include "Godot.hpp"
#include "simple.h"
using namespace godot;

void Simple::_init()
{
}

void Simple::_ready()
{
    Godot::print("Simple::_ready()");
}

void Simple::test()
{
    Godot::print("test");
    emit_signal("changed1", "signal from Simple::test()");
}

void Simple::_register_methods()
{
    register_method("test", &Simple::test);
    register_method("_ready", &Simple::_ready);
}
